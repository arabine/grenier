;
title impression de al ou de ax sur la console en hexa
;
NAME HEX_OUT
;
                PUBLIC     PRINT_AL,PRINT_AX
;
;
PILE            SEGMENT     STACK   'STACK'
                DW      9 DUP (?)
PILE            ENDS
;
;
	ASSUME CS:CODE
        ASSUME SS:PILE
;
CODE		SEGMENT	    PUBLIC   'CODE'
;
; Sous-programme interne de conversion
; d'un digit hexadecimal en son code ascii
; puis envoie sur la console
;
HEX_DIGIT_OUT   PROC    NEAR
                AND	AL,0FH
		ADD	AL,90H
		DAA
		ADC	AL,40H
		DAA
		MOV	AH,02
		MOV	DL,AL
		INT	21H
		RET
HEX_DIGIT_OUT   ENDP
;
; Impression de al sur la console
;
PRINT_AL        PROC    FAR
		PUSH	AX
		PUSH	CX
		PUSH	DX
		MOV	DH,AL
		MOV	CL,4
		SHR	AL,CL
		CALL    HEX_DIGIT_OUT
		MOV	AL,DH
		CALL	HEX_DIGIT_OUT
		POP	DX
		POP	CX
		POP	AX
		RET
;
PRINT_AL        ENDP
;
; Impression de ax sur la console
;
PRINT_AX        PROC    FAR
		PUSH	AX
                MOV     AL,AH
                CALL    PRINT_AL
                POP     AX
                PUSH    AX
                CALL    PRINT_AL
                POP     AX
                RET
PRINT_AX        ENDP
;
CODE    	ENDS
;
	        END
