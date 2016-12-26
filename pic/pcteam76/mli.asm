 	; on utilise les librairies du 16F84A
    LIST  P=16F84A
    include	<p16f84a.inc>

    ; Directives pour le programmateur (oscillateur rapide)
    __CONFIG   _CP_OFF & _PWRTE_ON & _WDT_OFF & _HS_OSC

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Configuration du Hard
; 4 bits poids faible du port B reli�s au 
; PIC num�ro 1 : le cerveau
; TABLE DE VERITE :
;
;  PA3   |   PA2    |   PA1    |   PA0    | Vitesse
; ------ | -------- | -------- | -------- | --------
;  0     |    0     |   0      |   0      | Arr�t robot  <---- la seule config qui arr�te le robot : TOUS les bits � 0
;  0     |    0     |   0      |   1      | Vitesse 25% avant
;  0     |    0     |   1      |   0      | Vitesse 50% avant
;  0     |    0     |   1      |   1      | Vitesse 75% avant
;  0     |    1     |   0      |   0      | 
;  0     |    1     |   0      |   1      | 
;  0     |    1     |   1      |   0      | Vitesse 50% moteur gauche off, moteur droit on (rotation)
;  0     |    1     |   1      |   1      | Vitesse 100% avant
;  1     |    0     |   0      |   0      | 
;  1     |    0     |   0      |   1      | Vitesse 25% arri�re
;  1     |    0     |   1      |   0      | Vitesse 50% arri�re
;  1     |    0     |   1      |   1      | Vitesse 75% arri�re
;  1     |    1     |   0      |   0      | 
;  1     |    1     |   0      |   1      | 
;  1     |    1     |   1      |   0      | Vitesse 50% moteur gauche on, moteur droit off (rotation)
;  1     |    1     |   1      |   1      | Vitesse 100% arri�re
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;
; DEFINES
;;;;;;;;;;;;

; Broches en sortie

SENS_D  EQU     0x04 ; Sens moteur droit RB4
SENS_G  EQU     0x05 ; Sens moteur gauche RB5
PWM_D   EQU     0x06 ; PWM moteur droit RB6
PWM_G   EQU     0x07 ; PWM moteur gauche RB7

;;;;;;;;;;;;;;;;;;;;;;;;;;
; VARIABLES EN RAM
; LA RAM COMMENCE EN 0x0C
;;;;;;;;;;;;;;;;;;;;;;;;;;
CBLOCK 0x20

    Image:1 ; l'octet image des broches du port B

; m�morisation des ordres pour chaque moteur
;         6   5   4   3   2   1   0
; MOT_X   -   -  100  75  50  25  SENS
;
; SENS=1 : avant , SENS=0 : arri�re
    Ordre:1 ; L'octet image du port A en provenance du PIC cerveau
    VAR:1
    MOT_G:1
    MOT_D:1
ENDC    ; Fin de la RAM 

;;;;;;;;;;;;;;;;;;;;;;
; PROGRAMME PRINCIPAL
;;;;;;;;;;;;;;;;;;;;;;

	org	0000h		 
	goto	START
    org	05h

START:
    call INIT
    
    ; Apr�s l'init, on va chercher les ordres sur le port A
    goto LOOP

REB:

; d�but de la MLI
;
; On fait perdre du temps au micro.
; Calcul : 15khz -> 70 us -> 350 cycles -> la MLI est divis�e par 4, soit 17,5 us par quart de cycle
; la routine de test de MLI fait 2us, il faut donc faire une perte de temps de 15,5us :

; Delay de 15,5us
    movlw   d'25'
    movwf   VAR
Boucle1:
    decfsz  VAR,1
    goto    Boucle1    


; on teste si on remet la MLI � 0 � 25%...
; La routine suivante dure 2 us
    btfsc   MOT_G,0x01   ; MLI Moteur gauche = 25% ?
    goto    Oui_G_25
    goto    Next_25
Oui_G_25:   bcf     Image,PWM_G      ; oui
Next_25:   btfsc   MOT_D,0x01   ; MLI Moteur droit = 25% ?
    goto    Oui_D_25
    goto MLI_25
Oui_D_25:   bcf     Image,PWM_D      ; oui

MLI_25:
; MLI = 25% : On envoie l'image des broches sur le portb
    movf   Image,0
    movwf   PORTB

; Delay de 15,5us
    movlw   d'25'
    movwf   VAR
Boucle2:
    decfsz  VAR,1
    goto    Boucle2


; on teste si on remet la MLI � 0 � 50%...
    btfsc   MOT_G,0x02   ; MLI Moteur gauche = 50% ?
    goto    Oui_G_50
    goto    Next_50
Oui_G_50:   bcf     Image,PWM_G      ; oui
Next_50:   btfsc   MOT_D,0x02   ; MLI Moteur droit = 50% ?
    goto    Oui_D_50
    goto MLI_50
Oui_D_50:   bcf     Image,PWM_D      ; oui

MLI_50:
; MLI = 50%
    movf   Image,0
    movwf   PORTB


; Delay de 15,5us
    movlw   d'25'
    movwf   VAR
Boucle3:
    decfsz  VAR,1
    goto    Boucle3


; on teste si on remet la MLI � 0 � 75%...
    btfsc   MOT_G,0x03   ; MLI Moteur gauche = 75% ?
    goto    Oui_G_75
    goto    Next_75
Oui_G_75:   bcf     Image,PWM_G      ; oui
Next_75:   btfsc   MOT_D,0x03   ; MLI Moteur droit = 75% ?
    goto    Oui_D_75
    goto MLI_75
Oui_D_75:   bcf     Image,PWM_D      ; oui

MLI_75:
; MLI = 75%
    movf   Image,0
    movwf   PORTB

;  Ce delay est � ajuster quand le d�codage des bits de sens sera fait
; Delay de 15,5us
    movlw   d'21'
    movwf   VAR
Boucle4:
    decfsz  VAR,1
    goto    Boucle4

        
; On lit les ordres sur le port A pour le prochain tour
LOOP:
    movf   PORTA,0
    movwf   Ordre
    movf    Ordre,0
    btfss   STATUS,Z ; on teste si Image=0
    goto    DECODE   ; Image!=0, on a un ordre valide que l'on va d�coder
    clrf    PORTB    ; Image=0, on arr�te le robot
    goto    LOOP     ; Et on reboucle : attente de nouveaux ordres

; d�codage des ordres selon la table de v�rit�
DECODE:
    clrf    MOT_G   ; RAZ des ordres pour le moteur gauche
    clrf    MOT_D   ; RAZ des ordres pour le moteur droit

; commencement des tests
    btfsc   Ordre,0x00 ; PA0=1 ?
    goto    Yes_1 ; oui 
; non : PA0 = 0, on teste PA1
    btfsc   Ordre,0x01 ; PA1=1 ?
    goto    Yes_2 ; oui
    goto    ERREUR

Yes_1:  btfsc   Ordre,0x01 ; PA1=0 ?
    goto    Suite_1 ; non
    goto    Vit_25 ; oui

Yes_2:  btfss Ordre,0x02 ; PA2=0 ? ;
        goto    Vit_50 ; non, alors c'est la vitesse 50%
        goto    ERREUR ; va vers les rotations. Pour l'instant on dirige vers l'erreur
;;;;;;;;;;;;;;;;;
; TO DO ICI
; RAJOUTER UNE SERIE DE TESTS POUR LES ROTATIONS
;;;;;;;;  
; Labels pour les rotations, pas encore fait
ROTATE_G:

ROTATE_D:
; fin labels des rotations
;;;;;;;;;;;;;;;;;;;;;;;

Suite_1: btfsc Ordre,0x02 ; PA2=0 ? ; on teste PA2...
    goto    Vit_100 ; PA2=1, vitesse = 100%
    goto    Vit_75  ; PA2=0, vitesse = 75%

Vit_25:
    bsf MOT_G,0x01
    bsf MOT_D,0x01
    goto SUITE
Vit_50:
    bsf MOT_G,0x02
    bsf MOT_D,0x02
    goto SUITE
Vit_75:
    bsf MOT_G,0x03
    bsf MOT_D,0x03
    goto SUITE
; m�me si on ne teste jamais le bit 100% dans MOT_G/D, on le met � 1, pour la forme et pour contr�ler...
Vit_100:
    bsf MOT_G,0x04
    bsf MOT_D,0x04
SUITE:
    bsf     Image,PWM_G
    bsf     Image,PWM_D
; On �crit les ordres sur les broches du port B
    movf   Image,0
    movwf   PORTB
    goto    REB

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; CONFIGURATION DES PORTS ET DES REGISTRES
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

INIT:
    bcf     STATUS, RP0 ; Select Bank 0
    clrf    PORTA
    clrf    PORTB
    clrf    TMR0
    bsf     STATUS, RP0 ; Select Bank 1
    ; Le port A contient les ordres en provenance de PIC1
    movlw   0xFF ; 0 = sortie, 1 = entr�e
    movwf   TRISA
    
    ; Tout le port B en sortie
    movlw   0x00
    movwf   TRISB
    movlw   B'01011111' ; pull up sur portb et timer
    movwf   OPTION_REG
    bcf     STATUS, RP0 ; Select Bank 0
    
 
    ; Par d�faut, PORTB=0  et PORTA=0 donc le robot est � l'arr�t
    ; La variable Image est l'image du port B
    clrf    Image
    clrf    PORTB
    clrf    MOT_G
    clrf    MOT_D
    bsf     PORTB,0 ; pour les tests uniquement
    return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN DU FICHIER
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ERREUR: goto ERREUR ; �chappatoire pour les codes de la table de v�rit� non impl�ment�s

    end
