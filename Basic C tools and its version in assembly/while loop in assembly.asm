countdown:
    xor eax, eax

while_check:
    cmp ecx, 0
    jle while_end

    dec ecx
    inc eax

    jmp while_check

while_end:
    ret