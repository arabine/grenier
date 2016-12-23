		ORG	$0


TRMSTAT 	EQU		$10040	;TERMINAL STATUS REGISTER
TRMDATA 	EQU		$10042	;TERMINAL DATA REGISTERS


Debut:

	
		MOVE.B	#$34,D3
		JSR		SendChar

		BRA		Fin













SendChar:
WaitOut:
		BTST		#1,TRMSTAT
		BEQ		WaitOut	;WAIT FOR OUTPUT READY
		MOVE.B	D3,TRMDATA	;OUTPUT CHARACTER IN D3
		RTS

Fin:
        	STOP 		#$2700          Stop the program
		END     	$0           End of assembly
