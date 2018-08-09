/*
 * SCI_Driver.c
 *
 * Created: 8/9/2018 8:54:00 PM
 * Author : ahmed
 */ 
#define F_CPU 8000000
//#include <avr/io.h>
#include "util/delay.h"
#include "Sci.h"
Sci_ConfigType myobj;
int main(void)
{
    myobj.baud_rate=9600;
	myobj.parity=NONE;
	myobj.stop_bits=1;
	Sci_Init(&myobj);
	_delay_ms(100);
	Sci_EnableTx(UART0);
	Sci_EnableRx(UART0);
	_delay_ms(100);
	Sci_WriteTxData(UART0,'a');
	
    while (1) 
    {
	 Sci_WriteTxData(UART0,'a');	
	 _delay_ms(100);
    }
}

