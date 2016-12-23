;
NAME    ?
;
TITLE   ?
;
;PROCEDURES EXTERNES CONTENUES DANS LA LIBRAIRIE
;
	extrn ci:far,co:far,crlf:far,retour_dos:far,test_input:far
	extrn output_message:far,test_hex:far,print_al:far
	extrn print_ax:far,print_ax_bcd:far,clear_screen:far
;
pile    segment stack 'stack'
	dw 40h dup(?)
	top label word
pile    ends
;
data    segment public 'data'
;       DEFINIR ICI LE SEGMENT DE DONNEES
Mes1		db	'Veuillez entrer un message au clavier se terminant par un dollar',0AH,0DH,'$'
Mes_entre	db	258	dup(?)
Mes2		db	'Nombre de caracteres : $'
Mes_invert	db	258	dup(?)
nb_car		db	1
data	ends
;
code    segment public 'code'
	assume ds:data,ss:pile,cs:code,es:data
;
;INSERER ICI LES SOUS PROGRAMMES
;"PROC"
ENTRER_MESSAGE	PROC	near
	PUSH 	BP

	LEA	Dx,mes1
       	call	output_message

	MOV	BP,SP
	MOV	CX,[BP+4]
	MOV	bx,[BP+6]
	MOV	ds,[BP+8]

	mov	si,0

reb:
	call	CI
	mov	bx[si],al
	inc	si
	cmp	al,'$'	
	loopne	reb

	call	CRLF
	call	CRLF

;	mov	bx[256],'$'

	dec	si
	mov	ax,si
	lea	bx,nb_car
	mov	[bx],ax

	pop	BP
	ret
ENTRER_MESSAGE	endp

INVERT PROC NEAR
	PUSH 	BP

	MOV	BP,SP
	MOV	ax,[BP+4] ; chaine inversée
	MOV	bx,[BP+6]
	MOV	ds,[BP+8]
	
;	mov	si,nb_car

	mov	dx,bx[si]
	


	ret
INVERT	endp


;
;DEBUT DU PROGRAMME PRINCIPAL
;
debut:  mov ax,data
	mov ds,ax
	mov es,ax
	mov ax,pile
	mov ss,ax
	mov sp,offset top
;
;INSERER ICI LE PROGRAMME PRINCIPAL
;
  

	push	ds
	lea	ax, Mes_entre
	push	ax
	mov	ax,256
	push	ax
	call	ENTRER_MESSAGE
	pop	ax
	pop	ax
	pop	ds

        LEA	Dx,Mes_entre
        call	output_message

	call	CRLF
	call	CRLF

	lea	dx,Mes2
        call	output_message
	


	mov	ax,word ptr nb_car
	call	PRINT_AX_BCD

;	call	CRLF
;	call	CRLF

;	push	ds
;        lea	ax, Mes_entre
;	push	ax
;	mov	ax,Mes_invert
;	push	ax
;	call	INVERT
;	pop	ax
;	pop	ax
;	pop	ds


;RETOUR DOS
	mov ah,4ch
	int 21h
code    ends
	end debut
