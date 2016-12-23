   NAME  CLEAR_SCREEN
   title Effacement de l ecran
;
	public clear_screen
;
 CODE    SEGMENT PUBLIC 'CODE'
;
 ASSUME  CS:CODE
;
clear_screen    proc far
		push ax
		push bx
		push cx
		push dx
		xor al,al      ;Efface fenetre entiere
		xor cx,cx      ;Coin haut gauche =(0,0)
		mov dh,24      ;Derniere ligne =24
		mov dl,79      ;Cote droit =colonne 79
		mov bh,7       ;Attribut normal
		mov ah,6       ;Fonction scroll-up
		int 10h        ;Efface fenetre
		mov bh,0       ;Affiche la page zero
		xor dx,dx      ;Curseur coin haut gauche =(0,0)
		mov ah,2       ;Fonction deplacement du curseur
		int 10h
		pop dx
		pop cx
		pop bx
		pop ax
		ret
 clear_screen   endp
;
 CODE ENDS
      END       
