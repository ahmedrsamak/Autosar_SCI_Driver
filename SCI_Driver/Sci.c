/*
 * Sci.c
 *
 * Created: 8/6/2018 10:19:09 PM
 *  Author: ahmed
 */ 
#include "Sci.h"
static u16 baud_rate_value;

void Sci_Init(const Sci_ConfigType *ConfigPtr)
{
	  UCSRC |= (3<<UCSZ0); // 8 bits mode
	  UCSRA |=(1<<U2X); // double speed active
	  UCSRC |=(1<<URSEL); // select reg UCSRC
	  UCSRC |=((ConfigPtr->parity)<<(UPM0)); // select parity
	  UCSRC |=((ConfigPtr->stop_bits)<<(USBS)); // select stop_bits
	  baud_rate_value=( (F_CPU / (8L * )(ConfigPtr->baud_rate)) ) -1); //set baud_rate value
	  UCSRC |=(1<<URSEL); // select reg UCSRC
	  UCSRC &=~(1<<UMSEL);
	  UBRRL &=~(1<<URSEL);
	  UBRRL = (u8)(baud_rate_value); // set baud_rate
	  UBRRH = (u8)(baud_rate_value>>8); // set baud_rate	  
}