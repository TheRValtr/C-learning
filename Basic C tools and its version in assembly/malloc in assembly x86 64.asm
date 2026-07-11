; malloc(16)
mov     ecx, 16
call    malloc

; Check returned pointer
test    rax, rax
je      malloc_failed

; Save the pointer
mov     rbx, rax

; numbers[0] = 10
mov     DWORD PTR [rbx], 10

; numbers[1] = 20
mov     DWORD PTR [rbx + 4], 20

; free(numbers)
mov     rcx, rbx
call    free

; return 0
xor     eax, eax
ret

malloc_failed:
mov     eax, 1
ret