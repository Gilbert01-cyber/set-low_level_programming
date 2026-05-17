global main
	extern printf

	section .text
main:
	; Align stack to 16-byte boundary to fully stabilize standard C library calls
	push    rbp
	mov     rbp, rsp

	; Load argument pointers for printf
	mov     rdi, msg       ; 1st parameter: address of message string
	mov     rax, 0         ; 0 floating-point/vector registers used
	call    printf         ; Invoke printf

	; Clean exit back to the calling process environment
	mov     rsp, rbp
	pop     rbp
	mov     rax, 0         ; Return status code 0 (SUCCESS)
	ret

	section .data
msg:
	db "Hello, ALX", 10, 0 ; Clean string bytes followed by LF (10) and NULL (0)
