; Fonction asm appel�e depuis un code source Pascal

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

        ; Rayon (single = ieee 32 bits) a �t� pouss� dans st
        ;fld     st(0) ;//rayon/rayon
        fmul    st,st   ;//rayon�
        fldpi   ;//rayon�/rayon/pi
        fmulp   st(2),st  ;//rayon/surface
        mov     si,[BP+10] ; on choppe l'adresse de la variable surface
        fstp    dword ptr [si] ;et on la range(single=32 bits, donc dword)+d�pilage : //rayon
        
        ; calcul du p�rim�tre
        fadd    st,st  ;//2*rayon
        fldpi   ;//pi/2*rayon
        fmulp   st(1),st ;//p�rim�tre
        
        mov     si,[BP+6] ; adresse de la variable surface...
        fstp    dword ptr [si] ; on range+d�pilage : tout est vide ---> //
        

        pop     si
        pop     di
        pop     es
        pop     bp
        
        ; En pascal, c'est le fonction qui d�pile...
        ret     8     ; sp�cifier le nombre d'octets � d�piler !!

FONC1   ENDP

CODE    ENDS
        END