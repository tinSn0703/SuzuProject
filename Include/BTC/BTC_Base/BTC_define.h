
#pragma once

/************************************************************************/

namespace Bluetooth
{

/************************************************************************/

#if BLUETOOTH == BLUEMASTER

#	define UART_NUM_BT Uart::NUM_1

#	define UART_BT_RX_vect USART1_RX_vect

#	define CTS PD4
#	define RTS PD5
#	define RSE PD6

#	define DDR_CTS DDRD
#	define DDR_RTS DDRD
#	define DDR_RSE DDRD

#	define PIN_CTS PIND
#	define PIN_RTS PIND
#	define PIN_RSE PIND

#	define PORT_CTS PORTD
#	define PORT_RTS PORTD
#	define PORT_RSE PORTD

#elif BLUETOOTH == ROBOBA005

#	define UART_NUM_BT Uart::NUM_1

#	define UART_BT_RX_vect USART1_RX_vect

#	define CTS PD4
#	define RTS PD5
#	define RSE PD6

#	define DDR_CTS DDRD
#	define DDR_RTS DDRD
#	define DDR_RSE DDRD

#	define PIN_CTS PIND
#	define PIN_RTS PIND
#	define PIN_RSE PIND

#	define PORT_CTS PORTD
#	define PORT_RTS PORTD
#	define PORT_RSE PORTD

#endif

/************************************************************************/

#define CTS_BIT (1 << CTS)
#define RTS_BIT (1 << RTS)
#define RSE_BIT (1 << RSE)

#define CTS_READ() ((PIN_CTS >> CTS) & 1)
#define RTS_READ() ((PIN_RTS >> RTS) & 1)
#define RSE_READ() ((PIN_RSE >> RSE) & 1)

#define CTS_HIGH() (PORT_CTS |=  CTS_BIT)
#define RTS_HIGH() (PORT_RTS |=  RTS_BIT)
#define RSE_HIGH() (PORT_RSE |=  RSE_BIT)

#define CTS_LOW() (PORT_CTS &= ~CTS_BIT)
#define RTS_LOW() (PORT_RTS &= ~RTS_BIT)
#define RSE_LOW() (PORT_RSE &= ~RSE_BIT)

/************************************************************************/

#define ADRS_BLUEMASTER_01 "000190EAD4B5"
#define ADRS_BLUEMASTER_02 "000190EAD491"
#define ADRS_BLUEMASTER_03 "000190E53F09"
#define ADRS_BLUEMASTER_04 "000190EAD491"
#define ADRS_BLUEMASTER_05 "000190EAD49A"
#define ADRS_BLUEMASTER_06 "000190E53A7B"
#define ADRS_BLUEMASTER_07 "000190EB1273"
#define ADRS_BLUEMASTER_08 "000190EB1416"
#define ADRS_BLUEMASTER_09 "000190EB105D"
#define ADRS_BLUEMASTER_10 "000190EB1057"
#define ADRS_BLUEMASTER_11 "000190EB105A"
#define ADRS_BLUEMASTER_12 "000190EB1052"
#define ADRS_BLUEMASTER_13 "000190EB1050"
#define ADRS_BLUEMASTER_14 "000190EB105C"
#define ADRS_BLUEMASTER_15 "000190EB104F"
#define ADRS_BLUEMASTER_16 "000190EB104E"

#define ADRS_ROBOBA005_00 "000190D89F6C"
#define ADRS_ROBOBA005_01 "000190D89F6B"
#define ADRS_ROBOBA005_02 "000190D89F70"
#define ADRS_ROBOBA005_03 "000190D89F72"
#define ADRS_ROBOBA005_04 "000190D89F9C"
#define ADRS_ROBOBA005_05 "000190D89F9B"
#define ADRS_ROBOBA005_06 "000190D89F6A"
#define ADRS_ROBOBA005_07 "000190D89F6D"
#define ADRS_ROBOBA005_08 "000190D89F9D"
#define ADRS_ROBOBA005_09 "000190D89F6F"
#define ADRS_ROBOBA005_10 "000190D89F68"
#define ADRS_ROBOBA005_11 "000190D89F6E"
#define ADRS_ROBOBA005_12 "000190D89F69"
#define ADRS_ROBOBA005_13 "000190D89F71"
#define ADRS_ROBOBA005_14 "000190D89DA4"
#define ADRS_ROBOBA005_15 "000190E98B15"

/************************************************************************/

};

/************************************************************************/
