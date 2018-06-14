
#pragma once

/************************************************************************/

#include "Timer_define.h"
#include "Timer_type.h"

/************************************************************************/

class Counter
{
//variable
protected:
	
	CountValue _mem_timer;
	
//function
public:
	
	Counter();
	
	void Start(mSecond _count_time);
	
	void Finish();
	
	YesNo Is_finished();
	
	YesNo Is_running();
	
	CountValue Get();
};

/************************************************************************/
