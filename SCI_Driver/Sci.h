/*
 * Sci.h
 *
 * Created: 8/6/2018 10:16:57 PM
 *  Author: ahmed
 */ 


#ifndef SCI_H_
#define SCI_H_
#include "Std_types.h"
#include "Sci_cfg.h"
#include <avr/io.h>

#ifndef F_CPU
/* prevent compiler error by supplying a default */
# warning "F_CPU not defined for SCI and defined with 1000000>"
# define F_CPU 1000000UL
#endif

typedef struct
{
	//u8 UART_id;
	u8 baud_rate; // baud_rate num
	u8 parity; // Even, ODD, or NONE
	u8 stop_bits; //1 or 2 
	//u8 sync;
	//u8 interrupt_Enable; // disable or Enable
}Sci_ConfigType;

typedef enum
{
 SCI_NOT_OK, // Development or production error occurred.
 SCI_TX_OK, // Successful transmission.
 SCI_TX_BUSY, // Ongoing transmission.
 SCI_TX_ERROR, // Erroneous transmission such as Transmission disabled or Physical bus error.
 SCI_RX_OK, // Successful reception.
 SCI_RX_BUSY, // Ongoing reception.
 SCI_RX_ERROR, // Erroneous reception such as Reception disabled, Parity error, Framing error or Overrun error
 SCI_OPERATIONAL, //Normal operation; the related SCI channel is ready to transmit or receive. No data from previous communication available (e.g. after initialization).
 SCI_CH_SLEEP, // Sleep state operation; in this state wake-up detection is enabled.
 
}Sci_StatusType; 

typedef u8 Sci_ChannelType;
typedef void (*Sci_TxNotification)(void);
typedef void (*Sci_TxErrNotification)(void);
typedef void (*Sci_RxNotification)(void);
typedef void (*Sci_RxErrNotification)(void);

void Sci_Init(const Sci_ConfigType *ConfigPtr); //SCI Driver Initialization.
//void Sci_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr); //SCI Driver version informations retrieval.
Std_ReturnType Sci_WriteTxData(Sci_ChannelType Channel, u8 Data); //TX Data Write. returns E_OK or E_NOT_OK
Std_ReturnType Sci_ReadRxData(Sci_ChannelType Channel, u8 *DataPtr); //RX Data Read. returns E_OK or E_NOT_OK
Sci_StatusType Sci_GetStatus(Sci_ChannelType Channel); //SCI Channel Status Retrieval. returns on of Sci_StatusType
Std_ReturnType Sci_GoToSleep(Sci_ChannelType Channel); //Channel Go To Sleep. return E_OK or E_NOT_OK
Std_ReturnType Sci_Wakeup(Sci_ChannelType Channel); //Channel Wake-up. return E_OK or E_NOT_OK
Std_ReturnType Sci_CheckWakeup(Sci_ChannelType Channel); //Channel Wake-up Check. return E_OK or E_NOT_OK
Std_ReturnType Sci_DisableTx(Sci_ChannelType Channel); //Channel Transmission Disable. return E_OK or E_NOT_OK
Std_ReturnType Sci_EnableTx(Sci_ChannelType Channel);//Channel Transmission Enable. return E_OK or E_NOT_OK
Std_ReturnType Sci_DisableRx(Sci_ChannelType Channel); //Channel Reception Disable. return E_OK or E_NOT_OK
Std_ReturnType Sci_EnableRx(Sci_ChannelType Channel); //Channel Reception Enable.  return E_OK or E_NOT_OK
void Sci_EnableNotifications(Sci_ChannelType Channel);//Channel Notifications Enable.
void Sci_DisableNotifications(Sci_ChannelType Channel); //Channel Notifications Disable.




#endif /* SCI_H_ */