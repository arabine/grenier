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
Mes1    db 'COUCOU$'
data    ends
;
code    segment public 'code'
	assume ds:data,ss:pile,cs:code,es:data
;
;INSERER ICI LES SOUS PROGRAMMES
;"PROC"
;
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
        LEA Dx,mes1
        call output_message
;RETOUR DOS
	mov ah,4ch
	int 21h
code    ends
	end debut
