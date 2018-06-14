
/************************************************************************/

#pragma once

/************************************************************************/

#define BLUEMASTER	0
//#define ROBOBA005	1

/************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <Others/Str.h>
#include <Others/BOOL.h>
#include <AVR/Uart/Uart_func.h>

/************************************************************************/

#if		defined(BLUEMASTER)
#	define BLUETOOTH BLUEMASTER
#	pragma message("Bluetooh select BlueMaster.")
#elif	defined(ROBOBA005)
#	define BLUETOOTH ROBOBA005
#	pragma message("Bluetooh select ROBOBA005.")
#else
#	error "Please define BLUEMASTER or ROBOBA005.  "
#endif

/************************************************************************/

#define NUM_BT_ADRS_LENGTH	13
#define NUM_BT_ADRS_TAIL	12

#define CODE_FAILED_PARTNER_SELECTION 255

/************************************************************************/

#include "BTC_Base/BTC_type.h"
#include "BTC_Base/BTC_func.h"

/************************************************************************/
