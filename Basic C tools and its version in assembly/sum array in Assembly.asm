sumArray:
    xor     eax, eax
    xor     r8d, r8d

loop_check:
    cmp     r8d, edx
    jge     loop_end

    add     eax, DWORD PTR [rcx + r8*4]

    inc     r8d
    jmp     loop_check

loop_end:
    ret