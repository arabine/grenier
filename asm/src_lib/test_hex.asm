NAME   TEST_HEXA
TITLE  TEST DU CARACTERE CONTENU DANS AL
;
                PUBLIC     TEST_HEX
;
PILE		SEGMENT	STACK 'STACK'
                DW	   4H DUP (?)
PILE		ENDS
;
;
	ASSUME CS:CODE
        ASSUME SS:PILE
;
CODE		SEGMENT	    PUBLIC  'CODE'
;
;  Programme de test et de conversion ascii --> hexa
;  entr‚e :  AL (valeur de 00 … FFh)
;  sorties:  CY = 0 si hexa ; CY = 1 si non hexad‚cimal
;            AL : code hexa ( de 0 … 9 et de A … F) si CY = 0
;
TEST_HEX        PROC    FAR
;
                SUB	AL,'0'
		JB	HRET
                CMP     AL,10
		CMC
		JNB	HRET
		SUB	AL,7
		CMP	AL,10
		JB	HRET
		CMP	AL,16
		CMC
HRET:		RET
;
TEST_HEX        ENDP
CODE    	ENDS
;
	        END
