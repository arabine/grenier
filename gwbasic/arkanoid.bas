10 CLS:KEY OFF:SCREEN 1:WIDTH 80:DIM R(50),B(50)
15 INPUT "AVEC BRIQUES";R$:IF R$="N" OR R$="n" THEN G=1:N=1
20 INPUT "VOULEZ-VOUS CHOISIR VOTRE ANGLE (O/N)";R$:IF R$="O"OR R$="o" THEN 310
30 CLS:RANDOMIZE TIMER:WIDTH 40
40 LINE (150,180)-(180,185),2,BF
50 LINE (50,200)-(50,0):LINE -(260,0):LINE -(260,200)
60 GET (150,180)-(180,185),R
70 XR=150:YR=180:IF G<>1 THEN GOSUB 500
80 XB=INT(RND*190)+55:YB=4
90 CIRCLE (XB,YB),4,2:PAINT(XB,YB),2
100 GET(XB-4,YB-3)-(XB+4,YB+3),B
110 DEF FNB(X,A,B)=A*X+B:XB=XB-4:YB=YB-3
120 A=RND*9+.5:B=1:C=INT(RND*2):C=C+(C=0):C=C*2:IF A<1 THEN C=C*5 ELSE IF A<3 THEN C=C*3 ELSE IF A<5 THEN C=C*2
130 R$=INPUT$(1):IF O=1 THEN A=R
140 I=1:IF N=0 THEN BEEP:N=1
150 AB=XB:BB=YB:XB=XB+C:YB=FNB(I,A,B)
160 PUT (AB,BB),B:IF G=1 THEN 170
161 IF A>0 THEN IF C>0 THEN 600 ELSE 620
162 IF C>0 THEN 640 ELSE 660
170 IF XB<=XR+26 AND XB>=XR-4 AND YB>=174 THEN YB=174:GOTO 290
180 IF YB<=1 THEN YB=1:GOTO 290
190 IF XB>=252 THEN XB=252:GOTO 280
200 IF XB<=51 THEN XB=51:GOTO 280
210 IF YB>185 THEN PLAY"L40BAGFEDCO3BAGFEDCO2BAGFEDC":GOTO 330
220 PUT (XB,YB),B
230 I=I+1:AR=XR
240 R$=INKEY$:IF R$=" " THEN 330
250 XR=XR+10*(R$="4" AND XR>50)-10*(R$="6" AND XR<230)
260 PUT (AR,YR),R:PUT (XR,YR),R
270 GOTO 150
280 SOUND 100,.1:PUT (XB,YB),B:C=-C:B=YB:GOTO 140
290 SOUND 100,.1:PUT (XB,YB),B:A=-A:B=YB:GOTO 140
310 O=1:INPUT "ANGLE (conseil:entre 0.5 et 10)";R
320 GOTO 30
330 INPUT "FIN (F) OU RECOMMENCER (R)";R$
340 IF R$="F" OR R$="f" THEN END ELSE 30
400 X=FIX((XB-42)/15)*15+50:Y=FIX((YB-47)/15)*15+50
410 LINE (X+1,Y+1)-(X+14,Y+14),0,BF:XB=X+1:RETURN
420 X=FIX((XB-46)/15)*15+50:Y=FIX((YB-44)/15)*15+50
430 LINE (X+1,Y+1)-(X+14,Y+14),0,BF:YB=Y+1:RETURN
440 X=FIX((XB-50)/15)*15+50:Y=FIX((YB-47)/15)*15+50
450 LINE (X+1,Y+1)-(X+14,Y+14),0,BF:XB=X+19:RETURN
460 X=FIX((XB-46)/15)*15+50:Y=FIX((YB-50)/15)*15+50
470 LINE (X+1,Y+1)-(X+14,Y+14),0,BF:YB=Y+19:RETURN
500 FOR I=1 TO 25
510 X=INT(RND*14+1)*15+35:Y=INT(RND*5+1)*15+35
520 IF POINT(X+2,Y+2)=1 THEN 510
530 LINE (X+1,Y+1)-(X+14,Y+14),1,BF:NEXT I
540 N=25:RETURN
600 IF POINT(XB+8,YB+3)=1 THEN GOSUB 400:N=N-1:GOTO 280
610 IF POINT(XB+4,YB+6)=1 THEN GOSUB 420:N=N-1:GOTO 290 ELSE 170
620 IF POINT(XB,YB+3)=1 THEN GOSUB 440:N=N-1:GOTO 280
630 IF POINT(XB+4,YB+6)=1 THEN GOSUB 420:N=N-1:GOTO 290 ELSE 170
640 IF POINT(XB+8,YB+3)=1 THEN GOSUB 400:N=N-1:GOTO 280
650 IF POINT(XB+4,YB)=1 THEN GOSUB 460:N=N-1:GOTO 290 ELSE 170
660 IF POINT(XB,YB+3)=1 THEN GOSUB 440:N=N-1:GOTO 280
670 IF POINT(XB+4,YB)=1 THEN GOSUB 460:N=N-1:GOTO 290 ELSE 170
