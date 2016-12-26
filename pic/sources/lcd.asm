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

	; RS=1, RW=1
	bsf	PORTA,RS
	bsf	PORTA,RW

BOUCLE:

	call	INIT
	
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
	movlw	0x79
	call	PUTCHAR
	call 	TEST_BUSY
	
	goto	FIN

;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN DU MAIN
;;;;;;;;;;;;;;;;;;;;;;;;;

INIT:

	bsf	PORTA,0x01	; pour les tests

	; 2) delay après la mise sous tension
	movlw	d'20'	; 20 ms
	call	DELAY

	; 3) DL = 1
	movlw	0x30
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

	; 8)
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
	movlw	0x06
	call	CONFIG

	; 16)	
	call 	TEST_BUSY

	;;;;;;;;;;;;
	; 17) INIT TERMINEE
	;;;;;;;;;;;;

	; DDRAM Adress 
	;movlw	0x80
	;call	CONFIG	
	;call 	TEST_BUSY

	bcf	PORTA,0x01	; pour les tests

	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; void CONFIG ( char Configuration )
; Cette fonction envoie un octet de configuration à l'écran
; entree : La configuration est dans l'accumulateur W
; sortie : -
; variables détruites : 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CONFIG:
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
	bsf	PORTA,RS
	bcf	PORTA,RW

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
	bsf	STATUS,RP0
	movlw	0xFF
	movwf	TRISB
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

	;remise du portb en sortie
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
	bcf	STATUS,C
	movwf	VAR
	rlf	VAR,1		; multiplie W par 2

LOOP_DELAY:
	movlw	0xA5		; chargemt de 0xff ds l'accu
	movwf	VAR2		; var2=0xff
	call LOOP2_DELAY
	decfsz	VAR,1
	goto LOOP_DELAY
	return

LOOP2_DELAY:				; deuxieme boucle imbriquee
	decfsz	VAR2,1
	goto LOOP2_DELAY
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION RETARD
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


; On sort du programme

FIN:	goto	FIN
	end

