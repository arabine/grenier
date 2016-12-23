/**
 * Groar - utils.h
 * Some useful general purpose functions here
 */

#include "groar.h"
#include "crctable.h"

unsigned long crc_normal (unsigned char *blk_adr, unsigned long blk_len)
{
	unsigned long crc = INIT;
	while (blk_len--)
	   crc = crctable[((crc>>24) ^ *blk_adr++) & 0xFFL] ^ (crc << 8);
	return crc ^ XOROT;
}
