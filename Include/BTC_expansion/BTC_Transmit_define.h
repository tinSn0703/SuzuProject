
#pragma once

/************************************************************************/

#define BIT_LED0 (1 << PB0)
#define BIT_LED1 (1 << PB1)
#define BIT_LED2 (1 << PB2)
#define BIT_LED3 (1 << PC6)
#define BIT_LED4 (1 << PC7)

#define LED0_ON() (PORTB |= BIT_LED0)
#define LED1_ON() (PORTB |= BIT_LED1)
#define LED2_ON() (PORTB |= BIT_LED2)
#define LED3_ON() (PORTC |= BIT_LED3)
#define LED4_ON() (PORTC |= BIT_LED4)

#define LED_ON()	LED0_ON();	\
					LED1_ON();	\
					LED2_ON();	\
					LED3_ON();	\
					LED4_ON()

#define LED0_OFF() (PORTB &= ~BIT_LED0)
#define LED1_OFF() (PORTB &= ~BIT_LED1)
#define LED2_OFF() (PORTB &= ~BIT_LED2)
#define LED3_OFF() (PORTC &= ~BIT_LED3)
#define LED4_OFF() (PORTC &= ~BIT_LED4)

#define LED_OFF()	LED0_OFF();	\
					LED1_OFF();	\
					LED2_OFF();	\
					LED3_OFF();	\
					LED4_OFF()

#define SW_READ() ((BluetoothNum)(~((PINA & 0xfe) | ((PIND >> 1) & 1)) & 0xff))

#define INIT_IO_PORT()	(DDRA  = 0x00);								\
						(DDRB  = (BIT_LED0 | BIT_LED1 | BIT_LED2));	\
						(DDRC  = (BIT_LED3 | BIT_LED4));			\
						(PORTA = 0xfe);								\
						(PORTB = 0x00);								\
						(PORTC = 0x00);								\
						(PORTD = 0x02)

/************************************************************************/
