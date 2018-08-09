/*
 * Sci.c
 *
 * Created: 8/6/2018 10:19:09 PM
 *  Author: ahmed
 */ 
#include "Sci.h"
static u16 baud_rate_value;
static u8 state;
void Sci_Init(const Sci_ConfigType * ConfigPtr) //that reg for for uart0
{
	  UCSRC |= (3<<UCSZ0); // 8 bits mode
	  UCSRA |=(1<<U2X); // double speed active
	  UCSRC |=(1<<URSEL); // select reg UCSRC
	  UCSRC |=((ConfigPtr->parity)<<(UPM0)); // select parity
	  UCSRC |=((ConfigPtr->stop_bits)<<(USBS)); // select stop_bits
	  baud_rate_value=( (F_CPU / (8L * (ConfigPtr->baud_rate)) ) -1); //set baud_rate value
	  UCSRC |=(1<<URSEL); // select reg UCSRC
	  UCSRC &=~(1<<UMSEL);
	  UBRRL &=~(1<<URSEL);
	  UBRRL = (u8)(baud_rate_value); // set baud_rate
	  UBRRH = (u8)(baud_rate_value>>8); // set baud_rate	  
}

Std_ReturnType Sci_WriteTxData(Sci_ChannelType Channel, u8 Data) // select uart channel to to write
{
 UDR=Data;
 
 return 0 ; // ok or not ok
}

Std_ReturnType Sci_ReadRxData(Sci_ChannelType Channel, u8 *DataPtr) // select uart channel to read
{
	*DataPtr=UDR;
	
	return 0; // ok or not ok
}

Sci_StatusType Sci_GetStatus(Sci_ChannelType Channel)
{
	
Sci_StatusType sci_state;

	return sci_state; // return status
}

Std_ReturnType Sci_DisableTx(Sci_ChannelType Channel)
{
	UCSRB &=~ (1 << TXEN);
	return 0; // return ok or not ok 
}

Std_ReturnType Sci_EnableTx(Sci_ChannelType Channel)
{
	UCSRB |= (1 << TXEN);
	return 0; // return ok or not ok	
}

Std_ReturnType Sci_DisableRx(Sci_ChannelType Channel)
{
	UCSRB &=~ (1 << RXEN);
	return 0; // return ok or not ok
}

Std_ReturnType Sci_EnableRx(Sci_ChannelType Channel)
{
	UCSRB |= (1 << RXEN);
	return 0; // return ok or not ok
}