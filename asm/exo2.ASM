;
NAME    ?
;
TITLE   ?
;
;PROCEDURES EXTERNE CONTENUES DANS LA LIBRAIRIE
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

data    ends
;
code    segment public 'code'
	assume ds:data,ss:pile,cs:code,es:data
;
;INSERER ICI LES SOUS PROGRAMMES
;"PROC"

; BL :  low
; BH : high
Prog54 PROC NEAR
	mov	dx,43H
	mov	al,10110111B
	out	dx,al
	mov	dx,42H
	mov	al,bl
	out	dx,al
	mov	al,bh
	out	dx,al

; on

	mov	dx,61H
	in	al,dx
	or	al,02H
	out	dx,al

	ret
Prog54 endp

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

reb:
	call	TEST_INPUT
	cmp	al,0
	jnz	note
	jmp	reb
note:
	call	ci
	cmp	al,'$'
	jz	exit
	
	cmp	al,'a'
	jz	a
	cmp	al,'z'
	jz	z
	cmp	al,'e'
	jz	e
	cmp	al,'r'
	jz	r
	cmp	al,'t'
	jz	t
	cmp	al,'y'
	jz	y
	cmp	al,'u'
	jz	u
a:
	mov	bx,4551H
	jmp	next
z:
	mov	bx,4056H
	jmp	next

e:
	mov	bx,3613H
	jmp	next

r:
	mov	bx,3407H
	jmp	next

t:
	mov	bx,3042H
	jmp	next


y:
	mov	bx,2710H
	jmp	next

u:
	mov	bx,2414H
	jmp	next

next:
	call	Prog54	
	jmp	reb
exit:
;RETOUR DOS
	mov ah,4ch
	int 21h
code    ends
	end debut
