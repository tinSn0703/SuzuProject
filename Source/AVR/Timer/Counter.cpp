
#include <Others/BOOL.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>

/************************************************************************/

//----------------------------------------------------------------------//

Counter::Counter()
{
	_mem_timer = TIMER_INITAL_VALUE;
}

//----------------------------------------------------------------------//

YesNo Counter::Is_running()
{
	return ((_mem_timer == TIMER_INITAL_VALUE) ? NO : YES);
}


//----------------------------------------------------------------------//

void Counter::Start(const mSecond _count_time)
{
	_mem_timer = Timer::General::Set_counter(_count_time);
}

//----------------------------------------------------------------------//

void Counter::Finish()
{
	_mem_timer = TIMER_INITAL_VALUE;
}

//----------------------------------------------------------------------//

YesNo Counter::Is_finished()
{
	return Timer::General::Is_current_bigger_than(_mem_timer);
}

//----------------------------------------------------------------------//

CountValue Counter::Get()
{
	return _mem_timer;
}

//----------------------------------------------------------------------//

/************************************************************************/
