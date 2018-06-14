
#pragma once

/************************************************************************/

#define UART_RECEIVE_CIRCIT Uart::NUM_0

#define BIT_LED0 (1 << PB0)
#define BIT_LED1 (1 << PB1)
#define BIT_LED2 (1 << PB2)
#define BIT_LED3 (1 << PB3)
#define BIT_LED4 (1 << PB4)

#define PORT_LED PORTB

#define LED0_ON() (PORT_LED |= BIT_LED0)
#define LED1_ON() (PORT_LED |= BIT_LED1)
#define LED2_ON() (PORT_LED |= BIT_LED2)
#define LED3_ON() (PORT_LED |= BIT_LED3)
#define LED4_ON() (PORT_LED |= BIT_LED4)

#define LED_ON()	(PORT_LED |= 0x1f)

#define LED0_OFF() (PORT_LED &= ~BIT_LED0)
#define LED1_OFF() (PORT_LED &= ~BIT_LED1)
#define LED2_OFF() (PORT_LED &= ~BIT_LED2)
#define LED3_OFF() (PORT_LED &= ~BIT_LED3)
#define LED4_OFF() (PORT_LED &= ~BIT_LED4)

#define LED_OFF()	(PORT_LED &= 0xe0)

#define SW_READ() ((BluetoothNum)((~PINC) & 0xff))

#define INIT_IO_PORT()	(DDRB = 0x1f);	\
						(DDRC = 0x00);	\
						(PORTB = 0x00);	\
						(PORTC = 0xff)

/************************************************************************/
