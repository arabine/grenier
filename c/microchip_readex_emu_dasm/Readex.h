#ifndef READEX_H
#define READEX_H

#include <stdio.h>

typedef int bool;

#define true 1
#define false 0

#ifdef __MSDOS__
#define SEPARATEUR {"\n"}
#elif defined(linux) || defined(__CYGWIN__)
#define SEPARATEUR {"\r"}
#elif defined(_Windows)
#define SEPARATEUR {"\n"}
#else
#define SEPARATEUR {"\n"}
#endif


/* Adresses du PIC 16F84 */

// Bank 0
#define INDF	0x00
#define TMR0	0x01
#define PCL		0x02
#define STATUS 	0x03
#define FSR		0x04
#define PORTA	0x05
#define PORTB	0x06
#define EEDATA	0x08
#define EEADR	0x09
#define PCLATH	0x0A
#define INTCON	0x0B

// Bank 1
//#define INDF		0x80
#define OPTION_REG	0x81
//#define PCL			0x82
//#define STATUS		0x83
//#define FSR			0x84
#define TRISA		0x85
#define TRISB		0x86
#define EECON1		0x88
#define EECON2		0x89

void usage(void);
void affDasm(void);

/* Variables globales */

// Représentation de la structure interne du pic
struct proc
{
	// adresse , opcode
	unsigned char flash[1024][2];
	unsigned short int stack[8];
	unsigned short int PC;
	unsigned char filereg[256]; // contient la RAM et le SFR
	unsigned char eeprom[64];
	
	// on sépare les opérandes, si opérande il y a (à voir selon le type)
	unsigned char operands[1024][2];
};

extern struct proc pic;
extern unsigned char *opcodes[35][4];
extern int mode;

/* Fonctions globales */
extern char *dasm(unsigned char , unsigned char );
extern long int filesize(FILE *);
extern char *mid(char *, int , int );
extern char asciiToHex(char );
extern unsigned long int HexToInt(char *);
extern void razPic(void);
extern void affEmu(void);

#endif
