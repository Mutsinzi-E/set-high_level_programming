section .data
    msg db "Hello, Holberton", 10, 0

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

section .note.GNU-stack noalloc noexec nowrite progbits
