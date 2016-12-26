 	include	<p16f84.inc>

;;;;;;;;;;;;;;;;;;;;;;;;;
; Defines
;;;;;;;;;;;;;;;;;;;;;;;;;
	
RS 	EQU	 0x03; RS sur RA3
RW 	EQU	 0x00
E  	EQU	 0x02

;;;;;;;;;;;;;;;;;;;;;;;;;
; Variables
;;;;;;;;;;;;;;;;;;;;;;;;;

VAR 	EQU	0x2F
VAR2	EQU	0x2E

;;;;;;;;;;;;;;;;;;;;;;;;;
; Début du programme à l'adresse 0H
;;;;;;;;;;;;;;;;;;;;;;;;;

	org	0		 
	nop	
	goto	START

;;;;;;;;;;;;;;;;;;;;;;;;;	
; Programme principal
;;;;;;;;;;;;;;;;;;;;;;;;;

	org	0x10

;;;;;;;;;;;;;;;;;;;;;;;;;
; void main ( void )
;;;;;;;;;;;;;;;;;;;;;;;;;

START:

	; configurations des ports
	clrf	PORTA
	bsf	STATUS,RP0	;met en bank 1
	;movlw	0x7F
	;movwf	OPTION_REG	; Port B avec résistances de pull up p.15
	clrf	TRISB		; PORT B en sortie
	clrf	TRISA		; PORT A en sortie
	bcf	STATUS,RP0	; met en bank 0 pour utiliser le port A physiqmt

	; lecture des données de la RAM du microcontrôleur alors (RS=1, RW=1)
	bsf	PORTA,RS
	bsf	PORTA,RW

BOUCLE:

	call	INIT 		; réalisation de la fonction init
	
	movlw	0x41
	call	PUTCHAR
	call 	TEST_BUSY
	movlw	0x6E
	call	PUTCHAR
	call 	TEST_BUSY
	movlw	0x74
	call	PUTCHAR
	call 	TEST_BUSY
	movlw	0x68
	call	PUTCHAR
	call 	TEST_BUSY
	movlw	0x6F
	call	PUTCHAR
	call 	TEST_BUSY
	movlw	0x6E
	call	PUTCHAR
	call 	TEST_BUSY
	;movlw	0x79
	;call	PUTCHAR
	;call 	TEST_BUSY
	
	;effacement du mot anthony après 1s ?
	
	movlw	d'1000'	; 1000 ms
	call	DELAY
	
	;movlw 0x01 	; fct clear display
	;call	 CONFIG
 	;call 	TEST_BUSY	

	;déplacement du curseur 
	movlw	0x02 ; fct entry mode set
	call CONFIG
	call TEST_BUSY
	
	;test position du curseur 
	
	movlw	0x40	; 2ème ligne 1ère colonne
	call CONFIG
	call TEST_BUSY
	
	
	
	goto	FIN

;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN DU MAIN
;;;;;;;;;;;;;;;;;;;;;;;;;

INIT:

	; 2) delay après la mise sous tension
	movlw	d'20'	; 20 ms
	call	DELAY

	; 3) DL = 1
	movlw	0x30	; initial reset of instruction, MEO function set
	call	CONFIG	
	
	; 4) 4,1 ms mini
	movlw	d'10'	; 10 ms
	call	DELAY
	
	; DL = 0
	movlw	0x00
	call	CONFIG	

	; 5) DL = 1
	movlw	0x30
	call	CONFIG
	
	; 6) 100 us mini
	movlw	d'1'	; 1 ms
	call	DELAY

	; DL = 0
	movlw	0x00
	call	CONFIG	

	; 7) DL = 1
	movlw	0x30
	call	CONFIG

	; 8) écran occupé ou pas?
	call 	TEST_BUSY

	; 9) config du hard : bus 8 bits, 2 lignes, digit 5*7
	movlw	0x38
	call	CONFIG	

	; 10)
	call 	TEST_BUSY

	; 11) DISPLAY MODE : Display ON, Cursor ON, Blink OFF
	movlw	0x0E
	call	CONFIG

	; 12)	
	call 	TEST_BUSY

	; 13) CLEAR DISPLAY
	movlw	0x01
	call	CONFIG

	; 14)	
	call 	TEST_BUSY

	; 15) SHIFT MODE : incrémentation de l'adresse, sans décalage de l'écran
	;  fonction entry mode set
	movlw	0x06
	call	CONFIG

	; 16)	
	call 	TEST_BUSY

	;;;;;;;;;;;;
	; 17) INIT TERMINEE
	;;;;;;;;;;;;

	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; void CONFIG ( char Configuration )
; Cette fonction envoie un octet de configuration à l'écran
; entree : La configuration est dans l'accumulateur W
; sortie : -
; variables détruites : 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CONFIG:  			; sur un frt montant de E, lcd reçoit les instructions
	; RS=0, RW=0
	bcf	PORTA,RS
	bcf	PORTA,RW

	movwf	PORTB
	bsf	PORTA,E
	bcf	PORTA,E

	; RS=1, RW=1
	bsf	PORTA,RS
	bsf	PORTA,RW
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION CONFIG
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; void PUTCHAR ( char Caractere )
; Cette fonction affiche un caractere à l'écran
; entree : Le caractere en ASCII est dans l'accumulateur W
; sortie : -
; variables détruites : 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTCHAR:
	; RS=1, RW=0
	bsf	PORTA,RS	; le lcd reçoit des instructions
	bcf	PORTA,RW 	; lcd lit le contenu de l'écran

	movwf	PORTB
	bsf	PORTA,E
	bcf	PORTA,E		; on baisse E pour valider la donnee

	; RS=1, RW=1
	bsf	PORTA,RS
	bsf	PORTA,RW
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION PUTCHAR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; void TEST_BUSY ( void )
; Fonction du test du Busy Flag
; Attend que l'écran est disponible
; entree : -
; sortie : -
; variables détruites : -
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TEST_BUSY:
	
	bcf	PORTA,RS	; RS=0
	bsf	PORTA,RW	; RW=1 (lecture du statut de l'écran)
	
	; on met le port B en entrée pour pouvoir lire	
	bsf	STATUS,RP0	; banque 1
	movlw	0xFF		; 
	movwf	TRISB		; portb en entrée
	bcf	STATUS,RP0

LOOP_BF:
	bcf	PORTA,E
	nop
	nop
	bsf	PORTA,E
	nop
	nop
	btfsc   PORTB,0x07 	; test du busy flag si c'est vrai il saute l'instruction 
				; sinon il boucle
	goto	LOOP_BF
	bcf	PORTA,E

	;remise du portb en sortie0
	bsf	STATUS,RP0	;met en bank 1
	clrf	TRISB
	bcf	STATUS,RP0	; met en bank 0 pour utiliser le port A physiqmt
	
	;RS=1, RW=1
	bsf	PORTA,RS
	bsf	PORTA,RW

	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION TEST_BUSY
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Fonction de retard DELAY
; entree : temps du retard en ms dans le registre W
; sortie : -
; variables détruites : VAR, VAR2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

DELAY:
	bcf	STATUS,C	;
	movwf	VAR
	rlf	VAR,1		; multiplie W par 2

LOOP_DELAY:
	movlw	0xA5		; chargemt de 0xff ds l'accu
	movwf	VAR2		; var2=0xff
	call LOOP2_DELAY
	decfsz	VAR,1		; si var différent de 0 var=var-1
	goto LOOP_DELAY		; sinon saute l'instruction suivante
	return

LOOP2_DELAY:				; deuxieme boucle imbriquee
	decfsz	VAR2,1
	goto LOOP2_DELAY
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION RETARD
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;FONCTION deplacement du curseur
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CURSEUR:
	
	
 	


; On sort du programme

FIN:	goto	FIN
	end
;;;;;;;;;;;;;;;;;;;;;;;;;
; affichage 

 
