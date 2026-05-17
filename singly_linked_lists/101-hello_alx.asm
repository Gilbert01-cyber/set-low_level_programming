global main
	extern printf

	section .text
main:
	; Set up complete stack frame to preserve call stack trace
	push    rbp
	mov     rbp, rsp

	; Safe string reference loading via relative addressing
	lea     rdi, [rel msg] ; Load exact relative address of message
	mov     rax, 0         ; 0 floating-point arguments passed
	call    printf         ; Call standard C library function

	; Tear down stack frame cleanly and exit
	mov     rsp, rbp
	pop     rbp
	mov     rax, 0         ; Return 0 to indicate SUCCESS
	ret

	section .data
msg:
	db "Hello,ALX", 10, 0  ; Notice: NO SPACE after the comma
