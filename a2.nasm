;Assignment 2 Write an assembly language program to perform non-overlap instructions 
;Aditya Gade 	SEA18	15/1/20

global _start

_start:

section .text
	;Print Macro
	%macro print 2
	    mov rax,1
	    mov rdi,1
	    mov rsi,%1
	    ;rsi requires HEX values
	    mov rdx,%2
	    syscall
	%endmacro
	;Accepting a choice
	%macro accept 2
		mov rax,0
		mov rdi,0
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro
	
	backToMenu:
		print menu1,menuLength
		accept choice1,2
		mov al,byte[choice1]
		
	cmp al,31H
	je ch1
	cmp al,32H
	je ch2
	cmp al,33H
	je ch3
	
	
	ch1:
		mov rsi,oarr
		mov rdi,oarr
		add rsi,9;OFFSET from
		add rdi,13;OFFSET to
		;WITHOUT STRING
		;Copying Operation
		l1:
			mov al,[rsi]
			mov [rdi],al
			dec rsi
			dec rdi
			dec byte [cnt1]
			jnz l1
		;displaying oarr
		mov rsi,oarr
		l2:
			mov al,[rsi]
			push rsi
			call displayByte
			pop rsi
			inc rsi
			dec byte[cnt2]
			jnz l2
		jmp backToMenu
	ch2:
		mov rsi,oarr1
		mov rdi,oarr1
		add rsi,9;OFFSET from
		add rdi,13;OFFSET to
		;WITH STRING
		std 
		mov rcx,10
		rep movsb
		;displaying oarr1
		mov rsi,oarr1
		l3:
			mov al,[rsi]
			push rsi
			call displayByte
			pop rsi
			inc rsi
			dec byte[cnt3]
			jnz l3
		jmp backToMenu
	ch3:
		;Exit	
		mov rax,60
		mov rdi,0
		syscall
	
	;Display Procedure for 2 digit Definition
	displayByte:
    ;point to 16th position in an empty array
    mov rsi,disparr+1
    ;		,base+offset
    
    ;declare count as 2
    mov rcx,2
    
    ;we divide the number in a loop(L2 is a loop label) to separate digits
     Label2:
     	mov rdx,0
    	mov rbx,10H
    	div rbx
    	;div divisor    ..it automatically takes in rdx:rax pair as dividend
    	;returns quotient-rax	 and	 remainder-dl
    	cmp dl,09H
    	;conditional j-jump b-below e-equal jump to label l1
    	jbe Label1
    	;if jump value isnt satisfied then all statements are executed below
    	add dl,07H
    	Label1:add dl,30H
    	;putting the number in dl into array
    	mov [rsi],dl
    	dec rsi
    	dec rcx
    	;rsi-array index rcx-counter var
    	jnz Label2
    	;j-jump nz-not zero
		;Print Macro Call
		print disparr,2
		print space,spaceLength
		ret

section .data
	;Overlap
	oarr db 01H,02H,03H,04H,05H,06H,07H,08H,09H,0AH,0BH,0CH,0DH,0EH,0FH	;both rsi and rdi
	cnt1 db 10; no of elements to copy 
	cnt2 db 15; array size
	space db " ",10
	spaceLength equ	$- space
	menu1 db "1.Overlap without string instruction",10
		db "2.Overlap with string instructions",10
		db "3.Exit",10
		db "Please enter your choice : "
	menuLength  equ $- menu1
	oarr1 db 01H,02H,03H,04H,05H,06H,07H,08H,09H,0AH,0BH,0CH,0DH,0EH,0FH	;both rsi and rdi
	cnt3 db 15; array oarr1 size
section .bss
;undefined so declared in .bss
disparr resb 34
choice1 resb 02
