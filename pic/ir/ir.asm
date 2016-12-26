;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; Free IR Receptor				;;;;
;;;; RC5 decode & RS232 (TX/RX) emulation	;;;;
;;;; (c) Anthony RABINE 2002			;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	; on utilise les librairies du 16F84
    LIST  P=16F84
    include	<p16f84.inc>

    ; Directives pour le programmateur (quartz 4MHz)
    __CONFIG   _CP_OFF & _PWRTE_ON & _WDT_OFF & _XT_OSC


;;;;;;;;;;;;
; DEFINES
;;;;;;;;;;;;
    
#define	TX	PORTA,0x02
#define RX	PORTA,0x03
#define IR	PORTB,0x00

;;;;;;;;;;;;;;;;;;;;;;;;;;
; VARIABLES EN RAM
; LA RAM COMMENCE EN 0x0C
;;;;;;;;;;;;;;;;;;;;;;;;;;
	CBLOCK 0x20

    	Temps:1 ; délai
	TXBUF:1	; buffer d'émission
	RXBUF:1 ; buffer de réception
	Cmpt:1	; compteur de bits	
	
	Addr:1	; adresse RC5
	Donnee:1	; Donnée RC5
	
	prec:1	; niveau précédent
	is_start:1	; est ce que c'est le début de la trame
	count:1		; compteur de bit
	
	tmp_bit:1	; gère le temps bit	
	Temps_:1

	ENDC    ; Fin de la RAM 

;;;;;;;;;;;;;;;;;;;;;;
; PROGRAMME PRINCIPAL
;;;;;;;;;;;;;;;;;;;;;;

	org	0x0000		 
	goto	START

	org	0x04
	call	IR_INT	; routine d'interruption
	bcf	INTCON,1
	bsf	INTCON,GIE
	retfie	; on retourne à l'endroit de l'interruption

	org	0x10
START:
	call	INIT	; Init des ports et les variables

	; On attend 'I'
rec_i:
	call	GETCHAR
	movlw	'I'
	subwf	RXBUF,0
	btfss	STATUS,Z
	goto	rec_i

	; On attend 'R'
rec_r:
	call	GETCHAR
	movlw	'R'
	subwf	RXBUF,0
	btfss	STATUS,Z
	goto	rec_r

	; on renvoie 'O' 
	movlw	'O'
	movwf	TXBUF
	call	PUTCHAR	

	; on renvoie 'K' 
	movlw	'K'
	movwf	TXBUF
	call	PUTCHAR	

	;;;;;; Initialisation terminée, on autorise l'interruption
	;;;;;; Le proc tourne dans le vide quand rien ne se passe

	bsf	INTCON,GIE
REB:
	goto	REB

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; INTERRUPT ROUTINE
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

IR_INT:
;;;;;;;;
; DELAI de 4.79 ms = 2 temps bit + 3/4
;;;;;;;;
	; interruptions interdites
	bcf	INTCON,GIE
	
	goto	prout	;<----- pour les tests simplement !! vérifier la routine de décodage
DELAY_1_2:
	movlw	D'126'
	movwf	Temps
delay2:
	call	DELAY_1_9
	decfsz	Temps,1
	goto	delay2

	goto	fin_delai


DELAY_1_9:
	movlw	D'10'
	movwf	Temps_
delay9:
	decfsz	Temps_,1
	goto	delay9
	return

fin_delai:

	movlw	D'5'
	movwf	count

ir_reb:
	call	DELAY_1_5	
	; on est maintenant sur un bit

	btfss	IR
	goto	ir_null
	bsf	STATUS,C
	goto	ir_next

ir_null:
	bcf	STATUS,C

ir_next:
	rrf	Addr,1
	decfsz	count,1
	goto	ir_reb

	; le stockage de l'adresse est terminé, on envoit le résultat par le port série

prout: ;<---- pour les tests simplement !! vérifier la routine de décodage
	movlw	Addr
	movwf	TXBUF
	call	PUTCHAR

	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; void PUTCHAR ( TXBUFF )
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
PUTCHAR:
	movlw	0x08
	movwf	Cmpt
	bsf	TX
putc1:	
	call	DELAY		; temps bit
	call	DELAY	
	rrf	TXBUF,1		; rotate right through carry
	btfsc	STATUS,0
	goto	Un
Zero:
	bsf	TX
	goto Suite
Un:
	bcf	TX
Suite:
	decfsz	Cmpt,1
	goto	putc1
	call	DELAY
	call	DELAY
	bcf	TX		; stop bit
	call	DELAY
	call	DELAY
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; RXBUFF GETCHAR ( void )
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
GETCHAR:
	movlw	0x00
	movwf	RXBUF
	movlw	0x08
	movwf	Cmpt
getc1:				; start detection
	btfss	RX
	goto	getc1
	
	call	DELAY		; milieu du start bit

	btfss	RX		; tjrs à 1 ?
	goto	getc1		; non, problème

getc2:
	call	DELAY		; next bit
	call	DELAY

	btfss	RX
	goto	One
Null:
	bcf	STATUS,0	; carry = 0
	goto	Next
One:
	bsf	STATUS,0	; carry = 1
Next:
	rrf	RXBUF,1		; rotate right through carry
	decfsz	Cmpt,1
	goto	getc2
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; DELAY DE 52us (quartz 4MHz)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DELAY:
	movlw	D'9'
	movwf	Temps
delay1:
	nop
	nop
	decfsz	Temps,1
	goto	delay1
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; DELAY DE 1.6ms (quartz 4MHz) : environ un temps bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

DELAY_1_5:
	movlw	D'200'
	movwf	Temps
delay5:
	nop
	nop
	nop
	nop
	nop
	decfsz	Temps,1
	goto	delay5
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; CONFIGURATION DES PORTS ET DES REGISTRES
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
INIT:
	bcf     STATUS, RP0 ; Select Bank 0
	clrf    PORTA
 	clrf    PORTB
    	clrf    TMR0
    	bsf     STATUS, RP0 ; Select Bank 1

	; RA2 en sortie
	; RA3 en entrée
	movlw   B'00001000' ; 0 = sortie, 1 = entrée
	movwf   TRISA
	
	;RB3 en entrée
	movlw   B'00000001' ; 0 = sortie, 1 = entrée
	movwf   TRISB

    	movlw   B'00011111'
    	movwf   OPTION_REG
	movlw   B'10010000'
    	movwf   INTCON
    	bcf     STATUS, RP0 ; Select Bank 0

    	bcf     TX
	
	clrf	Addr
	clrf	Donnee    	
	clrf	prec
	clrf	is_start
	movlw	D'14'
	movwf	count	
	clrf	tmp_bit

	return
    end
