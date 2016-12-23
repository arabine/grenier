;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;       Modele de programmation
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RAM		EQU	$1000
STACK		EQU	RAM+$FF		;initialise le pointeur de pile a la fin de la RAM
EEPROM		EQU	$F800

; Registres

RBASE	EQU	$0000

PORTA	EQU	RBASE+$00
PIOC	EQU	RBASE+$02
PORTC	EQU	RBASE+$03
PORTB	EQU	RBASE+$04
PORTCL	EQU	RBASE+$05
DDRC	EQU	RBASE+$07
PORTD	EQU	RBASE+$08
DDRD	EQU	RBASE+$09
PORTE	EQU	RBASE+$0A
CFORC	EQU	RBASE+$0B
OC1M	EQU	RBASE+$0C
OC1D	EQU	RBASE+$0D
TCNT	EQU	RBASE+$0E
TIC1	EQU	RBASE+$10
TIC2	EQU	RBASE+$12
TIC3	EQU	RBASE+$14
TOC1	EQU	RBASE+$16
TOC2	EQU	RBASE+$18
TOC3	EQU	RBASE+$1A
TOC4	EQU	RBASE+$1C
TI4O5	EQU	RBASE+$1E
TCTL1	EQU	RBASE+$20
TCTL2	EQU	RBASE+$21
TMSK1	EQU	RBASE+$22
TFLG1	EQU	RBASE+$23
TMSK2	EQU	RBASE+$24
TFLG2	EQU	RBASE+$25
PACTL	EQU	RBASE+$26
PACNT	EQU	RBASE+$27
SPCR	EQU	RBASE+$28
SPSR	EQU	RBASE+$29
SPDR	EQU	RBASE+$2A
BAUD	EQU	RBASE+$2B
SCCR1	EQU	RBASE+$2C
SCCR2	EQU	RBASE+$2D
SCSR	EQU	RBASE+$2E
SCDR	EQU	RBASE+$2F
ADCTL	EQU	RBASE+$30
ADR1	EQU	RBASE+$31
ADR2	EQU	RBASE+$32
ADR3	EQU	RBASE+$33
ADR4	EQU	RBASE+$34
BPROT	EQU	RBASE+$35
OPTION	EQU	RBASE+$39
COPRST	EQU	RBASE+$3A
PPROG	EQU	RBASE+$3B
HPRIO	EQU	RBASE+$3C
INIT	EQU	$103D		; fixe avant utilisation
TEST1	EQU	RBASE+$3E
CONFIG	EQU	RBASE+$3F

	ORG	RAM

; Variables

toto	RMB     1

; Programme 

	ORG	EEPROM

init:
        LDAA    #$10
        STAA    INIT            ;RAM en $1000, Registres en $0000
	SEI			;interruptions inhibees
	LDS	#STACK	 	;initialise le pointeur de pile

; ecrivez votre code ici...


;;;;;;;;;;;;;;;;;;;
;
; Procedures :
;
;;;;;;;;;;;;;;;;;;;

; ecrivez votre code ici...


	ORG	$FFD6

;  Vecteurs d'interruptions et de reset :

SCI_VECT	FDB	init
SPI_VECT	FDB	init
PAI_VECT	FDB	init
PAO_VECT	FDB	init
TOF_VECT	FDB	init

TOC5_VECT	FDB	init
TOC4_VECT	FDB	init
TOC3_VECT	FDB	init
TOC2_VECT	FDB	init
TOC1_VECT	FDB	init
TIC3_VECT	FDB	init
TIC2_VECT	FDB	init
TIC1_VECT	FDB	init

RTI_VECT	FDB	init
IRQ_VECT	FDB	init
XIRQ_VECT	FDB	init
SWI_VECT	FDB	init
TRAP_VECT	FDB	init
COP_FAIL_VECT	FDB	init
COP_CMF_VECT	FDB	init
RESET_VECT	FDB	init

