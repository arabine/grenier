*  Gestion d'un afficheur LCD (LM 16155)
*  port D    5    4    3    2    1    0
*  LCD       E   R/W   RS
*
*  port B  0  1   2   3   4   5   6   7
*  LCD     0  1   2   3   4   5   6   7
*
*

        ldx   #$1000
        bset  DDRD,x $38
* INITIialisation de l'afficheur
INITI    ldaa  #%00111000      ;2lignes;8bits;matrice 5x10
        jsr   LCDI
        ldaa  #%00001110      ;afficheur:on ; curseur:on et ne clignote pas
        jsr   LCDI
        ldaa  #%00000110      ;direction du curseur
        jsr   LCDI
        ldaa  #%00000001      ;adresse de la premiŠre (moiti‚) ligne
        jsr   LCDI
* Envoi d'un message … afficher
        ldy   #MESSAGE
        ldab  #$9
ENVOI1  ldaa  00,y
        decb
        bne   L1
        bra   L2
L1      jsr   LCDCH           ;premiŠre (moiti‚ de) ligne
        iny
        bra   ENVOI1
L2      ldaa  #%11000000      ;adresse de la deuxiŠme (moiti‚ de) ligne
        jsr   LCDI
        ldab  #$9
ENVOI2  decb
        bne   LL2             
        bra   FIN
LL2     ldaa  00,y            ;deuxiŠme (moiti‚ de) ligne
        jsr   LCDCH
        iny
        bra   ENVOI2
FIN     bra   FIN 
* sous programme d'envoi d'instructions 
LCDI    pshy
        bclr  PORTD,x %010000    ; RW=0 ->‚criture dans LCD
        bclr  PORTD,x %001000    ; RS=0 ->instruction
        staa  PORTB,x
        bset  PORTD,x %100000    ; E=1 ->valide LCD         
        ldy   #$0200
        jsr   DELAI
        bclr  PORTD,x %100000    ; E=0 ->invalide LCD
        ldy   #%0200
        jsr   DELAI
        puly
        rts
* sous programme d'envoi de caractŠres
LCDCH   pshy
        bclr  PORTD,x %010000    ; RW=0 ->‚criture dans LCD
        bset  PORTD,x %001000    ; RS=1 ->instruction
        staa  PORTB,x
        bset  PORTD,x %100000    ; E=1 ->valide LCD         
        ldy   #%0200
        jsr   DELAI
        bclr  PORTD,x %100000    ; E=0 ->invalide LCD
        ldy   #%0200
        jsr   DELAI
        puly
        rts
* sous programme de delai pour laisser du temps … l'afficheur
DELAI   dey
        bne   DELAI
        rts
* Message … envoyer
*              w   w   w   .   e   p   r   a   t   .   c   o   m  
MESSAGE fcb   $77,$77,$77,$2E,$65,$70,$72,$61,$74,$2E,$63,$6F,$6D,$20,$20,$20
*
*
*       CODES AFFICHEUR :
*
* de $30 … $39 : chiffres 0 … 9
* de $3A … $3F : symboles : ; < = > ?
* de $41 … $5A : lettres A … Z
* de $61 … $7A : lettres a … z
* d'autres symboles existent (entre $00 et $FF)
*
*
