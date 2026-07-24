add:
    mov eax, ecx
    add eax, edx
    ret

main:
    sub rsp, 40

    mov ecx, 5
    mov edx, 3
    call add

    add rsp, 40
    ret