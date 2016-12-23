		page,132
;
NAME            APPEL_DOS
;
TITLE           SOUS PROGRAMMES DE BIBLIOTHEQUE
;
                PUBLIC      CI,CO,CRLF,TEST_INPUT
                PUBLIC      OUTPUT_MESSAGE
                PUBLIC      RETOUR_DOS
;
PILE            SEGMENT     STACK   'STACK'
                DW	    10H     DUP(?)
PILE            ENDS
;
;
                ASSUME      CS:CODE,SS:PILE
;
CODE            SEGMENT     PUBLIC  'CODE'
;
;Proc‚dure de lecture d'un caractŠre …
;partir du clavier, AL contient le
;caractŠre frapp‚ au clavier
; SORTIE : AL contient le caractŠre ascii frapp‚ au clavier
;
CI              PROC        FAR
                PUSH        CX
                MOV         CH,AH
                MOV         AH,01
                INT         21H
		MOV         AH,CH
                POP         CX
                RET
CI              ENDP
;
;Procedure de sortie d'un caractŠre sur la
;console
; ENTREE : AL  contient le caractŠre ASCII … imprimer
;
CO              PROC        FAR
     		PUSH	    AX
                PUSH        DX
                MOV         DL,AL
                MOV         AH,02H
                INT         21H
                POP         DX
		POP         AX
                RET
CO              ENDP
;
;
;Procedure effectuant un retour au DOS
;
RETOUR_DOS      PROC        FAR
                MOV         AH,4CH
                INT         21H
; rearque AH d‚truit, mais sans importance !!!
                RET
RETOUR_DOS      ENDP
;
;Proc‚dure effectuant un retour chariot
;et un saut de ligne
;
CRLF            PROC        FAR
     		PUSH	    AX
                PUSH        DX
                MOV         DL,0DH
                MOV         AH,02
                INT         21H
                MOV         DL,0AH
                MOV         AH,02
                INT         21H
                POP         DX
		POP         AX
                RET
CRLF            ENDP
;
;proc‚dure testant l'‚tat du clavier
;AL=0 pas de caractŠre re‡u
;AL=-1 un caractŠre est disponible en entr‚e
;
;
TEST_INPUT      PROC        FAR
     		PUSH        CX
                MOV         CH,AH
                MOV         AH,0BH
                INT         21H
		MOV         AH,CH
                POP         CX
                RET
TEST_INPUT      ENDP
;
;proc‚dure de visualisation d'un message
;se terminant par $.
;DS:DX adresse du d‚but du message
;
OUTPUT_MESSAGE  PROC        FAR
     		PUSH	    AX
                MOV         AH,09H
                INT         21H
		POP         AX
                RET
OUTPUT_MESSAGE  ENDP
;
CODE            ENDS
;
                END
