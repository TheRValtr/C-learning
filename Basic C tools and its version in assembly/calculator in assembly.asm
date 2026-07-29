; calculator.asm
; x86-64 Linux, NASM syntax
;
; Equivalent to the C calculator:
;   float num1, num2;
;   char operator;
;
; Supports:
;   +  -  *  /

default rel

global main

extern printf
extern scanf

section .data

    title:
        db "=== Basic Calculator ===", 10, 0

    prompt_first:
        db "Enter first number: ", 0

    prompt_operator:
        db "Enter operator (+, -, *, /): ", 0

    prompt_second:
        db "Enter second number: ", 0

    format_float_input:
        db "%f", 0

    format_char_input:
        db " %c", 0

    format_result:
        db "Result: %.2f", 10, 0

    division_zero_message:
        db "Error: Division by zero!", 10, 0

    invalid_operator_message:
        db "Invalid operator!", 10, 0


section .bss

    num1:
        resd 1              ; reserve 4 bytes for one float

    num2:
        resd 1              ; reserve 4 bytes for one float

    operator:
        resb 1              ; reserve 1 byte for one character


section .text

main:

    ; Standard function setup
    push rbp
    mov rbp, rsp

    ; ---------------------------------------------------------
    ; printf("=== Basic Calculator ===\n");
    ; ---------------------------------------------------------

    lea rdi, [title]
    xor eax, eax
    call printf

    ; ---------------------------------------------------------
    ; printf("Enter first number: ");
    ; ---------------------------------------------------------

    lea rdi, [prompt_first]
    xor eax, eax
    call printf

    ; ---------------------------------------------------------
    ; scanf("%f", &num1);
    ; ---------------------------------------------------------

    lea rdi, [format_float_input]
    lea rsi, [num1]
    xor eax, eax
    call scanf

    ; ---------------------------------------------------------
    ; printf("Enter operator (+, -, *, /): ");
    ; ---------------------------------------------------------

    lea rdi, [prompt_operator]
    xor eax, eax
    call printf

    ; ---------------------------------------------------------
    ; scanf(" %c", &operator);
    ; ---------------------------------------------------------

    lea rdi, [format_char_input]
    lea rsi, [operator]
    xor eax, eax
    call scanf

    ; ---------------------------------------------------------
    ; printf("Enter second number: ");
    ; ---------------------------------------------------------

    lea rdi, [prompt_second]
    xor eax, eax
    call printf

    ; ---------------------------------------------------------
    ; scanf("%f", &num2);
    ; ---------------------------------------------------------

    lea rdi, [format_float_input]
    lea rsi, [num2]
    xor eax, eax
    call scanf

    ; ---------------------------------------------------------
    ; Decide which operation was requested
    ; ---------------------------------------------------------

    mov al, byte [operator]

    cmp al, '+'
    je addition

    cmp al, '-'
    je subtraction

    cmp al, '*'
    je multiplication

    cmp al, '/'
    je division

    jmp invalid_operator


addition:

    ; xmm0 = num1
    movss xmm0, dword [num1]

    ; xmm0 = xmm0 + num2
    addss xmm0, dword [num2]

    jmp print_result


subtraction:

    movss xmm0, dword [num1]

    ; xmm0 = xmm0 - num2
    subss xmm0, dword [num2]

    jmp print_result


multiplication:

    movss xmm0, dword [num1]

    ; xmm0 = xmm0 * num2
    mulss xmm0, dword [num2]

    jmp print_result


division:

    ; Load num2 so we can check whether it is zero
    movss xmm1, dword [num2]

    ; Set xmm2 to floating-point zero
    xorps xmm2, xmm2

    ; Compare num2 with 0.0
    ucomiss xmm1, xmm2

    je division_by_zero

    ; xmm0 = num1
    movss xmm0, dword [num1]

    ; xmm0 = num1 / num2
    divss xmm0, xmm1

    jmp print_result


print_result:

    ; The calculator stores the result as a 32-bit float.
    ;
    ; printf("%f") expects a 64-bit double because variadic
    ; function arguments promote float to double.

    cvtss2sd xmm0, xmm0

    lea rdi, [format_result]

    ; One floating-point argument is being passed to printf.
    mov eax, 1

    call printf

    jmp program_end


division_by_zero:

    lea rdi, [division_zero_message]
    xor eax, eax
    call printf

    jmp program_end


invalid_operator:

    lea rdi, [invalid_operator_message]
    xor eax, eax
    call printf


program_end:

    ; return 0;

    xor eax, eax

    ; Restore the previous stack frame
    mov rsp, rbp
    pop rbp

    ret