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


typedef int bool;

bool verifIntel(char *,long int);
long filesize(FILE *stream);
char *mid(char *chaine, int debut, int fin);
char asciiToHex(char c);
unsigned long int HexToInt(char *string);
unsigned char CalculateChecksum(int val);
char *dasm(unsigned char high, unsigned char low);

char *usage = "Usage :\n\tReadex.exe fichier.hex\n";

// Représentation de la structure interne du pic
struct 
{
	// adresse , opcode
	unsigned char flash[1024][2];
	unsigned short int stack[8];
	unsigned short int PC;
	unsigned char filereg[256]; // contient la RAM et le SFR
	unsigned char eeprom[64];
	
	// on sépare les opérandes, si opérande il y a (à voir selon le type)
	unsigned char operands[1024][2];
	
} pic;

/* masque, opcode , code assembleur, type de code

type 1 : byte-oriented file register operations b 1 bit, f 7 bits
type 2 : byte-oriented file register operations b 3 bit, f 7 bits
type 3 : une seule opérande de 8 bits)
type 4 : goto et call seulement
type 5 : une seule opérande de 7 bits
type 6 : pas d'opérande

*/
unsigned char *opcodes[35][4]={
							 {"3F00","0700","addwf","1"},
							 {"3F00","0500","andwf","1"},
							 {"3F80","0180","clrf","5"},
							 {"3F80","0100","clrw","6"},
							 {"3F00","0900","comf","1"},
							 {"3F00","0300","decf","1"},
							 {"3F00","0B00","decfsz","1"},
							 {"3F00","0A00","incf","1"},
							 {"3F00","0F00","incfsz","1"},
							 {"3F00","0400","iorwf","1"},
							 {"3F00","0800","movf","1"},
							 {"3F80","0080","movwf","5"},
							 {"3F9F","0000","nop","6"},
							 {"3F00","0D00","rlf","1"},
							 {"3F00","0C00","rrf","1"},
							 {"3F00","0200","subwf","1"},
							 {"3F00","0E00","swapf","1"},
							 {"3F00","0600","xorwf","1"},
							 {"3C00","1000","bcf","2"},
							 {"3C00","1400","bsf","2"},
							 {"3C00","1800","btfsc","2"},
							 {"3C00","1C00","btfss","2"},
							 {"3E00","3E00","addlw","3"},
							 {"3F00","3900","andlw","3"},
							 {"3800","2000","call","4"},
							 {"3FFF","0064","clrwdt","6"},
							 {"3800","2800","goto","4"},
							 {"3F00","3800","iorlw","3"},
							 {"3C00","3000","movlw","3"},
							 {"3FFF","0009","retfie","6"},
							 {"3C00","3400","retlw","3"},
							 {"3FFF","0008","return","6"},
							 {"3FFF","0066","sleep","6"},
							 {"3E00","3C00","sublw","3"},
							 {"3F00","3A00","xorlw","3"}
							};

