10 REM    ---------------BATAILLE NAVALE----------------
20 REM          ---------------------------------
30 CLS:KEY OFF:SCREEN 1:RANDOMIZE TIMER
40 LINE (20,0)-(222,152),,B
50 FOR I=6 TO 146 STEP 10:FOR J=26 TO 216 STEP 10:CIRCLE (J,I),2:NEXT J,I
60 DIM T(20,15),TT(20,15),C(20),E(2400),F(2400),M(5):Y=2:A$="ABCDEFGHIJKLMNOPQRST":X=22
70 FOR N=1 TO 15:LOCATE 1,31:WRITE N:GET (238,0)-(254,8),C
80 IF N<10 THEN PUT (8,Y),C ELSE PUT (1,Y),C
90 Y=Y+10:NEXT N:LOCATE 1,31:PRINT "  "
100 FOR N=1 TO 20:LOCATE 1,31:PRINT MID$(A$,N,1):GET (238,0)-(246,8),C
110 PUT (X,154),C:X=X+10:NEXT N:LOCATE 1,31:PRINT " "
120 GET (0,0)-(225,165),F
130 A$(1)="PORTE-AVION":A$(2)="SOUS-MARIN":A$(3)="CROISEUR":A$(4)="DESTROYER":A$(5)="FREGATE"
140 LOCATE 4,32:PRINT "CHOIX:";CHR$(18):LOCATE 6,30:PRINT A$(1):L=5:COD=1
150 R$=INKEY$:IF R$=CHR$(13) THEN 180 ELSE IF R$="" THEN 150
160 COD=COD+1:IF COD=6 THEN COD=1
170 LOCATE 6,30:PRINT "           ":LOCATE 6,30:PRINT A$(COD):GOTO 150
180 IF M(COD)=2 THEN 150
185 IF COD=1 THEN L=5 ELSE IF COD=3 THEN L=4 ELSE IF COD=5 THEN L=2 ELSE L=3
190 FOR I=6 TO L*10-4 STEP 10:PAINT (216,I),2,3:NEXT I
200 A=20:B=1:D=1:FOR I=1 TO L:T(20,I)=T(20,I)+COD:NEXT I
210 R$=INKEY$:IF R$="" THEN 210
220 IF R$=" " THEN 2000 ELSE IF R$=CHR$(13) THEN 3000
230 IF D=2 GOTO 320
240 IF R$="8" AND B>1 THEN B=B-1:T(A,B)=T(A,B)+COD:PAINT (A*10+16,B*10-4),2,3:T(A,B+L)=T(A,B+L)-COD:IF T(A,B+L)=0 THEN PAINT (A*10+16,(B+L)*10-4),0,3:GOTO 210
250 IF R$="2" AND B+L-1<15 THEN B=B+1:T(A,B+L-1)=T(A,B+L-1)+COD:PAINT (A*10+16,(B+L-1)*10-4),2,3:T(A,B-1)=T(A,B-1)-COD:IF T(A,B-1)=0 THEN PAINT (A*10+16,B*10-14),0,3:GOTO 210
260 IF R$<>"4" THEN 290 ELSE IF A=1 THEN 210
270 FOR I=B TO B+L-1:T(A,I)=T(A,I)-COD:IF T(A,I)=0 THEN PAINT(A*10+16,I*10-4),0,3
280 NEXT I:A=A-1:FOR I=B TO B+L-1:T(A,I)=T(A,I)+COD:PAINT(A*10+16,I*10-4),2,3:NEXT I:GOTO 210
290 IF R$<>"6" THEN 210 ELSE IF A=20 THEN 210
300 FOR I=B TO B+L-1:T(A,I)=T(A,I)-COD:IF T(A,I)=0 THEN PAINT(A*10+16,I*10-4),0,3
310 NEXT I:A=A+1:FOR I=B TO B+L-1:T(A,I)=T(A,I)+COD:PAINT(A*10+16,I*10-4),2,3:NEXT I:GOTO 210
320 IF R$="4" AND A>1 THEN A=A-1:T(A,B)=T(A,B)+COD:PAINT (A*10+16,B*10-4),2,3:T(A+L,B)=T(A+L,B)-COD:IF T(A+L,B)=0 THEN PAINT ((A+L)*10+16,B*10-4),0,3:GOTO 210
330 IF R$="6" AND A+L-1<20 THEN A=A+1:T(A+L-1,B)=T(A+L-1,B)+COD:PAINT ((A+L-1)*10+16,B*10-4),2,3:T(A-1,B)=T(A-1,B)-COD:IF T(A-1,B)=0 THEN PAINT (A*10+6,B*10-4),0,3:GOTO 210
340 IF R$<>"8" THEN 370 ELSE IF B=1 THEN 210
350 FOR I=A TO A+L-1:T(I,B)=T(I,B)-COD:IF T(I,B)=0 THEN PAINT(I*10+16,B*10-4),0,3
360 NEXT I:B=B-1:FOR I=A TO A+L-1:T(I,B)=T(I,B)+COD:PAINT(I*10+16,B*10-4),2,3:NEXT I:GOTO 210
370 IF R$<>"2" THEN 210 ELSE IF B=15 THEN 210
380 FOR I=A TO A+L-1:T(I,B)=T(I,B)-COD:IF T(I,B)=0 THEN PAINT(I*10+16,B*10-4),0,3
390 NEXT I:B=B+1:FOR I=A TO A+L-1:T(I,B)=T(I,B)+COD:PAINT(I*10+16,B*10-4),2,3:NEXT I:GOTO 210
400 FOR I=1 TO 20:FOR J=1 TO 15
410 IF T(I,J)<>INT(T(I,J)) THEN GOSUB 1000
420 NEXT J,I
430 LOCATE 4,32:PRINT "        ":LOCATE 6,30:PRINT "           "
440 GET (0,0)-(225,165),E:R$=INPUT$(1)
450 COD=1:L=5:GOSUB 1500:GOSUB 1500:COD=2:L=3:GOSUB 1500:GOSUB 1500
460 COD=3:L=4:GOSUB 1500:GOSUB 1500:COD=4:L=3:GOSUB 1500:GOSUB 1500
470 COD=5:L=2:GOSUB 1500:GOSUB 1500
480 CLS:PUT (0,0),F:AL=0:COUP=1:W(1)=5:W(2)=3:W(3)=4:W(4)=3:W(5)=2:FOR I=1 TO 5:M(I)=W(I):MM(I)=W(I):NEXT I
490 REM -----------DEBUT DU JEU-----------
500 LOCATE 22,2:INPUT "COORDONNEES (LETTRE ET NOMBRE):",I$:LOCATE 22,2:PRINT "                                    "
501 IF LEN(I$)<2 OR LEN(I$)>3 THEN 500
505 X$=LEFT$(I$,1):Y$=MID$(I$,2,2)
510 X=INSTR(A$,X$):Y=VAL(Y$):IF X=0 OR Y<1 OR Y>15 OR Y<>INT(Y) OR TT(X,Y)=8 THEN 500
520 A=X*10+16:B=Y*10-4:PSET (A,170),2:DRAW"F2;D8;L4;U8;E2":PAINT (A,175),2,2
530 GET (A-3,169)-(A+3,180),C:COD=TT(X,Y):TT(X,Y)=8
535 K=0:IF COD<>0 THEN MM(COD)=MM(COD)-1:IF MM(COD)=0 OR MM(COD)=-W(COD) THEN K=1
540 FOR I=166 TO B STEP -3:PUT (A-3,I+3),C:PUT (A-3,I),C
550 SOUND I*10,1:NEXT I:SOUND 0,0:PUT (A-3,I+3),C:IF COD=0 THEN 670
560 PLAY "MBO0L60GFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFMF"
570 PAINT (A,B),2,3:GET (0,0)-(225,165),F
580 L=0:J=5:C=1:FOR I=5 TO 40 STEP 5
590 CIRCLE (A,B),I,2:IF K=1 THEN FOR V=1 TO 100:NEXT V:COLOR C:C=C+1
600 L=L+1:IF L>=5 THEN GOSUB 620
610 NEXT I
620 CIRCLE (A,B),J,0
630 J=J+5:IF I<45 THEN RETURN
640 IF J<45 THEN GOTO 620
650 COLOR 0:LOCATE 22,4:IF K=1 THEN PRINT A$(COD);" COULE!" ELSE PRINT "TOUCHE"
660 FOR I=1 TO 5:IF MM(I)<>-W(I) THEN 700 ELSE NEXT I:GOTO 910
670 PAINT (A,B),1,3:GET (0,0)-(225,165),F
680 LOCATE 22,4:PRINT "MANQUE..."
690 REM --------------SUITE------------
700 R$=INPUT$(1):CLS:PUT (0,0),E:IF AL<>0 THEN 3200
705 FOR I=1 TO 5:IF M(I)<>W(I) AND M(I)<>-W(I) AND M(I)<>0 THEN X1=X(PBL):Y1=Y(PBL):PBL=PBL-1:AL=1:GOTO 3200
706 NEXT I
710 X=INT(RND*20+1):Y=INT(RND*15+1):IF T(X,Y)=8 THEN 710
715 COD=FIX(T(X,Y)):IF COD<>0 THEN AL=1:X1=X:Y1=Y:COD1=COD
720 A=X*10+16:B=Y*10-4
730 COD=FIX(T(X,Y)):PUT (A-3,169),C:T(X,Y)=8
735 K=0:IF COD<>0 THEN M(COD)=M(COD)-1:IF M(COD)=0 OR M(COD)=-W(COD) THEN K=1:AL=0
740 FOR I=166 TO B STEP -3:PUT (A-3,I+3),C:PUT (A-3,I),C
750 SOUND I*10,1:NEXT I:SOUND 0,0:PUT (A-3,I+3),C:IF COD=0 THEN 870
760 PLAY "MBO0L60GFGFGFGFGFGFGFGFGFGFGFGFGFGFGFGFMF"
770 CIRCLE (A,B),2,3:PAINT (A,B),2,3:GET (0,0)-(225,165),E
780 L=0:J=5:C=1:FOR I=5 TO 40 STEP 5
790 CIRCLE (A,B),I,2:IF K=1 THEN FOR V=1 TO 100:NEXT V:COLOR C:C=C+1
800 L=L+1:IF L>=5 THEN GOSUB 820
810 NEXT I
820 CIRCLE (A,B),J,0
830 J=J+5:IF I<45 THEN RETURN
840 IF J<45 THEN GOTO 820
850 COLOR 0:LOCATE 22,4:IF K=1 THEN PRINT A$(COD);" COULE!" ELSE PRINT "TOUCHE"
860 FOR I=1 TO 5:IF M(I)<>-W(I) THEN 885 ELSE NEXT I:GOTO 920
870 PAINT (A,B),1,3:GET (0,0)-(225,165),E
880 LOCATE 22,4:PRINT "MANQUE..."
885 R$=INKEY$:IF R$<>"" THEN 890
886 IF AL<>0 THEN CIRCLE (300,20),15,2:PAINT (300,20),2:FOR I=50 TO 400 STEP 12:SOUND I,.5:NEXT I:PAINT (300,20),0,0
887 GOTO 885
890 CLS:PUT (0,0),F:GOTO 500
900 REM ---------------FIN---------------
910 LOCATE 22,4:PRINT "BRAVO! TU AS GAGNE!":END
920 LOCATE 22,4:PRINT "HA HA HA! J'AI GAGNE!":END
999 REM ----------DESSIN DES BATEAUX-----------
1000 COD=VAL(LEFT$(STR$(T(I,J)),2)):D=VAL(RIGHT$(STR$(T(I,J)),1))
1010 P=9:V=1:Y=I*10+12:X=J*10-4:IF COD=1 OR COD=4 THEN X=X-4 ELSE X=X-5
1020 IF COD=1 THEN O=49 ELSE IF COD=2 THEN O=29 ELSE IF COD=3 THEN O=39 ELSE IF COD=4 THEN O=29 ELSE O=19
1030 IF COD=1 THEN RESTORE 4000 ELSE IF COD=2 THEN RESTORE 4100 ELSE IF COD=3 THEN RESTORE 4220 ELSE IF COD=4 THEN RESTORE 4160 ELSE RESTORE 4290
1040 IF D=1 THEN 1100
1050 Y=Y+O:FOR L=Y TO Y-O STEP -1:READ C$
1060 FOR K=X TO X+P:C=VAL(MID$(C$,V,1)):PSET (L,K),C:V=V+1:NEXT K:V=1:
1070 NEXT L:RETURN
1100 FOR K=X TO X+O:READ C$
1110 FOR L=Y TO Y+P:C=VAL(MID$(C$,V,1)):PSET (L,K),C:V=V+1:NEXT L:V=1
1120 NEXT K:RETURN
1500 X=INT(RND*20+1):Y=INT(RND*15+1):IF TT(X,Y)<>0 THEN 1500
1510 D=INT(RND*2+1):IF D=2 THEN 1570
1520 IF Y+L-1>15 THEN 1500
1530 FOR I=Y TO Y+L-1:TT(X,I)=TT(X,I)+COD:NEXT I
1540 FOR I=Y TO Y+L-1:IF TT(X,I)<>COD THEN 1560
1550 NEXT I:RETURN
1560 FOR I=Y TO Y+L-1:TT(X,I)=TT(X,I)-COD:NEXT I:GOTO 1500
1570 IF X+L-1>20 THEN 1500
1580 FOR J=X TO X+L-1:TT(J,Y)=TT(J,Y)+COD:NEXT J
1590 FOR J=X TO X+L-1:IF TT(J,Y)<>COD THEN 1610
1600 NEXT J:RETURN
1610 FOR J=X TO X+L-1:TT(J,Y)=TT(J,Y)-COD:NEXT J:GOTO 1500
1999 REM    ---------CHANGEMENT DE DIRECTION----------
2000 IF D=2 THEN 2100
2010 IF A+L-1>20 THEN 210
2020 FOR I=B+1 TO B+L-1
2030 IF T(A,I)=COD THEN T(A,I)=0:PAINT (A*10+16,I*10-4),0,3 ELSE T(A,I)=T(A,I)-COD
2040 NEXT I
2050 FOR I=A+1 TO A+L-1
2060 T(I,B)=T(I,B)+COD:PAINT(I*10+16,B*10-4),2,3:NEXT I:D=2:GOTO 210
2100 IF B+L-1>15 THEN 210
2110 FOR I=A+1 TO A+L-1
2120 IF T(I,B)=COD THEN T(I,B)=0:PAINT (I*10+16,B*10-4),0,3 ELSE T(I,B)=T(I,B)-COD
2130 NEXT I
2140 FOR I=B+1 TO B+L-1
2150 T(A,I)=T(A,I)+COD:PAINT(A*10+16,I*10-4),2,3:NEXT I:D=1:GOTO 210
2999 REM     -------------VALIDATION--------------
3000 V=0:IF D=1 THEN 3100
3010 FOR I=A TO A+L-1:IF T(I,B)=COD THEN V=V+1
3020 NEXT I:IF V=L THEN 3060 ELSE IF V<>0 THEN BEEP:GOTO 210
3030 FOR I=A TO A+L-1:IF INT(T(I,B))<>2*COD THEN BEEP:GOTO 210
3040 NEXT I:FOR I=A TO A+L-1:T(I,B)=0:PAINT(I*10+16,B*10-4),0,3:NEXT I
3050 M(COD)=M(COD)-1:GOTO 150
3060 M(COD)=M(COD)+1:T(A,B)=T(A,B)+.2:GOTO 3160
3100 FOR I=B TO B+L-1:IF T(A,I)=COD THEN V=V+1
3110 NEXT I:IF V=L THEN 3150 ELSE IF V<>0 THEN BEEP:GOTO 210
3120 FOR I=B TO B+L-1:IF INT(T(A,I))<>2*COD THEN BEEP:GOTO 210
3130 NEXT I:FOR I=B TO B+L-1:T(A,I)=0:PAINT(A*10+16,I*10-4),0,3:NEXT I
3140 M(COD)=M(COD)-1:GOTO 150
3150 M(COD)=M(COD)+1:T(A,B)=T(A,B)+.1
3160 FOR I=1 TO 5:IF M(I)<>2 THEN 150 ELSE NEXT I:GOTO 400
3200 IF AL=2 THEN ON D GOTO 3340,3370,3400,3430
3205 COUP=INT(RND*4)+1
3210 ON COUP GOTO 3220,3260,3290,3320
3220 X=X1-1:Y=Y1:IF X=0 THEN 3205 ELSE IF T(X,Y)=8 THEN 3205
3230 IF T(X,Y)<>0 THEN AL=2:D=1:X2=X:Y2=Y
3240 IF FIX(T(X,Y))<>COD1 AND T(X,Y)<>0 AND T(X,Y)<>8 THEN PBL=PBL+1:X(PBL)=X:Y(PBL)=Y:LOCATE 2,32:PRINT X(PBL);Y(PBL)
3250 GOTO 720
3260 X=X1+1:Y=Y1:IF X=21 THEN 3205 ELSE IF T(X,Y)=8 THEN 3205
3270 IF T(X,Y)<>0 THEN AL=2:D=2:X2=X:Y2=Y
3280 GOTO 3240
3290 X=X1:Y=Y1-1:IF Y=0 THEN 3205 ELSE IF T(X,Y)=8 THEN 3205
3300 IF T(X,Y)<>0 THEN AL=2:D=3:X2=X:Y2=Y
3310 GOTO 3240
3320 X=X1:Y=Y1+1:IF Y=16 THEN 3205 ELSE IF T(X,Y)=8 THEN 3205
3330 IF T(X,Y)<>0 THEN AL=2:D=4:X2=X:Y2=Y
3331 GOTO 3240
3335 REM ---------------------------------------------------------
3340 X2=X2-1:X=X2:Y=Y2:IF X=0 THEN F=1:X2=X1:D=2:GOTO 3370 ELSE IF T(X,Y)=8 THEN F=1:X2=X1:D=2:GOTO 3370
3350 IF T(X,Y)=0 THEN D=2:X2=X1
3360 GOTO 3240
3370 X2=X2+1:X=X2:Y=Y2:IF X=21 THEN 3460 ELSE IF T(X,Y)=8 THEN 3460
3380 IF T(X,Y)=0 THEN D=1:X2=X1
3390 GOTO 3240
3400 Y2=Y2-1:Y=Y2:X=X2:IF Y=0 THEN F=1:Y2=Y1:D=4:GOTO 3430 ELSE IF T(X,Y)=8 THEN F=1:Y2=Y1:D=4:GOTO 3430
3410 IF T(X,Y)=0 THEN D=4:Y2=Y1
3420 GOTO 3240
3430 Y2=Y2+1:Y=Y2:X=X2:IF Y=16 THEN 3470 ELSE IF T(X,Y)=8 THEN 3470
3440 IF T(X,Y)=0 THEN D=3:Y2=Y1
3450 GOTO 3240
3460 IF F=1 THEN AL=1:F=0:GOTO 3205 ELSE X2=X1:F=1:GOTO 3340
3470 IF F=1 THEN AL=1:F=0:GOTO 3205 ELSE Y2=Y1:F=1:GOTO 3400
3999 REM ----------PORTE AVION------------
4000 DATA 000001111,000001111,000011111,000011111,000111111,000111111
4010 DATA 001111111,001111111,011111111,011111111,011111111,011111111
4020 DATA 011111111,011111111,011111111,011111111,011111222,011111222
4030 DATA 011111222,011111222,011111222,011111222,011111222,011111222
4040 DATA 011111111,011111111,011111111,011111111,011111111,011111111
4050 DATA 211111111,121111111,112111111,111211111,111121111,111121111
4060 DATA 111112111,111111211,111111121,211111112,021111111,012111111
4070 DATA 011211111,011121111,011121111,011112111,011111211,011111121
4080 DATA 011111112,011111111
4090 REM ------------SOUS MARIN--------
4100 DATA 000111000,001111100,011111110,111111111,111111111,111111111
4110 DATA 111111111,111121111,111222111,112222211,112222211,112222211
4120 DATA 112222211,111222111,111222111,111121111,111111111,111111111
4130 DATA 111111111,111111111,111111111,111111111,111111111,111111111
4140 DATA 111111111,011111110,001111100,000010000,001111100
4150 REM -----------DESTROYER----------
4160 DATA 000010000,000111000,000111000,001121100,001121100,011121110,011121110
4170 DATA 111111111,122222221,121111121,121111122,121111222,121112221,221111121
4180 DATA 222111121,122211121,121111121,121111121,122222221,111111111
4190 DATA 111121111,112222211,112222211,112222211,111111111,111111111
4200 DATA 011111110,001111100,000111000
4210 REM ----------CROISEUR-----------
4220 DATA 000010000,000111000,000111000,201111102,021111120,002111200,001212100
4230 DATA 011111110,011111110,011111110,111111111,111111111,111111221,111112221
4240 DATA 111122211,111122111,122111111,122211111,112221111,111221111,111111111
4250 DATA 222111222,111111111,222111222,111111111,222111222,111111111,111111111
4260 DATA 111111111,111222111,112111211,121111121,111111111,111222111,011111110
4270 DATA 011111110,001111100,001111100,000111000,000111000
4280 REM -----------FREGATE-----------
4290 DATA 000111000,001111100,011111110,111111111,221111122,122111221,112222211
4300 DATA 111212111,112222211,122111221,221111122,211111112,111111111,111111111
4310 DATA 111121111,111222111,112212211,112222211,111111111,011111110
