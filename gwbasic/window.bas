10 CLS:KEY OFF:SCREEN 1
20 OPEN"I",#1,"NOMS":FOR I=1 TO 10:IF EOF (1) THEN CLOSE#1:GOTO 40
30 INPUT#1,P$:P$(I)=P$:NEXT I:CLOSE#1
40 LINE (0,9)-(320,9):LINE (260,9)-(260,200)
50 PRINT "Sauver    Palette    Figures    Quitter":LOCATE 3,34:PRINT "VITESSE":LOCATE 4,35:PRINT "V=1"
60 LINE (275,40)-(305,50),1,BF:LINE (275,55)-(305,65),3,BF:LINE (275,70)-(305,80),2,BF:LINE (275,85)-(305,95),3,B
70 LOCATE 14,35:PRINT "MODE:":LINE (268,117)-(312,129),3,B:LOCATE 16,35:PRINT "LINE"
80 LOCATE 18,37:PRINT CHR$(1):LINE (284,133)-(299,146),1,B
85 LOCATE 18,35:PRINT "X":LINE (268,133)-(283,146),1,B
90 LOCATE 20,34:PRINT CHR$(17) CHR$(16);" A":LINE (284,149)-(298,161),1,B
100 N$="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890,?;.:!&'()+-<>%"+CHR$(3)+CHR$(4)+CHR$(5)+CHR$(6):N=1
110 LINE (270,35)-(311,99),3,B
120 V=1:DIM C(7),DES(4000),SED(4000),LL(7):X=150:Y=72:W=X:Z=Y:C=3:FOND=0:GO=4:M=0
130 LOCATE 10,20:PRINT CHR$(127):GET (150,72)-(158,80),C:M=0
140 R$=RIGHT$(INKEY$,1)
150 IF R$="+" AND V<30 THEN V=V+1:LOCATE 4,37:PRINT "  ":LOCATE 4,37:WRITE V ELSE IF R$="-" AND V>1 THEN V=V-1:LOCATE 4,37:PRINT "  ":LOCATE 4,37:WRITE V
160 IF R$=" " AND Y>9 AND X<260 THEN PSET (X+5,Y),C ELSE IF R$=CHR$(13) THEN 230
170 IF R$="D" OR R$="d" OR R$="F" OR R$="f" THEN 610
180 IF R$="8" OR R$="H" THEN Y=Y-V ELSE IF R$="2" OR R$="P" THEN Y=Y+V ELSE IF R$="4" OR R$="K" THEN X=X-V ELSE IF R$="6" OR R$="M" THEN X=X+V ELSE 140
190 IF X<1 THEN X=1 ELSE IF X>310 THEN X=310
200 IF Y<1 THEN Y=1 ELSE IF Y>191 THEN Y=191
210 PUT (W,Z),C:PUT (X,Y),C:W=X:Z=Y:IF M=1 THEN 220 ELSE 140
220 LOCATE 22,34:PRINT "X=   ":LOCATE 22,36:WRITE X+5:LOCATE 23,34:PRINT "Y=   ":LOCATE 23,36:WRITE Y:GOTO 140
230 IF Y<9 THEN 240 ELSE IF X>255 THEN 830 ELSE 140
240 IF X<64 THEN 260 ELSE IF X<160 THEN 350 ELSE IF X<240 THEN 480 ELSE 750
250 REM ----------SAUVEGARDE---------
260 LG=2:LH=11:LD=105:LB=170:GET (1,1)-(110,175),DES:LINE (LG,LH)-(LD,LB),0,BF:LINE (LG,LH)-(LD,LB),1,B
270 LOCATE 3,2:PRINT "QUITTER":LOCATE 5,2:PRINT "SAUVER:":LOCATE 6,2:PRINT "Cadre (D/F)":LOCATE 7,2:PRINT "Tout l'ecran":LOCATE 9,2:PRINT "CHARGER:":LOCATE 21,2:PRINT "EFFACER"
280 FOR I=1 TO 10:LOCATE I+9,2:PRINT "-";P$(I):NEXT I
290 XX=80:WW=XX:YY=15:ZZ=YY:PUT (XX,YY),C:GOSUB 1200
300 IF YY<32 THEN PUT (1,1),DES,PSET:GOTO 140
310 IF YY<54 THEN GO=1:PUT (1,1),DES,PSET:LOCATE 16,35:PRINT"SAVE ":GOTO 140
320 IF YY<60 THEN 1100
330 IF YY>155 THEN GOSUB 1300:GOSUB 1200:GOTO 300
335 IF KI=1 THEN 1320 ELSE 1150
340 REM ----------PALETTE--------
350 GET (60,1)-(140,80),DES:XX=115:YY=29:WW=XX:ZZ=YY
360 LG=67:LH=11:LB=76:LD=132:LINE (LG,LH)-(LD,LB),0,BF:LINE (LG,LH)-(LD,LB),1,B
370 LOCATE 3,10:PRINT "QUITTER":LOCATE 5,10:PRINT "FOND":LOCATE 7,10:PRINT "PEINDRE":LOCATE 9,10:PRINT "X ET Y":PUT (XX,YY),C
380 GOSUB 1200
390 IF YY>62 THEN 450
400 IF YY>36 THEN GO=2:LOCATE 16,35:PRINT"PAINT":GOTO 380
410 IF YY<28 THEN PUT (60,1),DES,PSET:GOTO 140
420 FOND=FOND+1
430 IF FOND=16 THEN FOND=0
440 COLOR FOND:GOTO 380
450 IF M=1 THEN LOCATE 22,34:PRINT "     ":LOCATE 23,34:PRINT "     ":M=0:GOTO 380
460 LOCATE 22,34:PRINT "X=":LOCATE 23,34:PRINT "Y=":M=1:GOTO 380
470 REM ---------FIGURES---------
480 GET(155,1)-(240,125),DES:LG=156:LH=11:LD=235:LB=120:XX=210:WW=XX:YY=32:ZZ=YY
490 LINE (LG,LH)-(LD,LB),0,BF:LINE (LG,LH)-(LD,LB),1,B:A=5:B=5:AA=A:BB=B
500 LOCATE 3,21:PRINT "RECTANGLE":LOCATE 5,21:PRINT "LIGNE":LOCATE 7,21:PRINT "CERCLE":LOCATE 9,21:PRINT "ELLIPSE:":LOCATE 10,23:PRINT "+ / -"
510 CIRCLE (196,98),15,3,,,A/B
520 PUT (XX,YY),C
530 GOSUB 1200
540 IF YY<28 THEN GO=3:LOCATE 16,35:PRINT "RECT " ELSE IF YY<44 THEN GO=4:LOCATE 16,35:PRINT "LINE " ELSE IF YY<56 THEN GO=5:LOCATE 16,35:PRINT "ROND " ELSE 590
550 PUT (155,1),DES,PSET:GOTO 140
560 IF YY>88 THEN 530
570 IF XX<196 AND B=5 THEN A=A+1 ELSE IF XX<196 THEN B=B-1 ELSE IF XX>196 AND A=5 THEN B=B+1 ELSE A=A-1
580 CIRCLE (196,98),15,0,,,AA/BB:CIRCLE (196,98),15,3,,,A/B:AA=A:BB=B:GOTO 530
590 IF YY<72 THEN GO=6:LOCATE 16,35:PRINT "ELLI " :GOTO 550 ELSE 560
600 REM ----------DESSIN--------
610 IF R$="D" OR R$="d" THEN O=X+5:P=Y:GOTO 140
620 IF Y<10 OR X>254 THEN 140
630 IF GO=2 THEN PUT (X,Y),C:VIEW SCREEN (1,10)-(259,199):PAINT (X+5,Y),C,C:VIEW:PUT (X,Y),C:GOTO 140
640 IF GO=3 THEN PUT (X,Y),C:VIEW SCREEN (1,10)-(259,199):LINE (O,P)-(X+5,Y),C,B:VIEW:PUT (X,Y),C:GOTO 140
650 IF GO=4 THEN PUT (X,Y),C:VIEW SCREEN (1,10)-(259,199):LINE (O,P)-(X+5,Y),C:VIEW:PUT (X,Y),C:GOTO 140
660 RAY=SQR((X+4-O)^2+(Y-P)^2):IF GO=5 THEN PUT (X,Y),C:VIEW SCREEN (1,10)-(259,199):CIRCLE (O,P),RAY,C:VIEW:PUT (X,Y),C:GOTO 140
670 IF O-X-5=0 THEN RAY=ABS(Y-P) ELSE IF P-Y=0 THEN RAY=ABS(X+4-O) ELSE RAY=0
680 IF GO=6 THEN PUT (X,Y),C:VIEW SCREEN (1,10)-(259,199):CIRCLE (O,P),RAY,C,,,A/B:VIEW:PUT (X,Y),C:GOTO 140
690 FOR I=1 TO 10:IF P$(I)="" THEN 710
700 NEXT I:BEEP:GOTO 140
710 GET (O,P)-(X+4,Y),DES:GET (0,0)-(319,199),SED:LOCATE 10,1:INPUT "NOM";P$
720 CLS:PUT (O,P),DES:DEF SEG=&HB800:BSAVE P$,0,16384:P$(I)=P$
730 OPEN "A",#1,"NOMS":PRINT#1,P$:CLOSE#1:PUT (0,0),SED,PSET:GOTO 140
740 REM----------QUITTER-------
750 GET (230,1)-(310,80),DES:LH=11:LG=251:LB=76:LD=305:XX=290:YY=25:WW=XX:ZZ=YY
760 LINE (LG,LH)-(LD,LB),0,BF:LINE (LG,LH)-(LD,LB),1,B
770 LOCATE 3,33:PRINT "ANNULE":LOCATE 5,33:PRINT "FIN":LOCATE 7,33:PRINT "BASIC":LOCATE 9,33:PRINT "MS-DOS":PUT (XX,YY),C
780 GOSUB 1200
790 IF YY<28 THEN PUT (230,1),DES,PSET:GOTO 140 ELSE IF YY<44 THEN END ELSE IF YY<56 THEN WIDTH 80:SCREEN 0:KEY ON:END
800 LOCATE 9,33:INPUT "O/N";R$:IF R$="N" THEN PUT (230,1),DES,PSET:GOTO 140
810 IF R$="O" THEN SYSTEM ELSE 800
820 REM----------OPTIONS-------
830 IF Y<55 THEN C=1 ELSE IF Y<70 THEN C=3 ELSE IF Y<85 THEN C=2 ELSE IF Y<100 THEN C=0 ELSE 850
840 LINE (270,35)-(311,99),C,B:GOTO 140
850 IF Y>132 AND Y<148 THEN IF X>278 THEN LOCATE 16,35:PRINT "GOMME":GOTO 990 ELSE LOCATE 16,35:PRINT "CADRE":GOTO 1400
860 IF X<266 THEN N=N-1:IF N=0 THEN N=82
870 IF X>266 AND X+5<280 THEN N=N+1:IF N=83 THEN N=1
880 IF X>275 THEN 900
890 B$=MID$(N$,N,1):LOCATE 20,37:PRINT B$:GOTO 140
900 PUT (X,Y),C:GET (288,152)-(296,160),LL
910 LX=250:LY=150:LW=LX:LZ=LY
920 PUT (LX,LY),LL
930 R$=INKEY$:IF R$=" " THEN PUT (X,Y),C:GOTO 140
940 IF R$="+" AND V<30 THEN V=V+1:LOCATE 4,37:PRINT "  ":LOCATE 4,37:WRITE V ELSE IF R$="-" AND V>1 THEN V=V-1:LOCATE 4,37:PRINT "  ":LOCATE 4,37:WRITE V
950 IF R$="4" THEN LX=LX-V ELSE IF R$="6" THEN LX=LX+V ELSE IF R$="8" THEN LY=LY-V ELSE IF R$="2" THEN LY=LY+V ELSE 930
960 IF LX<1 THEN LX=1 ELSE IF LX>253 THEN LX=253
970 IF LY<11 THEN LY=11 ELSE IF LY>191 THEN LY=191
980 PUT (LW,LZ),LL:PUT (LX,LY),LL:LW=LX:LZ=LY:GOTO 930
990 R$=INKEY$
1000 IF R$="+" AND V<30 THEN V=V+1:LOCATE 4,37:PRINT "  ":LOCATE 4,37:WRITE V ELSE IF R$="-" AND V>1 THEN V=V-1:LOCATE 4,37:PRINT "  ":LOCATE 4,37:WRITE V
1010 IF R$=" " AND Y>9 AND X<252 THEN PUT (X ,Y),C,PSET ELSE IF R$=CHR$(13) THEN 1060
1020 IF R$="8" THEN Y=Y-V ELSE IF R$="2" THEN Y=Y+V ELSE IF R$="4" THEN X=X-V ELSE IF R$="6" THEN X=X+V ELSE 990
1030 IF X<1 THEN X=1 ELSE IF X>310 THEN X=310
1040 IF Y<1 THEN Y=1 ELSE IF Y>191 THEN Y=191
1050 PUT (W,Z),C:PUT (X,Y),C:W=X:Z=Y:GOTO 990
1060 IF Y>132 AND Y<148 AND X>255 THEN 1070 ELSE 990
1070 LOCATE 16,35:IF GO=1 THEN PRINT "SAVE " ELSE IF GO=2 THEN PRINT "PAINT" ELSE IF GO=3 THEN PRINT "RECT " ELSE IF GO=4 THEN PRINT "LINE " ELSE IF GO=5 THEN PRINT "ROND " ELSE PRINT "ELLI "
1080 GOTO 140
1090 REM -------TOUT L'ECRAN-------
1100 FOR I=1 TO 10:IF P$(I)="" THEN 1120
1110 NEXT I:BEEP:GOTO 1200
1120 LOCATE 8,2:INPUT P$:OPEN "A",#1,"NOMS":PRINT#1,P$:CLOSE#1:P$(I)=P$
1130 PUT (1,1),DES,PSET:GET (0,0)-(319,199),SED:GET (0,10)-(259,199),DES:CLS
1140 PUT (0,10),DES:DEF SEG=&HB800:BSAVE P$(I),0,16384:PUT (0,0),SED,PSET:GOTO 140
1150 L=FIX((YY-72)/8)+1:IF P$(L)="" THEN 1180
1160 PUT (1,1),DES,PSET:GET (0,0)-(319,199),SED:DEF SEG=&HB800:BLOAD P$(L),0:GET (0,10)-(259,199),DES
1170 PUT (0,0),SED,PSET:PUT (0,10),DES,PSET:GOTO 140
1180 BEEP:GOSUB 1200:GOTO 300
1190 '------------SOUS PROGRAMME------------
1200 R$=INKEY$
1210 IF R$=CHR$(13) THEN RETURN
1220 IF R$="8" THEN YY=YY-5 ELSE IF R$="2" THEN YY=YY+5 ELSE IF R$="4" THEN XX=XX-5 ELSE IF R$="6" THEN XX=XX+5 ELSE 1200
1230 IF XX<LG THEN XX=LG ELSE IF XX>LD-10 THEN XX=LD-10
1240 IF YY<12 THEN YY=12 ELSE IF YY>LB-10 THEN YY=LB-10
1250 PUT (WW,ZZ),C:PUT (XX,YY),C:WW=XX:ZZ=YY:GOTO 1200
1300 IF KI=0 THEN KI=1:SOUND 300,.02:RETURN
1310 KI=0:SOUND 0,0:RETURN
1320 L=FIX((YY-72)/8)+1:IF P$(L)="" THEN 1360
1330 PUT (XX,YY),C:LOCATE 9+L:PRINT "          ":PUT (XX,YY),C:SOUND 0,0
1340 PP$=P$(L)+".BAS":KILL PP$:P$(L)=""
1350 OPEN "O",#1,"NOMS":FOR I=1 TO 10:IF P$(I)<>"" THEN P$=P$(I):PRINT#1,P$
1355 NEXT I:CLOSE#1
1360 GOSUB 1200:GOTO 300
1400 R$=INKEY$
1405 IF R$="+" AND V<30 THEN V=V+1:LOCATE 4,37:PRINT "  ":LOCATE 4,37:WRITE V ELSE IF R$="-" AND V>1 THEN V=V-1:LOCATE 4,37:PRINT "  ":LOCATE 4,37:WRITE V
1410 IF R$=" " AND Y>9 AND X<252 THEN IF ZAP=1 THEN PUT (X,Y),C:GOTO 1500 ELSE ZAP=1:O=X+5:P=Y
1415 IF R$=CHR$(13) THEN 1460
1420 IF R$="8" THEN Y=Y-V ELSE IF R$="2" THEN Y=Y+V ELSE IF R$="4" THEN X=X-V ELSE IF R$="6" THEN X=X+V ELSE 1400
1430 IF X<1 THEN X=1 ELSE IF X>310 THEN X=310
1440 IF Y<1 THEN Y=1 ELSE IF Y>191 THEN Y=191
1450 PUT (W,Z),C:PUT (X,Y),C:W=X:Z=Y:GOTO 1400
1460 IF Y>132 AND Y<148 AND X>255 THEN 1470 ELSE 1400
1470 LOCATE 16,35:IF GO=1 THEN PRINT "SAVE " ELSE IF GO=2 THEN PRINT "PAINT" ELSE IF GO=3 THEN PRINT "RECT " ELSE IF GO=4 THEN PRINT "LINE " ELSE IF GO=5 THEN PRINT "ROND " ELSE PRINT "ELLI "
1480 GOTO 140
1500 DIFX=ABS(X+5-O):DIFY=ABS(Y-P):GET (O,P)-(X+5,Y),DES:X=O:Y=P:W=X:Z=Y
1510 R$=INKEY$
1520 IF R$=" " THEN PUT (X,Y),DES,PSET:PUT (X,Y),C:ZAP=0:GOTO 1400
1530 IF R$="8" THEN Y=Y-1 ELSE IF R$="2" THEN Y=Y+1 ELSE IF R$="4" THEN X=X-1 ELSE IF R$="6" THEN X=X+1 ELSE 1510
1540 IF X<1 THEN X=1 ELSE IF X+DIFX>259 THEN X=X-1
1550 IF Y<1 THEN Y=1 ELSE IF Y+DIFY>199 THEN Y=Y-1
1560 PUT (W,Z),DES:PUT (X,Y),DES:W=X:Z=Y:GOTO 1510
