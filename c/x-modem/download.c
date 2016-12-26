/*******************************************************************************
 *
 * Filename: download.c
 *
 * Simple host-side, x-modem download utility.  Does not provide error
 * recovery.
 *
 * Revision information:
 *
 * 20SEP2004	kb_admin	initial creation
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

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/time.h>

/******************************* LOCAL DEFINES ********************************/

// the following defines the UART used for the transfer
#define TEST_FILENAME "/dev/ttyS0"

// define the following for verbose messages
//#define QUIET_MODE

#ifdef QUIET_MODE
#define DBG_PRINT(args...) if(0)
#else
#define DBG_PRINT printf
#endif

#define RECORD_SIZE	128

/* Line control codes */
#define SOH			0x01	/* start of header */
#define ACK			0x06	/* Acknowledge */
#define NAK			0x15	/* Negative acknowledge */
#define CAN			0x18	/* Cancel */
#define EOT			0x04	/* end of text */

#define WAIT_FOR_START	1
#define SEND_BLOCK	2
#define SEND_EOT	3
#define TERMINATE	4
#define FINISHED	5

/********************************** GLOBALS ***********************************/

unsigned block_num = 0;

int ioPort;

char inputBuffer[RECORD_SIZE];

FILE *inputFilePtr;


/****************************** LOCAL FUNCTIONS *******************************/


/*
 * .KB_C_FN_DEFINITION_START
 * char WaitForChar(int Seconds)
 *  This private function waits for a maxmimum of seconds while attempting
 * to read a character from the input port.
 * Returns the character or -1 on timeout/error.
 * .KB_C_FN_DEFINITION_END
 */
static char WaitForChar(int seconds) {

        struct timeval	this_tv, to_tv;
	char		local_char;

	gettimeofday(&to_tv, 0);
	to_tv.tv_sec += seconds;

	while (1) {

		if (read(ioPort, &local_char, 1) > 0) {
			DBG_PRINT("RX char: %d (%c)\n", local_char, local_char);
			return (local_char);
		}

		gettimeofday(&this_tv, 0);

		if ((this_tv.tv_sec >= to_tv.tv_sec) &&
			(this_tv.tv_usec >= to_tv.tv_usec)) {
			DBG_PRINT("Error RX\n");
			return (-1);
		}
	}
}


/*
 * .KB_C_FN_DEFINITION_START
 * void WriteChar(char)
 *  This private function writes a character to the IO port.
 * .KB_C_FN_DEFINITION_END
 */
static void WriteChar(char x) {
	write(ioPort, &x, 1);
}


/*
 * .KB_C_FN_DEFINITION_START
 * int SendRecord(char *data)
 *  This private function sends a x-modem record.  Returns 0 on success, else
 * -1.
 * .KB_C_FN_DEFINITION_END
 */
static int SendRecord(char *data) {

	unsigned i, chk, j;

	WriteChar(SOH);
	WriteChar(block_num+1);
	WriteChar(~(block_num+1));
	chk = 0;
	for(i=0; i < RECORD_SIZE; ++i) {
		chk = chk ^(int)*data << 8;
		for (j = 0; j < 8; ++j) {
			if (chk & 0x8000)
				chk = chk << 1 ^ 0x1021;
			else
				chk = chk << 1;
		}
		WriteChar((*data++));
	}
	chk &= 0xFFFF;
	WriteChar((chk >> 8));
	WriteChar(chk);

	DBG_PRINT("Block num %d sent, waiting for ACK\n", block_num + 1);

	if (WaitForChar(1) == ACK)
		return (0);

	return (-1);
}


/*
 * .KB_C_FN_DEFINITION_START
 * char *StateToString(int state)
 *  Convert state code to string.
 * .KB_C_FN_DEFINITION_END
 */
static const char *StateToString(int state) {
	const char *str;

	switch (state) {
   	case WAIT_FOR_START:
		str = "WAIT_FOR_START";
		break;
	case SEND_BLOCK:
		str = "SEND_BLOCK";
		break;
	case SEND_EOT:
		str = "SEND_EOT";
		break;
	case TERMINATE:
		str = "TERMINATE";
		break;
	case FINISHED:
		str = "FINISHED";
		break;
	default:
		str = "INVALID";
	}

	return (str);
}


/*
 * .KB_C_FN_DEFINITION_START
 * void TransitionState(int *old, int new)
 *  Record the transition from one state to the next.
 * .KB_C_FN_DEFINITION_END
 */
static void TransitionState(int *old, int new_state) {
	printf("From: %s -> %s\n", StateToString(*old), StateToString(new_state));
	*old = new_state;
}


/*********************************** MAIN *************************************/

int main(int argc, char *argv[]) {

	int i, j, state, transfer = 1, retry_count = 0, returnValue = 0;
	struct termios options;

	if (argc != 2) {
		printf ("Error: Missing input file parameter\n");
		exit(1);
	}

	if((inputFilePtr = fopen(argv[1], "rb")) < 0) {
		printf ("Error: input file open failed\n\r");
		exit(1);
	}

	if ((ioPort = open(TEST_FILENAME, O_RDWR | O_NOCTTY)) < 0) {
		printf("Error: opening serial device(%s): %d\n",
			TEST_FILENAME, errno);
		exit(1);
	}

	memset(&options, 0, sizeof(options));
	options.c_cflag |= (CLOCAL | CREAD);
	if (cfsetispeed(&options, B115200) < 0) {
		exit(1);
	}

	if (cfsetospeed(&options, B115200) < 0) {
		exit(1);
	}

	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	options.c_cflag &= ~CSTOPB;

	if (tcsetattr(ioPort, TCSADRAIN, &options) < 0) {
		exit(1);
	}

	state = WAIT_FOR_START;

	while (transfer) {
	switch (state) {
		case WAIT_FOR_START:
			switch(WaitForChar(10)) {
				case 'C':
					TransitionState(&state, SEND_BLOCK);
					break;
				default:
					TransitionState(&state, TERMINATE);
					break;
			}
			break;

		case SEND_BLOCK:
			bzero(inputBuffer, sizeof(inputBuffer));
			j = fread(inputBuffer, 1, RECORD_SIZE, inputFilePtr);
			if (j < 0) {
				printf(" ERROR reading: %d\n", j);
				TransitionState(&state, SEND_EOT);
				break;
			} else {
				DBG_PRINT(" DEBUG: bytes read: %d\n", j);
				for (i = 0; i < RECORD_SIZE; ++i) {
					DBG_PRINT("%02x ",
						(unsigned char)inputBuffer[i]);
					if (!((i+1) % 16))
						DBG_PRINT("\n");
				}
				DBG_PRINT("\n");
				if (j < RECORD_SIZE)
					TransitionState(&state, SEND_EOT);
			}

			DBG_PRINT("block num: %u\n", block_num + 1);

			if (SendRecord(inputBuffer) < 0) {
				DBG_PRINT("Invalid response\n");
				TransitionState(&state, TERMINATE);
			} else {
				DBG_PRINT("Correct response\n");
				block_num++;
			}
			break;

		case SEND_EOT:
			printf("Sending EOT\n");
			WriteChar(EOT);
			switch(WaitForChar(10)) {
				case ACK:
					printf("Transfer complete\n");
					TransitionState(&state, FINISHED);
					break;
				default:
					TransitionState(&state, TERMINATE);
					printf("Error");
			}
			break;

		case TERMINATE:
			printf(" *** Transfer failed *** \n");
			WriteChar(CAN);
			TransitionState(&state, FINISHED);
			returnValue = -1;
			break;

		case FINISHED:
			transfer = 0;
			break;
		default:
			TransitionState(&state, FINISHED);
	}
	}

	close(ioPort);

	if (!returnValue) {
		printf(" Transmission complete: size = %d (0x%8X)\n",
			block_num * RECORD_SIZE, block_num * RECORD_SIZE);
	}

	return (returnValue);
}
