mov ecx,1

loop:

cmp ecx,5
jg end

; printf()

inc ecx

jmp loop

end: