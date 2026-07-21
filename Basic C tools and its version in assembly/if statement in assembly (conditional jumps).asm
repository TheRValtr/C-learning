classify:
    cmp ecx, 10
    jle not_greater

    mov eax, 1
    ret

not_greater:
    xor eax, eax
    ret