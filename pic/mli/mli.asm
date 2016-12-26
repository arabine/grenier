 	; on utilise les librairies du 16F84A
    LIST  P=16F84A
    include	<p16f84a.inc>

    ; Directives pour le programmateur (oscillateur rapide)
    __CONFIG   _CP_OFF & _PWRTE_ON & _WDT_OFF & _HS_OSC

;**************************************************************************************
; Configuration du Hard
; 4 bits poids faible du port B reliés au 
; PIC numéro 1 : capteurs
; TABLE DE VERITE :
;
;  PB3   |   PB2    |   PB1    |   PB0    | Vitesse
; ------ | -------- | -------- | -------- | --------
;  0     |    0     |   0      |   0      | Vitesse 25% avant
;  0     |    0     |   0      |   1      | Vitesse 50% avant
;  0     |    0     |   1      |   0      | Vitesse 75% avant
;  0     |    0     |   1      |   1      | Vitesse 100% avant
;  0     |    1     |   0      |   0      | ERREUR D'ORDRE !!
;  0     |    1     |   0      |   1      | ERREUR D'ORDRE !!
;  0     |    1     |   1      |   0      | Rotation : moteur gauche arrière vitesse 50%, moteur droit avant vitesse 100%
;  0     |    1     |   1      |   1      | Arrêt robot
;  1     |    0     |   0      |   0      | Vitesse 25% arrière
;  1     |    0     |   0      |   1      | Vitesse 50% arrière
;  1     |    0     |   1      |   0      | Vitesse 75% arrière
;  1     |    0     |   1      |   1      | Vitesse 100% arrière
;  1     |    1     |   0      |   0      | ERREUR D'ORDRE !!
;  1     |    1     |   0      |   1      | ERREUR D'ORDRE !!
;  1     |    1     |   1      |   0      | Rotation : moteur gauche avant vitesse 100%, moteur droit arrière vitesse 50%
;  1     |    1     |   1      |   1      | Arrêt robot
;**************************************************************************************


;**************************************************************************************
; DEFINITION DE CONSTANTES
;**************************************************************************************

; Broches en sortie

PWM_G   EQU     0x00		; PWM moteur gauche RA0
PWM_D   EQU     0x01		; PWM moteur droit RA1
SENS_G  EQU     0x02		; Sens moteur gauche RA2
SENS_D  EQU     0x03		; Sens moteur droit RA3

LED	EQU	0x07		; LED de signalisation d'une erreur sur RB7

;**************************************************************************************
; VARIABLES EN RAM
; LA RAM COMMENCE EN 0x0C
;**************************************************************************************
	CBLOCK 0x20

	Image:1			; l'octet image des broches du port A
	Ordre:1			; L'octet image du port B en provenance du PIC Capteurs
	VAR:1

; mémorisation des ordres pour chaque moteur
;         6   5   4   3   2   1   0
; MOT_X   -   -  100  75  50  25  SENS
;
; SENS=1 : arrière , SENS=0 : avant
	
	MOT_G:1
	MOT_D:1
	
	ENDC			; Fin de la RAM 

;**************************************************************************************
; PROGRAMME PRINCIPAL
;**************************************************************************************

	org	0000h		 
	goto	START
	
	org	05h

START:
	call INIT
    
    	; Après l'init, on va chercher les ordres sur le port B
	goto LOOP


;**************************************************************************************
; DEBUT DE LA MLI
;**************************************************************************************

REB:

; Delay de 15,5us
	movlw   d'25'
	movwf   VAR
Boucle1:
	decfsz  VAR,1
	goto    Boucle1    


;********************************** MLI 25% *******************************************

; La routine suivante dure 2 us
	btfsc   MOT_G,0x01	; MLI Moteur gauche = 25% ?
	goto    Oui_G_25
	goto    Next_25
Oui_G_25:
	bcf     Image,PWM_G	; oui
Next_25:
	btfsc   MOT_D,0x01	; MLI Moteur droit = 25% ?
	goto    Oui_D_25
	goto MLI_25
Oui_D_25:
	bcf     Image,PWM_D	; oui

MLI_25:
; MLI = 25% : On envoie l'image des broches sur le porta
	movf   Image,0
	movwf   PORTA

; Delay de 15,5us
	movlw   d'25'
	movwf   VAR
Boucle2:
	decfsz  VAR,1
	goto    Boucle2

;********************************** MLI 50% *******************************************
	btfsc   MOT_G,0x02	; MLI Moteur gauche = 50% ?
	goto    Oui_G_50
	goto    Next_50
Oui_G_50:
	bcf     Image,PWM_G	; oui
Next_50:
	btfsc   MOT_D,0x02	; MLI Moteur droit = 50% ?
	goto    Oui_D_50
	goto MLI_50
Oui_D_50:
	bcf     Image,PWM_D	; oui

MLI_50:
; MLI = 50%
	movf   Image,0
	movwf   PORTA

; Delay de 15,5us
	movlw   d'25'
	movwf   VAR
Boucle3:
	decfsz  VAR,1
	goto    Boucle3

;********************************** MLI 75% *******************************************
	btfsc   MOT_G,0x03	; MLI Moteur gauche = 75% ?
	goto    Oui_G_75
	goto    Next_75
Oui_G_75:
	bcf     Image,PWM_G	; oui
Next_75:
	btfsc   MOT_D,0x03	; MLI Moteur droit = 75% ?
	goto    Oui_D_75
	goto MLI_75
Oui_D_75:
	bcf     Image,PWM_D	; oui

MLI_75:
; MLI = 75%
	movf	Image,0
	movwf   PORTA

;  Ce delay est à ajuster quand le décodage des bits de sens sera fait
; Delay de 15,5us
	movlw   d'21'
	movwf   VAR
Boucle4:
	decfsz  VAR,1
	goto    Boucle4

;******************************* LECTURE DES ORDRES ************************************
        
; On lit les ordres sur le port B pour le prochain tour
LOOP:
	movf	PORTB,0
	iorlw	0xF0		; on masque la partie basse du port B
	movwf   Ordre
	movf    Ordre,0
	addlw	d'1'		; on ajoute 1, donc le résultat=0 si on demande l'arrêt du robot (c'est plus facile de tester si une valeur est à 0 !!)
	btfss   STATUS,Z	; on teste si Ordre=0
	goto    DECODE		; Ordre!=0, on a un ordre valide que l'on va décoder
	clrf    PORTA		; Ordre=0, on arrête le robot
	goto    LOOP		; Et on reboucle : attente de nouveaux ordres

; décodage des ordres selon la table de vérité
DECODE:
	clrf    MOT_G		; RAZ des ordres pour le moteur gauche
	clrf    MOT_D		; RAZ des ordres pour le moteur droit

; on commence les tests par décoder le sens de marche
	btfsc   Ordre,0x03	; PB3=1 ?
	goto    ARRIERE		; oui, le robot recule (ou tourne !!)

AVANT:
	bcf	MOT_D,0x00
	bcf	MOT_G,0x00
	bcf     Image,SENS_G
	bcf     Image,SENS_D
	goto	SUITE_0

ARRIERE:
	bsf	MOT_D,0x00
	bsf	MOT_G,0x00
	bsf     Image,SENS_G
	bsf     Image,SENS_D

; maintenant, on va trier entre les vitesses ou les mouvements spéciaux (arrêt, rotation)
SUITE_0:
	btfsc   Ordre,0x02	; PB2=1 ?
	goto    SPECIAL		; oui, c'est un mouvement spécial

; on décode la vitesse choisie...
	btfsc   Ordre,0x01	; PB1=1 ?
	goto	VIT_75_100	; oui, la vitesse est 75% ou 100%

VIT_25_50:
	btfsc   Ordre,0x00	; PB0=1 ?
	goto	VIT_50		; oui, la vitesse est 50%
	goto	VIT_25		; non, la vitesse est 25%

VIT_75_100:
	btfsc   Ordre,0x00	; PB0=1 ?
	goto	VIT_100		; oui, la vitesse est 100%
	goto	VIT_75		; non, la vitesse est 75%

; ici on gère les rotations, l'arrêt du robot et les ordres non valides !
SPECIAL:
	btfss   Ordre,0x01	; PB1=1 ?
	goto	ERREUR		; NON ! CODE ILLEGAL !

	btfsc   Ordre,0x00	; PB0=1 ?
	goto	STOP_BOT	; oui, on stoppe le robot

; Deux rotations possibles, le bit RB3 permet de choisir la bonne
	
	btfsc   Ordre,0x03	; PB3=1 ?
	goto	ROT_2		; oui, on fait une des deux rotations

;Rotation : moteur gauche arrière vitesse 50%, moteur droit avant vitesse 100%
ROT_1:
	bsf     Image,SENS_G	; moteur gauche arrière
	bsf	MOT_G,0x02	; moteur gauche 50%
	bcf	Image,SENS_D	; moteur droit avant
	bsf	MOT_D,0x04	; moteur droit 100%
	goto	SUITE_1

;Rotation : moteur gauche avant vitesse 100%, moteur droit arrière vitesse 50%
ROT_2:
	bcf     Image,SENS_G	; moteur gauche avant
	bsf	MOT_G,0x04	; moteur gauche 100%
	bsf	Image,SENS_D	; moteur droit arrière
	bsf	MOT_D,0x02	; moteur droit 50%
	goto	SUITE_1

STOP_BOT:
	clrf	PORTA		; on stoppe le robot
	goto	LOOP		; et on reboucle !

VIT_25:
	bsf	MOT_G,0x01
	bsf	MOT_D,0x01
	goto	SUITE_1
VIT_50:
	bsf	MOT_G,0x02
	bsf	MOT_D,0x02
	goto	SUITE_1
VIT_75:
	bsf	MOT_G,0x03
	bsf	MOT_D,0x03
	goto	SUITE_1
; même si on ne teste jamais le bit 100% dans MOT_G/D, on le met à 1, pour la forme et pour éventuellement contrôler...
VIT_100:
	bsf	MOT_G,0x04
	bsf	MOT_D,0x04

SUITE_1:
	bsf     Image,PWM_G
	bsf     Image,PWM_D

; On écrit les ordres sur les broches du port A
	movf   Image,0
	movwf   PORTA
	
	goto    REB

;**************************************************************************************
; INITIALISATION DES PORTS ET DES REGISTRES
;**************************************************************************************

INIT:
	bcf     STATUS, RP0	; Select Bank 0
	clrf    PORTA
	clrf    PORTB
	clrf    TMR0
	bsf     STATUS, RP0	; Select Bank 1
	
	movlw   B'01111111'	; 0 = sortie, 1 = entrée
	movwf   TRISB		; Le port B contient les ordres en provenance de PIC1 + la LED
    
	movlw   0x00
	movwf   TRISA		; Tout le port A en sortie

	movlw   B'10000000'	; PAS de pull up sur portb
	movwf   OPTION_REG
	
	movlw	B'00000000'	; pas d'interruptions
	movwf	INTCON

	bcf     STATUS, RP0	; Select Bank 0
 
	; Par défaut, PORTB=0xFF (résistances de tirage externe) et PORTA=0 donc le robot est à l'arrêt
	; La variable Image est l'image du port A
	clrf    Image
	clrf    PORTA
	clrf    MOT_G
	clrf    MOT_D
	
	return

;**************************************************************************************
; GESTION DES ERREURS DE L'ORDRE DE MARCHE
;**************************************************************************************

ERREUR:
	clrf	PORTB		; On arrête le robot
	bsf	PORTB,LED	; On signale l'erreur
	goto LOOP		; On reboucle, pour attendre un code valide...

;**************************************************************************************
; FIN DU FICHIER
;**************************************************************************************
    end
