/*******************************************************************************
 *
 * Filename: xmodem.c
 *
 * Instantiation of simple x-modem support using debug uart channel.
 *
 * Revision information:
 *
 * 22AUG2004	kb_admin	initial creation
 * 24AUG2004	kb_admin	optimize for space, not quite as elegant. . .
 *
 * BEGIN_KBDD_BLOCK
 * No warranty, expressed or implied, is included with this software.  It is
 * provided "AS IS" and no warranty of any kind including statutory or aspects
 * relating to merchantability or fitness for any purpose is provided.  All
 * intellectual property rights of others is maintained with the respective
 * owners.  This software is not copyrighted and is intended for reference
 * only.
 * END_BLOCK
 ******************************************************************************/

#include "at91rm9200_lowlevel.h"

/* ****************************** GLOBALS *************************************/

/* ********************* PRIVATE FUNCTIONS/DATA/DEFINES ***********************/

#define PACKET_SIZE	128

/* Line control codes */
#define SOH			0x01	/* start of header */
#define ACK			0x06	/* Acknowledge */
#define NAK			0x15	/* Negative acknowledge */
#define CAN			0x18	/* Cancel */
#define EOT			0x04	/* end of text */

enum {
	INVALID_STATE = 0,
	WAITING_START,
	WAIT_SOH,
	RX_PACKET,
	RX_EOT,
	SEND_NAK
};

static char	packetNumber;

#define TransitionState(x, y) (x = y)


/*
 * .KB_C_FN_DEFINITION_START
 * int GetRecord(char , char *)
 *  This private function receives a x-modem record to the pointer and
 * returns non-zero on success.
 * .KB_C_FN_DEFINITION_END
 */
static int GetRecord(char blocknum, char *dest) {
	int		size;
	char		nextChar;
	unsigned	chk, j;

	chk = 0;

	if (!WaitForChar(&nextChar, 1)) {
		return (0);
	}

	if ((char)nextChar != (char)~blocknum) {
		return (0);
	}

	for (size = 0; size < PACKET_SIZE; ++size) {
		if (!WaitForChar(&nextChar, 1)) {
			return (0);
		}
		chk = chk ^(int)nextChar << 8;
		for (j = 0; j < 8; ++j) {
			if (chk & 0x8000)
				chk = chk << 1 ^ 0x1021;
			else
				chk = chk << 1;
		}
		*dest++ = nextChar;
	}

	chk &= 0xFFFF;

	if ((!WaitForChar(&nextChar, 1)) || (nextChar != ((chk >> 8) & 0xFF))) {
		return (0);
	}

	if ((!WaitForChar(&nextChar, 1)) || (nextChar != (chk & 0xFF))) {
		return (0);
	}

	DebugPutc(ACK);

	return (1);
}


/* ************************** GLOBAL FUNCTIONS ********************************/


/*
 * .KB_C_FN_DEFINITION_START
 * int xmodem_rx(char *)
 *  This global function receives a x-modem transmission consisting of
 * (potentially) several blocks.  Returns the number of bytes received or
 * -1 on error.
 * .KB_C_FN_DEFINITION_END
 */
int xmodem_rx(char *dest) {

	int		state;
	char		nextChar, *startAddress = dest;

	packetNumber = 1;
	state = WAITING_START;

	while (1) {

		if (state == WAITING_START) {
			DebugPutc('C');
			if (WaitForChar(&nextChar, 1)) {
				if (nextChar == SOH) {
					TransitionState(state, RX_PACKET);
				}
			}
		}

		if (state == WAIT_SOH) {
			if (!WaitForChar(&nextChar, 1)) {
				return (-1);
			}

			if (nextChar == SOH) {
				TransitionState(state, RX_PACKET);
			}

			if (nextChar == EOT) {
				// TransitionState(state, RX_EOT);
				DebugPutc(ACK);
				return (dest - startAddress);
			}
		}

		if (state == RX_PACKET) {
			if (!WaitForChar(&nextChar, 1)) {
				return (-1);
			}

			if (nextChar != packetNumber) {
				// TransitionState(state, SEND_NAK);
				DebugPutc(NAK);
				return (-1);
			}

			if (GetRecord(packetNumber, dest)) {
				dest += PACKET_SIZE;
				++packetNumber;
				TransitionState(state, WAIT_SOH);
			} else {
				return (-1);
			}
		}
	}

	// the loop above should return in all cases
	return (-1);
}
