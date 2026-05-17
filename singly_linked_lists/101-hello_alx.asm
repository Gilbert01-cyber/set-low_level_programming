global main
	extern printf

	section .text
main:
	; Align stack to 16-byte boundary and preserve call framework
	push    rbp
	mov     rbp, rsp

	; Set up parameters for printf call
	mov     rdi, msg       ; 1st argument: address of the string
	mov     rax, 0         ; 0 floating-point/vector arguments
	call    printf         ; Transfer control to C library printf

	; Restore stack frames and exit cleanly back to OS environment
	mov     rsp, rbp
	pop     rbp
	mov     rax, 0         ; Return SUCCESS code 0
	ret

	section .rodata
msg:
	db "Hello, ALX", 10, 0 ; 10 is line feed (\n), 0 is null terminator (\0)
