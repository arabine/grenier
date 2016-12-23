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
Mess		db	'Repondez par o ou n (dollar pour quitter)$'
oui             db      'Vous avez appuye sur o$'
non             db      'Vous avez appuye sur n$'
mauvais         db      'mauvaise reponse$'

data	ends
;
code    segment public 'code'
	assume ds:data,ss:pile,cs:code,es:data
;
;INSERER ICI LES SOUS PROGRAMMES
;"PROC"


;
;DEBUT DU PROGRAMME PRINCIPAL
;
debut:
        mov ax,data
	mov ds,ax
	mov es,ax
	mov ax,pile
	mov ss,ax
	mov sp,offset top
;
;INSERER ICI LE PROGRAMME PRINCIPAL
;
	push	ds

        lea	dx,Mess
        call	output_message

	call	CRLF
reb:
        call	CRLF
        call    CI
        cmp	al,'$'	
	je	liberty
        cmp     al,'o'
        je      touch_o
        cmp     al,'n'
        je      touch_n
        
        ; mauvaise réponse
        lea     dx,mauvais
        call	output_message
        jmp     reb
touch_o:
        lea     dx,oui
        call	output_message
        jmp     reb

touch_n:
        lea     dx,non
        call	output_message
        jmp     reb

liberty:

;RETOUR DOS
	mov ah,4ch
	int 21h
code    ends
	end debut
