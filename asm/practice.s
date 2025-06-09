; a at %ebp+8, b at %ebp+12
movl 8(%ebp), %ecx			; get a
movl 12(%ebp), %ebx			; get b
movl $1, %eax				; set result to 1
cmpl %ebx, %ecx				; compare a:b
jge .L11					; jump to done if a >= b
leal (%ebx,%ecx), %edx		; set a + b
movl $1, %eax				; set result to 1 (again?)
.L12:
	imull %edx, %eax		; a = a*b
	addl $1, %ecx			; a++
	addl $1, %edx			; (a + b)++
	cmpl %ecx, %ebx			; compare a:b
	jg .L12					; if a < b, rerun loop
.L11:

; register	value
; ------------------
; %eax		result
; %ebx		b
; %ecx		a
; %edx		a + b

fun_a:
	; x at %ebp+8
	movl 8(%ebp), %edx		; get x
	movl $0, %eax			; set val = 0
	testl %edx, %edx		; test x & x
	je .L7					; if x & x == 1 jump to L7
	.L10:
		xorl %edx, %eax		; val = x ^ val;
		shrl %edx 			; shift x right by 1 CF = last bit, OF = 0
		jne .L10			; if x bit is not 0, repeat
	.L7:
		andl $1, %eax		; val = 1 & val

; funb 

fun_b:								; x at %ebp+8
	movl 8(%ebp), %ebx				; get x
	movl $0, %eax					; set val = 0
	movl $0, %ecx					; set i = 0
	.L13:
		leal (%eax,%eax), %edx		; %edx = 2val
		movl %ebx, %eax				; val = x
		andl $1, %eax				; val &= 1
		orl %edx, %eax				; val |= 2val;
		shrl %ebx 					; shift x right by 1
		addl $1, %ecx				; increment i
		cmpl $32, %ecx				; compare i:32
		jne .L13					; if i < 32, reloop
	

; practice 3.26
; register: x in %edx
arith:
	leal 	3(%edx), %eax			; eax = x + 3
	testl 	%edx, %edx				; test x for pos/neg
	cmovns 	%edx, %eax				; if x is positive. set %eax = x
	sarl	$2, %eax				; divide %eax by 4
; OP is /


; practice 3.27
; x at %ebp+8, y at %ebp+12
test:
	movl	8(%ebp), ebx			; set %ebx = x
	movl	12(%ebp), ecx			; set %ecx = y

	testl	%ecx, %ecx				; test y
	jle		.L2						; if y <= 0, jump to L2
	movl	%ebx, %edx				; move x to %edx
	subl	%ecx, %edx				; %edx = x - y
	movl	%ecx, %eax				; move y to %eax
	xorl	%ebx, %eax				; %eax = x ^ y (CF & OF = 0)
	cmpl	%ecx, %ebx				; compare x:y (x - y)
	cmovl	%edx, %eax				; if x - y < 0, move x - y to eax
	jmp		.L4						; done
.L2:
	leal	0(,%ebx,4), %edx		; set %edx = 4x
	leal	(%ecx, %ebx), %eax		; set %eax = x + y
	cmpl	$-2, %ecx				; compare y:-2 (y - 2)
	cmovge	%edx, %eax				; if y >= -2, move 4x to %eax
.L4:

; practice 3.29
; a at %ebp+8, b at %ebp+12, c at %ebp+16
	.section	.rodata
	.align		4
.L7
	.long	.L3
	.long	.L2
	.long	.L4
	.long	.L2
	.long	.L5
	.long	.L6
	.long	.L2
	.long	.L4

switcher:
	movl	8(%ebp), %eax 	; get a
	cmpl	$7, %eax		; compare a:7
	ja		.L2				; if a > 7: default
	jmp		*.L7(,%eax,4)	; otw switch a
.L2							; default
	movl 	12(%ebp), %eax	; answer = b
	jmp		.L8				; break
.L5							; a = 4
	movl	$4, %eax		; answer = 4
	jmp		.L8				; break
.L6							; a = 5
	movl	12(%ebp), %eax	; answer = b
	xorl	%15, %eax		; answer = b ^ 15
	movl	%eax, 16(%ebp)	; c = b ^ 15
.L3							; a = 0
	movl	16(%ebp), %eax 	; answer = c
	addl	$112, %eax		; answer = c + 112
	jmp		.L8				; break;
.L4							; a = 2, 7
	movl	16(%ebp), %eax	; answer = c
	addl	12(%ebp), %eax	; answer = c + b
	sall	$2, %eax		; answer = (c + b) * 4
.L4