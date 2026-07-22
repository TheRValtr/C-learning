compare:
    cmp ecx, edx
    jg greater
    jl less

    xor eax, eax
    ret

greater:
    mov eax, 1
    ret

less:
    mov eax, -1
    ret