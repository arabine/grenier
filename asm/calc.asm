; Mod�le de proc�dure ou fonction appel�e par le C


; Calcul la surface d'un disque dont l'adresse du rayon (float) est pass�e en 
; param�tre
; retourne le r�sultat (float)

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

        ; on r�cup�re le rayon
        
        mov     si,[BP+4]
        fld     dword ptr [si] ; float, donc sur 4 octets = dword !! //rayon
        fld     st ;//rayon/rayon
        
        fmulp   st(1),st ;//rayon�
        fldpi   ;//rayon�/pi
        fmulp   st(1),st ;//surface
        
        ; retour de la fonction dans st(0) (float)
        
        pop     si
        pop     di
        pop     es
        pop     bp
        ret

_CALC   ENDP    ; fin proc�dure

_TEXT    ends
	end
