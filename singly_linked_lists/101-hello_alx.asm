global main
	extern printf

	section .text
main:
	; Align stack to 16-byte boundary to perfectly comply with standard C ABI
	push    rbp
	mov     rbp, rsp

	; Load position-relative reference of the string format
	lea     rdi, [rel msg]
	mov     rax, 0         ; 0 floating-point arguments passed
	call    printf         ; Execute call

	; Tear down frame and exit safely back to operating system
	mov     rsp, rbp
	pop     rbp
	mov     rax, 0         ; Return status SUCCESS
	ret

	section .rodata
	align 8
msg:
	db "Hello, ALX", 10, 0
