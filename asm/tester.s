    .text
    .section    .rodata.str1.1,"aMS",@progbits,1
string:
    .string "Hello world!"
    .text
    .globl  main
    .type   main, @function
main:
    pushl %ebx
    popl %ebx
    addl $VAROFF, 
    movl $4, %eax
    movl $1, %ebx
    movl $12, %edx
    int $0x80
    popl %ebx
    ret
    .section    .note.GNU-stack,"",@progbits
