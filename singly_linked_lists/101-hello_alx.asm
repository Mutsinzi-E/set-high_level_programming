section .data
    msg db "Hello, ALX", 10, 0

section .text
    global main
    extern printf

main:
    push rbp

    mov rdi, msg
    xor rax, rax
    call printf

    mov eax, 0
    pop rbp
    ret
