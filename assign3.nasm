;Assignment 3 Write an assembly language program to convert from HEXADECIMAL to BCD
;Aditya Gade 	SEA18	18/1/20

global _start

_start:

section .text
	;Print Macro
		%macro print 2
		mov rax,1
		mov rdi,1
		mov rsi,%1
		mov rdx,%2
		syscall
		%endmacro
	;Accepting a Choice
		%macro accept 2
		mov rax,0
		mov rdi,0
		mov rsi,%1
		mov rdx,%2
		syscall
		%endmacro
	print msg1,length1
	
	accept inputNo,2
	call convert
	mov [no1],al
	
	accept inputNo,3
	call convert
	mov [no2],al
	
	print msg2,length2
	print no1,2
	print no2,2
	
	convert:
		mov rsi,inputNo
		mov al,[rsi]
		cmp al,39H
		jbe l1
		sub al,7H
		l1:	sub al,30H
		;Rotate 4 times to swap a 2 digit number 
		rol al,4	;rotateLeft which,howMuch
		mov bl,al
		inc rsi
		mov al,[rsi]
		cmp al,39H
		jbe l2
		sub al,7H
		l2: sub al,30H
		add al,bl
		ret
section .data
	msg1 db "Input a Hexadecimal number",10
	length1 equ $ -msg1
	msg2 db "Output number obtained is",10
	length2 equ $ -msg2
section .bss
	inputNo resb 05
	no1 	resb 02
	no2		resb 02
