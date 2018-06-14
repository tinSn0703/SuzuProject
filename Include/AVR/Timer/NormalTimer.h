
#pragma once

/************************************************************************/

#include "Timer_type.h"

/************************************************************************/

#define TIMER_SHORT_ISR_vect TIMER0_COMPA_vect

/************************************************************************/

namespace Timer
{

/************************************************************************/

//Timer0
namespace Short
{

void Initialize();

void Set(Clock _clock, CountValue _count_value);

void Set_us(uSecond _time_us);

void Set_ms(mSecond _time_ms);

void Start();

void Start(Clock _clock, CountValue _count_value);

void Enable_isr();

void Disable_isr();

YesNo Is_count_finshed();

void Stop();

};

/************************************************************************/

//Timer1
namespace Long
{

/************************************************************************/

void Initialize();

void Set(Clock _clock, CountValue _count_value);

void Set_us(uSecond _time_us);

void Set_ms(mSecond _time_ms);

void Start();

void Start(Clock _clock, CountValue _count_value);

YesNo Is_count_finshed();

void Stop();

/************************************************************************/

}

}

/************************************************************************/
