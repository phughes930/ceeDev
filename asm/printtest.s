	.file	"printtest.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0
	.string	"Hello!"
	.text
	.globl	printtest
	.type	printtest, @function
printtest:
	pushl	%ebx								; save ebx
	subl	$20, %esp							; subtract 20 from esp
	call	__x86.get_pc_thunk.bx				; load esp address to ebx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx		; add global offset table to ebx
	leal	.LC0@GOTOFF(%ebx), %eax				; load string to eax
	pushl	%eax								; push eax to stack
	call	printf@PLT							; call print
	movl	$0, %eax							; load 0 to eax
	addl	$24, %esp							; fix esp
	popl	%ebx								; fix ebpl
	ret
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
	movl	(%esp), %ebx
	ret
	.ident	"GCC: (Debian 12.2.0-14+deb12u1) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
