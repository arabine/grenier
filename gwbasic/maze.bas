10 KEY OFF:SCREEN 1:CLS:RANDOMIZE TIMER:NIV=1:XO=5:YO=6
20 DIM S(4000),S1(313),S2(353),S3(313),M(4000),P(1163),L(313),F(353),R(313),T(10,10),D(5,4)
30 FOR I=1 TO 5:FOR J=0 TO 3:READ D(I,J):NEXT J,I
40 FOR J=1 TO 10:FOR I=1 TO 10:READ T(I,J):NEXT I,J:GOTO 690
50 GET (100,50)-(220,199),P:PAINT (160,100),1:GET (0,0)-(319,199),M
60 LINE (0,0)-(70,30):LINE -(250,30):LINE -(320,0)
70 PAINT (50,10):LINE (250,31)-(250,160),0:LINE -(70,160),0:LINE -(70,31),0
80 LINE -(250,31),0:LINE -(320,0),0:LINE (70,31)-(0,0),0:LINE (0,200)-(70,161),2
90 LINE -(250,161),2:LINE -(320,200),2:PAINT (100,170),2
100 LINE (0,200)-(70,161),0:LINE (250,161)-(320,200),0
110 LINE (68,163)-(252,163),0:LINE (60,167)-(260,167),0:LINE (50,173)-(270,173),0
120 LINE (36,181)-(284,181),0:LINE (16,192)-(304,192),0:LINE (32,200)-(88,161),0
130 LINE (64,200)-(106,161),0:LINE (96,200)-(124,161),0:LINE(128,200)-(142,161),0
140 LINE (160,200)-(160,161),0:LINE (192,200)-(178,161),0
150 LINE (224,200)-(196,161),0:LINE (256,200)-(214,161),0
160 LINE (288,200)-(232,161),0:GET (0,0)-(319,199),S
170 GET (27,60)-(64,184),S1:GET (127,78)-(193,160),S2:GET (256,60)-(293,184),S3
180 LINE (27,184)-(27,60),0:LINE -(64,73),0:LINE -(64,164),0:PAINT (50,100),0
190 LINE(293,184)-(293,60),0:LINE -(256,73),0:LINE -(256,164),0:PAINT(270,100),0
200 LINE(127,160)-(127,78),0:LINE -(193,78),0:LINE -(193,160),0:PAINT(160,100),0
210 GET (27,60)-(64,184),L:GET (127,78)-(193,160),F:GET (256,60)-(293,184),R
220 DATA 1,2,3,4,2,5,6,4,3,7,3,7,5,8,6,7,8,8,8,8
230 DATA 23,31,31,20,10,23,31,20,13,20,42,20,13,21,42,50,11,30,23,21,30,42,11,23,41,41,43,21,42,20,30,12,23,21,23,11,22,31,21,30,30,23,21,23,50,31,31,43,20,30,30,30,23,50,41
240 DATA 43,20,30,30,30,30,30,30,22,31,40,30,42,40,30,30,30,22,20,23,21,30,30,30,30,30,22,20,22,41,31,21,30,30,30,22,31,41,31,31,31,31,21,12,30
245 REM -------------------DEBUT------------------------
250 D=4:X=4:Y=1:A=XO:B=YO
260 R$=INKEY$:R$=RIGHT$(R$,1):IF R$="" THEN 260 ELSE IF R$=CHR$(27) THEN 1040
270 SOUND 40,.5:IF R$="H" OR R$="8" THEN 340
280 IF R$<>"K" AND R$<>"M" AND R$<>"4" AND R$<>"6" THEN 260
290 D=-(D+1+4*(D=4))*(R$="K" OR R$="4")-(D-1-4*(D=1))*(R$="M" OR R$="6")
300 Y=(Y+4+(R$="M" OR R$="6"))MOD 4:Y=(Y+4-(R$="K" OR R$="4"))MOD 4
310 PUT (27,60),S1,PSET:PUT (127,78),S2,PSET:PUT (256,60),S3,PSET
320 ON D(X,Y) GOSUB 400,410,420,430,440,450,460,470
330 GOTO 260
340 IF POINT (160,100)<>0 THEN 570
350 A=A-1*(D=3)+1*(D=1):B=B-1*(D=2)+1*(D=4):IF (B=11)+(B=0)+(A=0)+(A=11)<0 THEN 1040:' A FAIRE DANS CAS GENERAL
360 X=FIX(T(A,B)/10):Y=T(A,B)-X*10
370 Y=Y+D+4*(Y+D>3)
380 PUT (0,0),M,PSET:PUT (100,50),P,PSET:FOR I=1 TO 500:NEXT I
390 PUT (0,0),S,PSET:GOTO 320
400 RETURN
410 PUT (27,60),L,PSET:RETURN
420 PUT (127,78),F,PSET:RETURN
430 PUT (256,60),R,PSET:RETURN
440 GOSUB 410:GOSUB 420:RETURN
450 GOSUB 420:GOSUB 430:RETURN
460 GOSUB 410:GOSUB 430:RETURN
470 GOSUB 410:GOSUB 420:GOSUB 430:RETURN
475 REM -------------------IMAGE FINALE--------------------
480 BEEP:PRINT "GAGNE!":FOR I=1 TO 1000:NEXT I:CLS
490 LINE (0,0)-(320,100),1,BF:CIRCLE (220,100),30,3:PAINT (200,100),3
500 LINE (0,100)-(320,100),1:PAINT (160,150),2,1
510 Y=100:B=200:FOR X=0 TO 320 STEP 4:A=-480+4*X
520 LINE (X,Y)-(A,B),0:NEXT X
530 X=100:FOR I=0 TO 13:X=X+I
540 LINE (0,X)-(320,X),0:NEXT I
550 LOCATE 17,17:PRINT "THE END"
560 R$=INPUT$(1):END
565 REM --------------ROUTINES SPECIALES---------------
570 PUT (0,0),M,PSET:SOUND 1000,.5:PLAY"MB":GOSUB 670
580 FOR C=1 TO 77 STEP 4:V=C*2:SOUND 1300-C*15,2
590 LINE (C,0)-(C,V),0:LINE -(320-C,V),0:LINE -(320-C,0),0
600 LINE (0,200)-(C,V),0:LINE (320,200)-(320-C,V),0
610 LINE (C+1,0)-(319-C,V-1),3,BF
620 IF C=77 THEN 660
630 LINE (C,0)-(C+4,V),1,BF:LINE -(316-C,V),1:LINE -(320-C,0),1,BF
640 LINE (0,200)-(C,V),1:LINE (320,200)-(320-C,V),1
650 NEXT C
660 PLAY "MF":SOUND 40,20:FOR W=1 TO 2000:NEXT W:GOTO 390
670 FOR W=1 TO 1000:C=INT(RND*50+RND*40)+100:V=INT(RND*50+RND*40)+20
680 PSET (C,V),2:NEXT W:RETURN
685 REM                    *   *   *
690 X=20:Y=70
700 FOR J=1 TO 4:PSET (X,Y),0:FOR I=4 TO 60 STEP 4:A=2
710 ON J GOSUB 740,750,760,770
720 A=0:ON J GOSUB 740,750,760,770:NEXT I:SOUND 50,.5
730 A=2:ON J GOSUB 740,750,760,790:PAINT (X+5,Y+50),2:X=X+70:NEXT J:END
740 DRAW"S=I;C=A;D4;R1;U3;F1;E1;D3;R1;U4;L1;G1;H1;L1":RETURN
750 DRAW"S=I;C=A;BD1;D3;R1;U1;R2;D1;R1;U3;H1;L2;G1;BR1;R2;D1;L2;U1;BH1":RETURN
760 DRAW"S=I;C=A;R4;D1;M-3,+2;R3;D1;L4;U1;M+3,-2;L3;U1":RETURN
770 IF I=52 THEN 730
780 DRAW"S=I;C=A;D5;R4;U1;L3;U1;R1;U1;L1;U1;R3;U1;L4":RETURN
790 DRAW"S52;C2;D5;R4;U1;L3;U1;R1;U1;L1;U1;R3;U1;L4"
800 PAINT (X+5,Y+50),2:LINE (230,135)-(282,135),0
810 FOR I=20 TO 282:PSET (I,136),1:SOUND 3500-I*10,.1:NEXT I
820 A=INT(RND*50+60):B=INT(RND*50+60):X=12
830 LOCATE 20,1:PRINT A;"+";B;"=?":TIME$="00:00":K$=""
840 T=VAL(RIGHT$(TIME$,1)):LOCATE 20,30:PRINT 5-T:IF T=5 THEN 860
850 R$=RIGHT$ (INKEY$,1):IF R$<>"" THEN LOCATE 20,X:PRINT R$:X=X+1:K$=K$+R$:GOTO 840 ELSE 840
860 IF VAL(K$)<>A+B THEN CLS:GOTO 50
870 BEEP:CLS:PAINT (160,100),1
880 D$="S7;C0;M+8,-4;M+8,+4;M-8,+4;M-8,-4;M+4,+2;M+4,-2;U4;D4;M+4,+2"
890 A=-14:B=87:FOR J=1 TO 10:A=A+16:B=B+8
900 FOR I=0 TO 9:X=A+16*I:Y=B-8*I:PSET (X,Y),0:DRAW D$:LINE (X+14,Y-8)-(X+30,Y),3:LINE -(X+14,Y+8),3:PAINT (X+14,Y+4),2,0
910 II=FIX(T(I+1,J)/10):JJ=T(I+1,J)-II*10
920 ON D(II,JJ) GOSUB 1000,1000,1010,1020,1010,1030,1020,1030
925 NEXT I,J:IF NIV>1 THEN 940
930 PSET (311,109),0:DRAW"S4;C0;U5;M+3,-2;D5"
940 LINE (160,16)-(1,95):LINE-(160,175):LINE (0,96)-(160,176),0:LINE -(323,95),0:LINE -(159,14),0:LINE (159,15)-(0,95),0
950 LINE -(0,104),0:LINE-(160,185),0:LINE-(323,104),0:LINE (160,185)-(160,176),0
960 PAINT (10,10),0:PAINT (10,180),0:PSET (161,15):PSET (319,95)
970 IF NIV=1 THEN PAINT (312,104),0
975 XC=XO*16+(YO-1)*16:YC=YO*8+99-8*XO:CIRCLE(XC,YC),2,3:PAINT(XC,YC),3:LINE -(50,160)
980 LOCATE 21,2:PRINT "VOUS ETES":LOCATE 22,5:PRINT "ICI"
990 R$=INPUT$(1):CLS:GOTO 50
1000 RETURN
1010 PSET (X+6,Y+3),0:DRAW"S4;C0;U3;M+3,-2;D3":PAINT (X+7,Y+2),0:RETURN
1020 PSET (X+18,Y+1),0:DRAW"S4;C0;U3;M+3,+2;D3":PAINT (X+20,Y+1),0:RETURN
1030 GOSUB 1010:GOSUB 1020:RETURN
1040 REM ----------------NIVEAUX RAJOUTES------------------
1050 BEEP:NIV=NIV+1:IF NIV>2 THEN 480 ELSE ON NIV GOSUB 1100
1060 CLS:PRINT "NIVEAU";NIV:R$=INPUT$(1):GOTO 40
1100 RESTORE 2000:XO=6:YO=5:RETURN
2000 DATA 10,23,33,33,33,43,33,43,33,20,32,32,23,33,20,22,20,12,10,12,32,22,41,43,21,10,22,33,41,20,42,33,20,32,23,50,11,13,20,32,32,13,40,32,22,50,43,20,32,22
2010 DATA 42,11,22,50,20,42,50,40,42,11,32,23,20,22,21,32,42,21,32,10,42,21,22,20,13,41,40,22,40,32,42,33,33,41,43,33,21,42,41,21,22,33,33,33,41,33,33,41,33,11
