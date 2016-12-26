
;es.ASM : recopie les bits de poids forts sur les bits de poids faible

	list	p=16F84

	include	<p16F84.inc>	;librairie que l'on pourrait utiliser

;********Lignes de déclaration et de définition des registres****************
Minutes		EQU	0x1D
Heures		EQU	0x11
Jour_Cal	EQU	0x12
Jour_Sem	EQU	0x13
Mois		EQU	0x14
Annee		EQU	0x15
VAR		EQU 	0x16
VAR2		EQU	0x17

Cpt_Tempo	EQU	0x18
Cpt_Bit		EQU	0x19
Tampon		EQU	0x1A
var3		EQU	0x1B
Cpt_test	EQU	0x1C
Res_Mi		EQU	0x1E
Res_He		EQU	0x1F

Min_Msb		EQU	0x20
Min_Lsb		EQU	0x21
Heu_Msb		EQU	0x22
Heu_Lsb		EQU	0x23

;*************Début physique du programme à l'adresse 0H ********************
	org	0x10		 
	nop
	goto	START
	

;*********************Initialisation************

START:	bsf	STATUS,RP0	; passage en banque 1
	movlw	0x0F		;Déclaration de RA3 en entrée
	movwf	TRISA

	movlw	0x00		;Déclaration du port b en sortie
	movwf	TRISB
	
	clrf	PORTB

	bcf	STATUS,RP0	;retour banque 0
	clrf	Cpt_Tempo
	clrf	Cpt_Bit
	clrf	Minutes
	clrf	Heures
	clrf	Jour_Cal
	clrf	Mois
	clrf	Tampon	
	clrf	Cpt_test
	clrf	Jour_Sem
	clrf	Res_Mi
	clrf	Res_He
	clrf	Heu_Msb
	clrf	Heu_Lsb
	clrf	Min_Msb
	clrf	Min_Lsb

;******detection du début de la trame*****

Scrutation2:			;attente PortA,2 état bas	
	clrf	Cpt_Tempo
Scrutation:
	btfsc	PORTA,2
	goto	Scrutation

Scrutation3:
	incf	Cpt_Tempo,1
	movlw	0x63
	subwf	Cpt_Tempo,0
	btfsc	STATUS,2
	goto	Suite
	movlw	0x10		;Tempo de 16 ms
	call	DELAY
	btfss	PORTA,2
	goto	Scrutation3
	goto 	Scrutation2
Suite:	clrf	Cpt_Tempo
	Bcf	STATUS,2
;***********fin de la détection du bit de start***



;***********Détection du 1er bit significatif******
	

	clrf 	PORTB
Scrut:				;détection état haut
	btfss	PORTA,2
	goto	Scrut
Scrut2:				; détection état bas
	btfsc	PORTA,2
	goto 	Scrut2

	incf	Cpt_Bit,1
	movlw	0x15		;détection du 20ème bit 
	subwf	Cpt_Bit,0
	Btfss	STATUS,2
	goto	Scrut
		
	bcf	STATUS,2


;***********Fin de la détection du 1er bit significatif******


	
;***********détection de la valeur des bits significatifs*********


Front:
	Btfsc 	PORTA,2		;detection d'un front montant
	goto	Front
Front_mo:
	Btfss 	PORTA,2	
	goto	Front_mo

	incf	Cpt_Bit,1	
	movlw	0x50		;crée une tempo de 150 ms environ
	call	DELAY
	movlw	0x50
	call	DELAY

	btfsc	PORTA,2		;met à 1 ou à 0 le bit7 de tampon 
	goto	Suite2
	bcf	Tampon,7
	goto	Suite3
Suite2:
	bsf	Tampon,7


;***********Fin détection de la valeur des bits significatifs*********




;***Stockage des valeurs reçues***
Suite3:				;Stockage minutes
	movlw	0x1E
	subwf	Cpt_Bit,0
	btfsc	STATUS,0	;test si bit minutes
	goto	lbl_Heure

	bcf	STATUS,0	;decalage à droite de Minutes
	rrf	Minutes,1

	btfss	Tampon,7	;bit reçu appartient aux Minutes
	goto	lbl_Reset
	bsf	Minutes,7
	goto	lbl_Set
lbl_Reset:
	bcf	Minutes,7
lbl_Set:
	goto Front
lbl_Heure:			;Stockage heures
	movlw	0x24
	subwf	Cpt_Bit,0
	btfsc	STATUS,0	;test si bit heures
	goto	Traiter
	
	btfss	Tampon,7	;bit reçu appartient aux heures
	goto	lbl_Reset2
	bsf	Heures,7
	goto	lbl_Set2
lbl_Reset2:
	bcf	Heures,7
lbl_Set2:
	bcf	STATUS,0
	rrf	Heures,1

	goto 	Front
	goto	Traiter
;lbl_Jour_cal:			;Stockage jours calendaires
;	movlw	0x2A
;	subwf	Cpt_Bit,0
;	btfsc	STATUS,0	;test si bit heures
;	goto	lbl_Jour_sem
;	
;	btfss	Tampon,7	;bit reçu appartient aux heures
;	goto	lbl_Reset3
;	bsf	Jour_Cal,7
;	goto	lbl_Set3
;lbl_Reset3:
;	bcf	Jour_Cal,7
;lbl_Set3:
;	bcf	STATUS,0
;	rrf	Jour_Cal,1
;	
;	goto 	Front

;lbl_Jour_sem:

;*******Traitement****
;**Conversion des données en binaire naturel
	;*****Octet des minutes****
Traiter:
	bcf	STATUS,0
	rlf	Minutes,1	;rotation de la parité des minutes(bit à ne pas prendre en compte)

	bcf	STATUS,0
	rlf	Minutes,1	;traitement du bit de poids fort de Minutes
	
	btfss	STATUS,0
	goto	Minute_20
	movlw	d'40'
	addwf	Res_Mi,1
Minute_20:
	bcf	STATUS,0
	rlf	Minutes,1	;traitement du bit de (poids fort)-1 de Minutes
	
	btfss	STATUS,0
	goto	Minute_10
	movlw	d'20'
	addwf	Res_Mi,1
Minute_10:
	bcf	STATUS,0
	rlf	Minutes,1	;traitement du bit de (poids fort)-2 de Minutes
	
	btfss	STATUS,0
	goto	Minute_8
	movlw	d'10'
	addwf	Res_Mi,1
Minute_8:
	bcf	STATUS,0
	rlf	Minutes,1	;traitement du bit de (poids fort)-3 de Minutes
	
	btfss	STATUS,0
	goto	Minute_4
	movlw	d'8'
	addwf	Res_Mi,1
Minute_4:
	bcf	STATUS,0
	rlf	Minutes,1	;traitement du bit de (poids fort)-4 de Minutes
	
	btfss	STATUS,0
	goto	Minute_2
	movlw	d'4'
	addwf	Res_Mi,1
Minute_2:
	bcf	STATUS,0
	rlf	Minutes,1	;traitement du bit de (poids fort)-5 de Minutes
	
	btfss	STATUS,0
	goto	Minute_1
	movlw	d'2'
	addwf	Res_Mi,1
Minute_1
	bcf	STATUS,0
	rlf	Minutes,1	;traitement du bit de poids faible de Minutes
	
	btfss	STATUS,0
	goto	Heure_Par
	movlw	d'1'
	addwf	Res_Mi,1
	
	;*****octet des heures
Heure_Par:

	bcf	STATUS,0
	rlf	Heures,1	;traitement du bit de parité des heures
	
	bcf	STATUS,0
	rlf	Heures,1	;traitement de poids fort des heures
	
	btfss	STATUS,0
	goto	Heure_10
	movlw	d'20'
	addwf	Res_He,1

Heure_10:

	bcf	STATUS,0
	rlf	Heures,1	;traitement du bit de poids (fort-1)des heures
	
	btfss	STATUS,0
	goto	Heure_8
	movlw	d'10'
	addwf	Res_He,1

Heure_8:
	bcf	STATUS,0
	rlf	Heures,1	;traitement du bit de poids (fort-2) des heures
	
	btfss	STATUS,0
	goto	Heure_4
	movlw	d'8'
	addwf	Res_He,1

Heure_4:

	bcf	STATUS,0
	rlf	Heures,1	;traitement du bit de poids(fort-3)des heures
	
	btfss	STATUS,0
	goto	Heure_2
	movlw	d'4'
	addwf	Res_He,1
Heure_2:

	bcf	STATUS,0
	rlf	Heures,1	;traitement du bit de poids (fort-4) des heures
	
	btfss	STATUS,0
	goto	Heure_1
	movlw	d'2'
	addwf	Res_He,1

Heure_1:
	bcf	STATUS,0
	rlf	Heures,1	;traitement du bit de poids faible des heures
	
	btfss	STATUS,0
	goto	Conversion
	movlw	d'1'
	addwf	Res_He,1


	;*****Conversion de la valeur binaire en décimal
		;Conversion des minutes

Conversion:
		
	movlw	0x0A
	subwf	Res_Mi,0

	btfss	STATUS,0
	goto	Stock
	
	movlw	0x0A
	subwf	Res_Mi,1
	incf	Min_Msb,1
	goto	Conversion

Stock:
	movf	Res_Mi,0
	movwf	Min_Lsb

		;Conversion des Heures

Conversion2:
		
	movlw	0x0A
	subwf	Res_He,0

	btfss	STATUS,0
	goto	Stock2
	
	movlw	0x0A
	subwf	Res_He,1
	incf	Heu_Msb,1
	goto	Conversion2

Stock2:
	movf	Res_He,0
	movwf	Heu_Lsb
	
;*******Conversion ASCII
	
	movlw	0x30
	addwf	Min_Msb,1
	addwf	Min_Lsb,1
	addwf	Heu_Msb,1
	addwf	Heu_Lsb,1
 	Goto 	Decalage

;Fin_Conver:
			;Stockage jours semaines
;	movlw	0x2D
;	subwf	Cpt_Bit,0
;	btfsc	STATUS,0	;test si bit heures
;	goto	lbl_Mois
;;	
;	btfss	Tampon,7	;bit reçu appartient aux heures
;	goto	lbl_Reset4
;	bsf	Jour_Sem,7
;	goto	lbl_Set4
;lbl_Reset4:
;	bcf	Jour_Sem,7
;lbl_Set4:
;	bcf	STATUS,0
;	rrf	Jour_Sem,1
;
;	goto 	Front
;lbl_Mois:			;Stockage mois
;	movlw	0x32
;	subwf	Cpt_Bit,0
;	btfsc	STATUS,0	;test si bit mois
;	goto	lbl_Année
;
;	btfss	Tampon,7	;bit reçu appartient aux mois
;;	goto	lbl_Reset5
;;	bsf	Mois,7
;	goto	lbl_Set5
;lbl_Reset5:
;	bcf	Mois,7
;lbl_Set5:
;	bcf	STATUS,0
;	rrf	Mois,1
;
;	goto 	Front
;lbl_Année:
	
;***Fin stockage des valeurs reçues***

;*****Programme de test affichant le contenu de Minutes sur RB1

Decalage:

	bsf	PORTB,1
	nop
	nop
	nop
	nop
	nop
	nop
	bcf	PORTB,1


	incf	Cpt_test,1
	bcf	STATUS,0
	rlf	Min_Msb,1
	btfss	STATUS,0
	goto	PortB_Reset
	bsf	PORTB,1
	movlw	0x5F
	call	DELAY
	bcf	PORTB,1
	goto 	PortB_Set

PortB_Reset:
	bcf	PORTB,1
	movlw	0x5F
	call	DELAY
PortB_Set:

	movlw	0x08
	subwf	Cpt_test,0
	btfss	STATUS,2	;test si bit minutes
	goto	Decalage

;*****Programme de test affichant le contenu de Minutes sur RB1
	clrf	Cpt_test

Decalage2:

	bsf	PORTB,1
	nop
	nop
	nop
	nop
	nop
	nop
	bcf	PORTB,1


	incf	Cpt_test,1
	bcf	STATUS,0
	rlf	Min_Lsb,1
	btfss	STATUS,0
	goto	PortB_Reset2
	bsf	PORTB,1
	movlw	0x5F
	call	DELAY
	bcf	PORTB,1
	goto 	PortB_Set2

PortB_Reset2:
	bcf	PORTB,1
	movlw	0x5F
	call	DELAY
PortB_Set2:

	movlw	0x08
	subwf	Cpt_test,0
	btfss	STATUS,2	;test si bit minutes
	goto	Decalage2
;*********	
	clrf	Cpt_test

Decalage3:

	bsf	PORTB,1
	nop
	nop
	nop
	nop
	nop
	nop
	bcf	PORTB,1


	incf	Cpt_test,1
	bcf	STATUS,0
	rlf	Heu_Msb,1
	btfss	STATUS,0
	goto	PortB_Reset3
	bsf	PORTB,1
	movlw	0x5F
	call	DELAY
	bcf	PORTB,1
	goto 	PortB_Set3

PortB_Reset3:
	bcf	PORTB,1
	movlw	0x5F
	call	DELAY
PortB_Set3:

	movlw	0x08
	subwf	Cpt_test,0
	btfss	STATUS,2	;test si bit minutes
	goto	Decalage3

;*****Programme de test affichant le contenu de Minutes sur RB1
	clrf	Cpt_test

Decalage4:

	bsf	PORTB,1
	nop
	nop
	nop
	nop
	nop
	nop
	bcf	PORTB,1


	incf	Cpt_test,1
	bcf	STATUS,0
	rlf	Heu_Lsb,1
	btfss	STATUS,0
	goto	PortB_Reset4
	bsf	PORTB,1
	movlw	0x5F
	call	DELAY
	bcf	PORTB,1
	goto 	PortB_Set4

PortB_Reset4:
	bcf	PORTB,1
	movlw	0x5F
	call	DELAY
PortB_Set4:

	movlw	0x08
	subwf	Cpt_test,0
	btfss	STATUS,2	;test si bit minutes
	goto	Decalage4
	
	goto	Fin

;*****Fin programme de test affichant le contenu de Minutes sur RB1





;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Fonction de retard DELAY
; entree : temps du retard en ms dans le registre W
; sortie : -
; variables détruites : VAR, VAR2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

DELAY:
	bcf	STATUS,C
	movwf	VAR
	rlf	VAR,1		; multiplie W par 2

LOOP_DELAY:
	movlw	0xA5		; chargemt de 0xff ds l'accu
	movwf	VAR2		; var2=0xff
	call LOOP2_DELAY
	decfsz	VAR,1
	goto LOOP_DELAY
	return

LOOP2_DELAY:				; deuxieme boucle imbriquee
	decfsz	VAR2,1
	goto LOOP2_DELAY
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION RETARD
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
Fin:
	goto 	START
	end		;marque de fin de programme


;***programme de test****	







