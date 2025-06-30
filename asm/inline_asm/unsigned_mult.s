	.file	"mult.c"
	.text
	.globl	umult_ok_asm
	.type	umult_ok_asm, @function
umult_ok_asm:
.LFB0:
	.cfi_startproc
	movl	8(%esp), %eax
	mull    4(%esp)
	movl	12(%esp), %edx
	movl	%eax, (%edx)
	; testl	%eax, %eax
	; setne	%al
    setae   %al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	umult_ok_asm, .-umult_ok_asm
	.ident	"GCC: (Debian 12.2.0-14+deb12u1) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
