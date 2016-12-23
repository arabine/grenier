;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;       petite demo
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RAM		EQU	$1000
STACK		EQU	RAM+$FF		;initialise le pointeur de pile a la fin de la RAM
EEPROM		EQU	$F800

; Registres

RBASE	EQU	$0000
PORTA	EQU	RBASE+$00
INIT	EQU	$103D		; fixe avant utilisation

; Programme 

	ORG	EEPROM

init:
        LDAA    #$10
        STAA    INIT            ;RAM en $1000, Registres en $0000
	SEI			;interruptions inhibees
	LDS	#STACK	 	;initialise le pointeur de pile

Debut:	LDAA	#$FF
	STAA	PORTA