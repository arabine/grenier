; Modèle de procédure ou fonction appelée par le C


; Fait appel à une fonction C externe pour calculer la surface

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
        ; on passe en paramètre et on appel la fonction
        call    _MULTI
        
        pop     cx      ; on dépile 4 octets...
        pop     cx
        
        ; le résultat de _MULTI est dans  st(0), on laisse et on sort...
        
        pop     si
        pop     di
        pop     es
        pop     bp
        ret

_CALC   ENDP    ; fin procédure

_TEXT    ends
	end
