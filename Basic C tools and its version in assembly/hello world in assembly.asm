.intel_syntax noprefix

.section .rdata
message:
    .asciz "Hello, world!"

.text
.globl main
.extern puts

main:
    sub rsp, 40

    lea rcx, [rip + message]
    call puts

    xor eax, eax

    add rsp, 40
    ret