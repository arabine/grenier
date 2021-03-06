; Mod�le de proc�dure ou fonction appel�e par le C


; Fait appel � une fonction C externe pour calculer la surface

_DATA   SEGMENT WORD PUBLIC 'DATA'

result  dd      ?
quatre  dw      4
trois   dw      3

_DATA	ends

_BSS    SEGMENT WORD PUBLIC 'BSS'


_BSS    ends

DGROUP  group _BSS, _DATA

_TEXT   SEGMENT BYTE PUBLIC 'CODE'

ASSUME  CS:_TEXT, DS:DGROUP

PUBLIC  _CALC
EXTRN   _MULTI:NEAR

_CALC	PROC	NEAR

        push    BP
        mov     bp,sp
        push    es
        
        ; pour indexer
        push    di
        push    si

        
        push    dword ptr [BP+4] ; on met dans la pile le rayon
        ; on passe en param�tre et on appel la fonction
        call    _MULTI
        
        pop     cx      ; on d�pile 4 octets...
        pop     cx
        
        ; le r�sultat de _MULTI est dans  st(0), on laisse et on sort...
        
        pop     si
        pop     di
        pop     es
        pop     bp
        ret

_CALC   ENDP    ; fin proc�dure

_TEXT    ends
	end
