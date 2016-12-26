/* Programme d'initiation
   PC Team 75
   Janvier 2002
*/

#define EVER ;;
#include <pic1684.h>

/* Cette variable va compter les interruptions */
unsigned char Compteur;

void main(void)
{
    Compteur = 0;    
    
    /* Bit 0 du Port B en sortie */
    TRISB=0xFE;

    /* Bit 0 du port B à zéro */
    RB0 = 0;
    
    /* Réglage des paramètres du timer TMR0
       Prescaler = 256
       Horloge interne (quartz/4)
       Soit une interruption par overflow tous les 0,01321 s
       C'est à dire environ 38 interruptions de T0IE pour avoir une demi-seconde !
       CQFD !!
    */    
    OPTION = 0x7;

    /* On configure les interruptions 
       Et on baisse le flag T0IF
    */
    INTCON = 0x20;
    
    /* RAZ du timer */
    TMR0 = 0;  
    
    /* On autorise les interruptions */
    GIE=1;
    for(EVER)
    {
    }
}

/* Interruption générale */
void interrupt Timer_Overflow(void)
{
    char i;
    if(T0IF) /* On teste la source d'interruption */
    {
        T0IF=0; /* On baisse le flag */
        Compteur++;
        if(Compteur==38)
        {
            Compteur = 0;
            i = RB0;
            RB0 = ~i;
            TMR0 = 0;
        }
    }

}
