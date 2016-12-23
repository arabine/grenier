                page,132
Title  conversion binaire_bcd  de l'accu et impression
;
name  imp_ac_bcd
;
                PUBLIC    PRINT_AX_BCD
                EXTRN     PRINT_AX:FAR
                EXTRN     PRINT_AL:FAR
;
data		segment
;
;accumulateur binaire
;
BINAIRE         DB       2 DUP (?)
;
;accumulateur bcd
;
BCD             DB       3 DUP (?)
data		ends
pile		segment stack 'stack'
		dw 	 20 dup (?)
pile            ends
;
;
cseg	segment
	assume cs:cseg, ds:data, ss:pile, es:data
;
bin_bcd       proc        NEAR
	;
        push	ax
        push    bx
        push    cx
        push    si
        push    di
	;initiallisation de l'accumulateur BCD … z‚ro
	;
        cld
	lea	di, BCD
	mov	cx, length bcd
	xor	al,al
rep	stosb
	;initialisation du compteur de bits
        ;
	mov	cx,16
cloop:
	xchg	cx,bx
	lea	si, binaire
	mov	cx, length binaire
	clc
	;
	;d‚calage du nombre binaire de
        ;1 bit vers la gauche
rloop:
        rcl    	byte ptr [si],1
	inc	si
	loop	rloop
	;
	;initialisation pour doubler
	;le r‚sultat BCD
	;
	lea	di, BCD
	mov	cx, length BCD
	;
	; doublement du r‚sultat BCD
	;
bloop:
	mov	al,[di]
	adc	al,[di]
	daa
	mov	[di],al
	inc	di
	loop	bloop
        ;
	;d‚calage de tous les bits
	;
	xchg	cx,bx
	loop	cloop
	;
        pop	di
	pop     si
	pop	cx
	pop	bx
	pop     ax
;
	ret
;
bin_bcd      endp
;
PRINT_AX_BCD 	proc	far
                push    ds
		push    es
                push    ax
                mov     ax,data
                mov     ds,ax
                mov     es,ax
                pop     ax
                push    ax
                mov     word ptr binaire,ax
                call    bin_bcd
                mov     ax,word ptr bcd+1
                call    print_ax
                mov     al,byte ptr bcd
                call    print_al
                pop     ax
                pop     es
                pop     ds
                ret
PRINT_AX_BCD    endp
cseg    ends
	end
