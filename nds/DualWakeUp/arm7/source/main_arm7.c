#include <nds.h>
#include <stdlib.h>

static touchPosition first,tempPos;

//---------------------------------------------------------------------------------
void VblankHandler() {
//---------------------------------------------------------------------------------
	static int lastbut = -1;
   
	uint16 but=0, x=0, y=0, xpx=0, ypx=0, z1=0, z2=0;
   uint32 i;
   static uint8 ct[sizeof(IPC->time.curtime)];

	but = REG_KEYXY;

	if (!( (but ^ lastbut) & (1<<6))) {
 
		tempPos = touchReadXY();

		if ( tempPos.x == 0 || tempPos.y == 0 ) {
			but |= (1 <<6);
			lastbut = but;
		} else {
			x = tempPos.x;
			y = tempPos.y;
			xpx = tempPos.px;
			ypx = tempPos.py;
			z1 = tempPos.z1;
			z2 = tempPos.z2;
		}
		
	} else {
		lastbut = but;
		but |= (1 <<6);
	}


	if (	abs( xpx - first.px) > 10 || abs( ypx - first.py) > 10 ||
			(but & ( 1<<6)) ) {

		but |= (1 <<6);
		lastbut = but;
 
	} else { 	
		IPC->mailBusy = 1;
		IPC->touchX			= x;
		IPC->touchY			= y;
		IPC->touchXpx		= xpx;
		IPC->touchYpx		= ypx;
		IPC->touchZ1		= z1;
		IPC->touchZ2		= z2;
		IPC->mailBusy = 0;
	}

   
   // Lecture de l\'heure
   rtcGetTime((uint8 *)ct);
   BCDToInteger((uint8 *)&(ct[1]), 7);
   for(i=0; i<sizeof(ct); i++) {
      IPC->time.curtime[i] = ct[i];
   }

	IPC->buttons = but;
}


//---------------------------------------------------------------------------------
int main(int argc, char ** argv) {
//---------------------------------------------------------------------------------

	// Reset the clock if needed
	rtcReset();

	//enable sound
	powerON(POWER_SOUND);
   SOUND_CR = SOUND_ENABLE | SOUND_VOL(0x7F);

	irqInit();
	irqSet(IRQ_VBLANK, VblankHandler);
	irqEnable(IRQ_VBLANK);

	// Keep the ARM7 idle
	while (1) swiWaitForVBlank();
}


