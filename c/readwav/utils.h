#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mid(unsigned char *in, int taille, int debut, int fin, unsigned char *out);
unsigned long int HexToInt(char *string);
char asciiToHex(char c);
long int filesize(FILE *stream);


#endif