;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;     	clignote.asm
;
;     	Clignotement d'une led sur 
;	PB0, a la frequence de 1 Hz
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RAM		EQU	$1000
STACK		EQU	RAM+$FF		;put stack at top of ram
EEPROM		EQU	$F800

* registers

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
INIT	EQU	$103D		; fixed before use
TEST1	EQU	RBASE+$3E
CONFIG	EQU	RBASE+$3F

; Program

	ORG	EEPROM

init:
        LDAA    #$10
        STAA    INIT            ;RAM at $1000, Registers at $0000
	SEI			;inhibits interrupts
	LDS	#STACK	 	;initialize stack pointer

boucle:
	BSET	PORTB %00000001	;allumage de la led

	LDAA	#5
	BSR	tempo		;temporisation de 0,5 seconde

	BCLR	PORTB %00000001 ;extinction de la led

	LDAA	#5
	BSR	tempo		;temporisation de 0,5 seconde

	BRA	boucle		;recommence

; Procedures

;temporisation de duree : Accu A * 0.1s (quartz 8MHz)
;duree : de 0.1s à 25.5s
;argument : Accu A

val	EQU	33332		; tempo=A*0.1s (3332 pour 0.01s)
tempo:
        PSHX                    ; sauvegarde de X
_tmp1   LDX     #val
_tmp2   DEX
        BNE     _tmp2
        DECA
        BNE     _tmp1
        PULX
        RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	ORG	$FFD6

;  Interrupt and reset vectors.

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

