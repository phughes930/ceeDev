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