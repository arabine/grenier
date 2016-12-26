 	include	<p16f84.inc>

;;;;;;;;;;;;;;;;;;;;;;;;;
; Defines
;;;;;;;;;;;;;;;;;;;;;;;;;
	
RS 	EQU	 0x03; RS sur RA3
RW 	EQU	 0x00
E  	EQU	 0x02
DCF	EQU	 0x01

;;;;;;;;;;;;;;;;;;;;;;;;;
; Variables
;;;;;;;;;;;;;;;;;;;;;;;;;

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
VAR3		EQU	0x1B
Cpt_test	EQU	0x1C
Res_Mi		EQU	0x1E
Res_He		EQU	0x1F

Min_Msb		EQU	0x20
Min_Lsb		EQU	0x21
Heu_Msb		EQU	0x22
Heu_Lsb		EQU	0x23
VAR4		EQU	0x24
VAR5		EQU	0x25

;;;;;;;;;;;;;;;;;;;;;;;;;
; Début du programme à l'adresse 0H
;;;;;;;;;;;;;;;;;;;;;;;;;

	org	0		 
	nop	
	goto	START

;;;;;;;;;;;;;;;;;;;;;;;;;	
; Programme principal
;;;;;;;;;;;;;;;;;;;;;;;;;

	org	0x10

;;;;;;;;;;;;;;;;;;;;;;;;;
; void main ( void )
;;;;;;;;;;;;;;;;;;;;;;;;;

START:

	; configurations des ports
	clrf	PORTA
	bsf	STATUS,RP0	;met en bank 1
	;movlw	0x7F
	;movwf	OPTION_REG	; Port B avec résistances de pull up p.15
	clrf	TRISB		; PORT B en sortie
	
	movlw	0x02
	movwf	TRISA		; PORT A en sortie sauf RA2
	bcf	STATUS,RP0	; met en bank 0 pour utiliser le port A physiqmt

	call INIT
	clrf	VAR3
	clrf	VAR4
	clrf	VAR5

	clrf	Heu_Msb
	clrf	Heu_Lsb
	clrf	Min_Msb
	clrf	Min_Lsb



	movlw	0X49		;affichage de "Init"
	call	PUTCHAR
	call 	TEST_BUSY
	movlw	0X4E
	call	PUTCHAR
	call 	TEST_BUSY
	movlw	0X49
	call	PUTCHAR
	call 	TEST_BUSY
	movlw	0X54
	call	PUTCHAR
	call 	TEST_BUSY
BOUCLE:

	call	CAPTURE
	call	Affichage
	goto	BOUCLE

;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN DU MAIN
;;;;;;;;;;;;;;;;;;;;;;;;;



CAPTURE:
	; lecture des données de la RAM du microcontrôleur alors (RS=1, RW=1)
	bsf	PORTA,RS
	bsf	PORTA,RW
	clrf	Cpt_Tempo
	clrf	Cpt_Bit
	clrf	Minutes
	clrf	Heures
	clrf	Tampon	
	clrf	Cpt_test
	clrf	Res_Mi
	clrf	Res_He



;******detection du début de la trame*****

Scrutation2:			;attente PortA,DCF état bas	
	clrf	Cpt_Tempo
Scrutation:
	btfsc	PORTA,DCF
	goto	Scrutation

	btfsc	VAR3,0
	call 	Affichage

Scrutation3:
	incf	Cpt_Tempo,1
	movlw	0x63
	subwf	Cpt_Tempo,0
	btfsc	STATUS,2
	goto	Suite
	movlw	0x10		;Tempo de 16 ms
	call	DELAY
	btfss	PORTA,DCF
	goto	Scrutation3
	goto 	Scrutation2
Suite:	clrf	Cpt_Tempo
	Bcf	STATUS,2
;***********fin de la détection du bit de start***



;***********Détection du 1er bit significatif******
	

	clrf 	PORTB
Scrut:				;détection état haut
	btfss	PORTA,DCF
	goto	Scrut
Scrut2:				; détection état bas
	btfsc	PORTA,DCF
	goto 	Scrut2

	btfsc	VAR4,0
	call 	Affichage

	incf	Cpt_Bit,1
	movlw	0x15		;détection du 20ème bit 
	subwf	Cpt_Bit,0
	Btfss	STATUS,2
	goto	Scrut
		
	bcf	STATUS,2


;***********Fin de la détection du 1er bit significatif******


	
;***********détection de la valeur des bits significatifs*********


Front:
	Btfsc 	PORTA,DCF		;detection d'un front montant
	goto	Front
Front_mo:
	Btfss 	PORTA,DCF
	goto	Front_mo

	btfsc	VAR5,0
	call 	Affichage

	incf	Cpt_Bit,1	
	movlw	0x50		;crée une tempo de 150 ms environ
	call	DELAY
	movlw	0x50
	call	DELAY

	btfsc	PORTA,DCF		;met à 1 ou à 0 le bit7 de tampon 
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
	clrf	Heu_Msb
	clrf	Heu_Lsb
	clrf	Min_Msb
	clrf	Min_Lsb
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

	return

INIT:

	; 2) delay après la mise sous tension
	movlw	d'20'	; 20 ms
	call	DELAY

	; 3) DL = 1
	movlw	0x30	; initial reset of instruction, MEO function set
	call	CONFIG	
	
	; 4) 4,1 ms mini
	movlw	d'10'	; 10 ms
	call	DELAY
	
	; DL = 0
	movlw	0x00
	call	CONFIG	

	; 5) DL = 1
	movlw	0x30
	call	CONFIG
	
	; 6) 100 us mini
	movlw	d'1'	; 1 ms
	call	DELAY

	; DL = 0
	movlw	0x00
	call	CONFIG	

	; 7) DL = 1
	movlw	0x30
	call	CONFIG

	; 8) écran occupé ou pas?
	call 	TEST_BUSY

	; 9) config du hard : bus 8 bits, 2 lignes, digit 5*7
	movlw	0x38
	call	CONFIG	

	; 10)
	call 	TEST_BUSY

	; 11) DISPLAY MODE : Display ON, Cursor OFF, Blink OFF
	movlw	0x0C
	call	CONFIG

	; 12)	
	call 	TEST_BUSY

	; 13) CLEAR DISPLAY
	movlw	0x01
	call	CONFIG

	; 14)	
	call 	TEST_BUSY

	; 15) SHIFT MODE : incrémentation de l'adresse, sans décalage de l'écran
	;  fonction entry mode set
	movlw	0x06
	call	CONFIG

	; 16)	
	call 	TEST_BUSY

	;;;;;;;;;;;;
	; 17) INIT TERMINEE
	;;;;;;;;;;;;

	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; void CONFIG ( char Configuration )
; Cette fonction envoie un octet de configuration à l'écran
; entree : La configuration est dans l'accumulateur W
; sortie : -
; variables détruites : 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CONFIG:  			; sur un frt montant de E, lcd reçoit les instructions
	; RS=0, RW=0
	bcf	PORTA,RS
	bcf	PORTA,RW

	movwf	PORTB
	bsf	PORTA,E
	bcf	PORTA,E

	; RS=1, RW=1
	bsf	PORTA,RS
	bsf	PORTA,RW
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION CONFIG
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; void PUTCHAR ( char Caractere )
; Cette fonction affiche un caractere à l'écran
; entree : Le caractere en ASCII est dans l'accumulateur W
; sortie : -
; variables détruites : 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUTCHAR:
	; RS=1, RW=0
	bsf	PORTA,RS	; le lcd reçoit des instructions
	bcf	PORTA,RW 	; lcd lit le contenu de l'écran

	movwf	PORTB
	bsf	PORTA,E
	bcf	PORTA,E		; on baisse E pour valider la donnee

	; RS=1, RW=1
	bsf	PORTA,RS
	bsf	PORTA,RW
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION PUTCHAR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; void TEST_BUSY ( void )
; Fonction du test du Busy Flag
; Attend que l'écran est disponible
; entree : -
; sortie : -
; variables détruites : -
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

TEST_BUSY:
	
	bcf	PORTA,RS	; RS=0
	bsf	PORTA,RW	; RW=1 (lecture du statut de l'écran)
	
	; on met le port B en entrée pour pouvoir lire	
	bsf	STATUS,RP0	; banque 1
	movlw	0xFF		; 
	movwf	TRISB		; portb en entrée
	bcf	STATUS,RP0

LOOP_BF:
	bcf	PORTA,E
	nop
	nop
	bsf	PORTA,E
	nop
	nop
	btfsc   PORTB,0x07 	; test du busy flag si c'est vrai il saute l'instruction 
				; sinon il boucle
	goto	LOOP_BF
	bcf	PORTA,E

	;remise du portb en sortie0
	bsf	STATUS,RP0	;met en bank 1
	clrf	TRISB
	bcf	STATUS,RP0	; met en bank 0 pour utiliser le port A physiqmt
	
	;RS=1, RW=1
	bsf	PORTA,RS
	bsf	PORTA,RW

	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION TEST_BUSY
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Fonction de retard DELAY
; entree : temps du retard en ms dans le registre W
; sortie : -
; variables détruites : VAR, VAR2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

DELAY:
	bcf	STATUS,C	;
	movwf	VAR
	rlf	VAR,1		; multiplie W par 2

LOOP_DELAY:
	movlw	0xA5		; chargemt de 0xff ds l'accu
	movwf	VAR2		; var2=0xff
	call LOOP2_DELAY
	decfsz	VAR,1		; si var différent de 0 var=var-1
	goto LOOP_DELAY		; sinon saute l'instruction suivante
	return

LOOP2_DELAY:				; deuxieme boucle imbriquee
	decfsz	VAR2,1
	goto LOOP2_DELAY
	return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; FIN FONCTION RETARD
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


Affichage:
	
	Movlw	0x01
	Movwf	VAR3
	Movwf	VAR4
	Movwf	VAR5

	movlw	0x01		;effacement de l'afficheur
	call	CONFIG
	
	movf	Heu_Msb,0
	call	PUTCHAR
	call 	TEST_BUSY

	movf	Heu_Msb,0
	call	PUTCHAR
	call 	TEST_BUSY

	movf	Heu_Lsb,0
	call	PUTCHAR
	call 	TEST_BUSY

	movlw	0x48		;espace
	call	PUTCHAR
	call 	TEST_BUSY

	movf	Min_Msb,0
	call	PUTCHAR
	call 	TEST_BUSY

	movf	Min_Lsb,0
	call	PUTCHAR
	call 	TEST_BUSY

	Movlw	0x2E
	call	PUTCHAR
	call 	TEST_BUSY

	Movlw	0x7F
	call	DELAY
	Movlw	0x7F
	call	DELAY
	Movlw	0x7F
	call	DELAY
	Movlw	0x7F
	call	DELAY


	movlw	0x01		;effacement de l'afficheur
	call	CONFIG
	
	movf	Heu_Msb,0
	call	PUTCHAR
	call 	TEST_BUSY

	movf	Heu_Msb,0
	call	PUTCHAR
	call 	TEST_BUSY

	movf	Heu_Lsb,0
	call	PUTCHAR
	call 	TEST_BUSY

	movlw	0x48		;espace
	call	PUTCHAR
	call 	TEST_BUSY

	movf	Min_Msb,0
	call	PUTCHAR
	call 	TEST_BUSY

	movf	Min_Lsb,0
	call	PUTCHAR
	call 	TEST_BUSY
	

	return



	end
 
