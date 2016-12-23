; Fonction asm appelée depuis un code source Pascal

NAME zasmp1

DATA    SEGMENT WORD PUBLIC

DATA    ENDS

CODE    SEGMENT BYTE PUBLIC
ASSUME  CS:CODE, DS:DATA

PUBLIC  FONC1

FONC1   PROC    NEAR

        push    bp
        mov     bp,sp
        push    es
        push    di
        push    si

        ; Rayon (single = ieee 32 bits) a été poussé dans st
        ;fld     st(0) ;//rayon/rayon
        fmul    st,st   ;//rayon²
        fldpi   ;//rayon²/rayon/pi
        fmulp   st(2),st  ;//rayon/surface
        mov     si,[BP+10] ; on choppe l'adresse de la variable surface
        fstp    dword ptr [si] ;et on la range(single=32 bits, donc dword)+dépilage : //rayon
        
        ; calcul du périmètre
        fadd    st,st  ;//2*rayon
        fldpi   ;//pi/2*rayon
        fmulp   st(1),st ;//périmètre
        
        mov     si,[BP+6] ; adresse de la variable surface...
        fstp    dword ptr [si] ; on range+dépilage : tout est vide ---> //
        

        pop     si
        pop     di
        pop     es
        pop     bp
        
        ; En pascal, c'est le fonction qui dépile...
        ret     8     ; spécifier le nombre d'octets à dépiler !!

FONC1   ENDP

CODE    ENDS
        END