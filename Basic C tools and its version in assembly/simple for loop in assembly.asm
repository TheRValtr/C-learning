main:
    sub     rsp, 40

    mov     DWORD PTR [rsp+36], 0

loop_check:
    cmp     DWORD PTR [rsp+36], 5
    jge     loop_end

    mov     edx, DWORD PTR [rsp+36]
    lea     rcx, format_string
    call    printf

    add     DWORD PTR [rsp+36], 1
    jmp     loop_check

loop_end:
    xor     eax, eax
    add     rsp, 40
    ret

format_string:
    db "%d", 10, 0