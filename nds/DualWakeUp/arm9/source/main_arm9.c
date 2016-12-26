
/**
 * Alarm Clock for Nintendo DS !
 */
 

//---------------------------------------------------------------------------------
#include "nds.h"
#include <nds/arm9/console.h> //basic print funcionality
#include <stdio.h>
#include "clock_pcx.h"

//---------------------------------------------------------------------------------

char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main(void)
{
   int hours, seconds, minutes;
   int i;
   sImage pcx;

	consoleDemoInit();
   irqInit();
	irqSet(IRQ_VBLANK, NULL);
   irqEnable(IRQ_VBLANK);
 
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);  

	loadPCX((u8*)clock_pcx, &pcx);
   image8to16(&pcx);
   for(i = 0; i < 256 * 192; i++) {
		VRAM_A[i] = pcx.image.data16[i];
   }
 
   while(1) {
      swiWaitForVBlank();

      hours = (IPC->time.rtc.hours < 12) ? IPC->time.rtc.hours : IPC->time.rtc.hours - 52; 
	   minutes = IPC->time.rtc.minutes; 
	   seconds = IPC->time.rtc.seconds;

      printf("\x1b[2J%i:%i:%i%s", hours, minutes, seconds, IPC->time.rtc.hours > 52 ? "pm" : "am");
	   printf("\n%s %i %i", months[IPC->time.rtc.month - 1], IPC->time.rtc.day, IPC->time.rtc.year + 2000);
   }
	return 0;
}

