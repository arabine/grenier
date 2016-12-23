; Modèle de procédure ou fonction appelée par le C


; Calcul la surface d'un disque dont l'adresse du rayon (float) est passée en 
; paramètre
; retourne le résultat (float)

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

_CALC	PROC	NEAR

        push    BP
        mov     bp,sp
        push    es
        
        ; pour indexer
        push    di
        push    si

        ; on récupère le rayon
        
        mov     si,[BP+4]
        fld     dword ptr [si] ; float, donc sur 4 octets = dword !! //rayon
        fld     st ;//rayon/rayon
        
        fmulp   st(1),st ;//rayon²
        fldpi   ;//rayon²/pi
        fmulp   st(1),st ;//surface
        
        ; retour de la fonction dans st(0) (float)
        
        pop     si
        pop     di
        pop     es
        pop     bp
        ret

_CALC   ENDP    ; fin procédure

_TEXT    ends
	end
