        list      p=16F84             ; Type du processeur
        #include  <p16F84.inc>        ; Définition des variables

; Configuration word ( Accessible uniquement lors de la programmation )
;       Pas de code protégé.
;       Délai de démarrage.
;       Watchdog timer désactivé.
;       Type d'oscillateur HS  (Fréquence du quartz 20 Mhz).

        __CONFIG   _CP_OFF & _PWRTE_ON & _WDT_OFF & _HS_OSC

;******************************************************************************
;
;        Déclaration des variables et constantes
;        Zone mémoire utilisable compris entre 0x0C et 0x4F (68 octets)
;
;******************************************************************************
; Affectation des ports du pic :
;
; Port | Broche | Type      | Valeur Initiale | Nom      | Description
;
; RA0  |     17 |           |                 |          | 
; RA1  |     18 |           |                 |          | 
; RA2  |      1 |           |                 |          | 
; RA3  |      2 |           |                 |          | 
; RA4  |      3 |           |                 |          | 
;
; RB0  |      6 | Sortie    | Etat haut       | PortB0   | 
; RB1  |      7 |           |                 |          | 
; RB2  |      8 |           |                 |          | 
; RB3  |      9 |           |                 |          | 
; RB4  |     10 |           |                 |          | 
; RB5  |     11 |           |                 |          | 
; RB6  |     12 |           |                 |          | 
; RB7  |     13 |           |                 |          | 
;  Avec résistance Pull-Ups qui force le niveau haut pour des ports RB1 RB2 RB3 RB4 RB5 RB6 RB7
;   qui ne seraient pas reliés ou en haute impédance.
;
;******************************************************************************
;
PortB0                EQU     0                ; Sortie 
;
;******************************************************************************
;
;    Vecteur reset
;
;******************************************************************************
                ORG     0x000

                CALL    Init                      ; Initialisation processeur
                GOTO    Main                      ; Début du programme

;******************************************************************************
;
;    Vecteur interruption
;
;******************************************************************************

                ORG     0x004
                RETFIE                           ; return après l'interruption

;******************************************************************************
;
;    Initialisation
;
;******************************************************************************
Init
        CLRF    TMR0                         ; Initialisation du compteur

        CLRF    PORTA                  ; Initialisation port A
        MOVLW   B'00000001'                  ; Initialisation port B
        MOVWF   PORTB

        BSF     STATUS, RP0                  ; Bank 1 sélectionnée

        MOVLW   B'11111110'
        MOVWF   TRISB
        ; pull-ups activé, TMR0 sur timer, Prescaler sur TMR0, Prescaler/256
        MOVLW   B'01010111'
        MOVWF   OPTION_REG

        BCF     STATUS, RP0                  ; Bank 0 sélectionnée

        RETURN


;******************************************************************************
;
;    Programme Main
;    Exécuté au démarrage du processeur ou lors d'un reset ( broche MCLR )
;
; TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
;   A FAIRE A FAIRE A FAIRE A FAIRE A FAIRE A FAIRE A FAIRE A FAIRE A FAIRE
;******************************************************************************
Main



FinMain         GOTO    FinMain                   ; Fin du main, boucle sans fin


;******************************************************************************
;
;    Fin
;
;******************************************************************************

        END
