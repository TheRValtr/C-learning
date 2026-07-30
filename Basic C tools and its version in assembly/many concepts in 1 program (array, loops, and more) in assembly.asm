sumArray:
    xor eax,eax
    xor r8d,r8d

loop:
    cmp r8d,edx
    jge done

    add eax,DWORD PTR [rcx+r8*4]
    inc r8d
    jmp loop

done:
    ret

increase:
    inc DWORD PTR [rcx]
    ret

main:

    sub rsp,40

    lea rcx,numbers
    mov edx,4
    call sumArray

    mov [rsp+32],eax

    cmp DWORD PTR [rsp+32],50
    jle skip

    lea rcx,[rsp+32]
    call increase

skip:

    lea rcx,format
    mov edx,[rsp+32]
    call printf

    xor eax,eax

    add rsp,40

    ret