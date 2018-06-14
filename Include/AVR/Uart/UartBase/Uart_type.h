
#pragma once

/************************************************************************/

namespace Uart
{

//UARTのデータを表す型
typedef DataBit8	UartData8bit;
typedef DataBit16	UartData9bit;

//UARTの番号を表す型
enum UartNum
{	
	NUM_0 = 0xc0,
	NUM_1 = 0xc8,
	
#ifdef _AVR_IOM640_H_
	
	NUM_2 = 0xd0,
	NUM_3 = 0x130,
	
#endif
	
};

//UARTの割り込みを表す型
enum UartISR
{
	RECEIVE_COMPLETE	= 7,	//RXCIE
	TRANSMIT_COMPLETE	= 6,	//TXCIE
	UDR_EMPATY			= 5,	//UDRIE
};

}

using Uart::UartNum;
using Uart::UartData8bit;
using Uart::UartData9bit;
using Uart::UartISR;

/************************************************************************/
