; Quartz = 4MHz
	include	<p16f84.inc>
	
RS 	EQU	 0x04
RW 	EQU	 0x01
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

START:
	bsf	STATUS,RP0	;met en bank 1
	clrf	TRISA		; PORT A en sortie
	bcf	STATUS,RP0	; met en bank 0 pour utiliser le port A physiqmt

BOUCLE:
	bsf	PORTA,E
	movlw	d'5'	; on initialise le Delay à 5ms
	call	DELAY
	bcf	PORTA,E	
	movlw	d'5'
	call	DELAY
	
	goto	BOUCLE
	

	;call	INIT
	;call	SEND_CAR
	;goto	FIN

;INIT:
	

	;return

;SEND_CAR:


	;return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Fonction de retard
; entree : temps du retard en ms dans le registre W
; sortie : -
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

DELAY:
	bcf	STATUS,C
	movwf	VAR
	rlf	VAR,1		; multiplie W par 2

LOOP:
	movlw	0xA5		; chargemt de 0xff ds l'accu
	movwf	VAR2		; var2=0xff
	call LOOP2
	decfsz	VAR,1
	goto LOOP
	return

LOOP2:
	decfsz	VAR2,1
	goto LOOP2
	return

;FIN:
	end

