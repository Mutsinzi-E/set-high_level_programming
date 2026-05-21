section .data
    msg db "Hello, ALX", 10, 0

section .text
    global main
    extern printf

main:
    mov rdi, msg
    xor eax, eax
    call printf

    mov eax, 0
    ret
