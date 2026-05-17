global main
	extern printf

	section .text
main:
	; Set up stack frame configuration
	push    rbp
	mov     rbp, rsp

	; Load position-relative address of the exact string format
	lea     rdi, [rel msg]
	mov     rax, 0         ; 0 floating-point/vector registers
	call    printf         ; Execute the C library call

	; Clean stack frame breakdown
	mov     rsp, rbp
	pop     rbp
	mov     rax, 0         ; Return SUCCESS status 0
	ret

	section .rodata
msg:
	db "Hello, ALX", 10, 0
