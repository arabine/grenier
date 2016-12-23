   NAME    toto
   title
;
   EXTRN CI:FAR , TEST_INPUT:FAR
   EXTRN OUTPUT_MESSAGE :FAR, PRINT_AL:far
   EXTRN CRLF:FAR
 ;
 PILE     SEGMENT STACK 'STACK'
          DW 200H DUP (?)
          TOP LABEL WORD
 PILE     ENDS
;
 DATA    SEGMENT PUBLIC 'DATA'
         DB 100H DUP (?)
 DATA    ENDS
;
 CODE    SEGMENT PUBLIC 'CODE'
;
 ASSUME  CS:CODE,SS:PILE,DS:DATA
;
 DEBUT:
       MOV AX,PILE
       MOV SS,AX               ;INIT DE LA PILE
       MOV SP,OFFSET TOP
;
       MOV AX,DATA
       MOV DS,AX               ;INIT DE DS
;

       Mov cx,0
 encore:      call TEST_INPUT
       Call PRINT_AL
       call CRLF
       call TEST_INPUT
       Call PRINT_AL
       loop encore


; RETOUR DOS
       MOV AH,4CH
       INT 21H
;
 CODE ENDS
      END DEBUT
