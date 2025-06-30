	.file	"mult.c"
	.text
	.globl	tmult_ok_asm
	.type	tmult_ok_asm, @function
tmult_ok_asm:
.LFB0:
	.cfi_startproc
	movl	8(%esp), %eax       ; get y
	imull	4(%esp), %eax       ; multiply x by y
	movl	12(%esp), %edx      ; get *dest
	movl	%eax, (%edx)        ; store p @ dest
	; testl	%eax, %eax          ; rem: test for neg
	; setg	%al                 ; set low byte of eax
    setae   %al                 ; set to ~CF
	movzbl	%al, %eax           ; zero-extend to eax
	ret                         ; return
	.cfi_endproc
.LFE0:
	.size	tmult_ok_asm, .-tmult_ok_asm
	.ident	"GCC: (Debian 12.2.0-14+deb12u1) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
