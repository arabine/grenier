 
	include	<p16f84.inc>
	
RS 	EQU	 0x04
RW 	EQU	 0x00
E  	EQU	 0x02


; Variables

VAR 	EQU	0x2F
VAR2	EQU	0x2E

;*************Début physique du programme à l'adresse 0H ********************
	org	0		 
	nop	
	goto	START
	
;************************Programme principal**********************************
	org	0x10

;;;;;;;;;;;;;;;;;;;;;;;;;
; void main ( void )
;;;;;;;;;;;;;;;;;;;;;;;;;

START:

	; configurations des ports

	bsf	STATUS,RP0	;met en bank 1
	clrf	TRISB		; PORT B en sortie
	clrf	TRISA		; PORT A en sortie
	bcf	STATUS,RP0	; met en bank 0 pour utiliser le port A physiqmt
	bsf	PORTA,RS
	bsf	PORTA,RW

BOUCLE:
	; appels des fonctions d'init et de test
	call	INIT
	
	goto	BOUCLE

;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN DU MAIN
;;;;;;;;;;;;;;;;;;;;;;;;;

INIT:
	movlw	d'20'
	call	DELAY
	bsf	PORTA,0x01	; pour les tests
	call 	TEST_BUSY
	bcf	PORTA,0x01	; pour les tests
	
	; config du hard
	movlw	0x38
	call	CONFIG	
	call 	TEST_BUSY
	
	; config de l'affichage
	movlw	0x0F
	call	CONFIG	
	call 	TEST_BUSY
	
	; RAZ écran
	movlw	0x01
	call	CONFIG	
	call 	TEST_BUSY
	
	return

CONFIG:
	bcf	PORTA,RS
	bcf	PORTA,RW
	movwf	PORTB
	bsf	PORTA,E
	bcf	PORTA,E
	bsf	PORTA,RS
	bsf	PORTA,RW
	return

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
	bsf	STATUS,RP0	;met en bank 1
	movlw	0xFF
	movwf	TRISB
	bcf	STATUS,RP0	; met en bank 0 pour utiliser le port A physiqmt

LOOP_BF:	
	btfsc   PORTB,0x07 	; test du busy flag si c'est vrai il saute l'instruction 
				; sinon il boucle
	goto	LOOP_BF
	
	;remise du portb en sortie
	bsf	STATUS,RP0	;met en bank 1
	clrf	TRISB
	bcf	STATUS,RP0	; met en bank 0 pour utiliser le port A physiqmt
	
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

;FIN:
	end

