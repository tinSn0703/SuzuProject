/*
 * DoubleCylinder.cpp
 *
 * Created: 2018/02/28 15:36:05
 *  Author: FUJITSU
 */ 

#include <stdlib.h>

#include <akilcd/akilcd.h>
#include <Others/BOOL.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Valve/Valve.h>
#include <MainCircit/Cylinder/DoubleCylinder.h>

#define WAIT_TIME 50//[ms]

/************************************************************************/

DoubleCylinder::DoubleCylinder()
{
	_valve_NC.Set(CLOSE);
	_valve_NO.Set(CLOSE);
}

//----------------------------------------------------------------------//

 DoubleCylinder::DoubleCylinder(ValveNum _num)

	: _valve_NC(_num)
{
	_valve_NC.Set(CLOSE);
	_valve_NO.Set(CLOSE);
}

//----------------------------------------------------------------------//

 DoubleCylinder::DoubleCylinder(ValveNum _num_NC, ValveNum _num_NO)

	: _valve_NC(_num_NC)
	, _valve_NO(_num_NO)
{
	_valve_NC.Set(CLOSE);
	_valve_NO.Set(OPEN);
}

//----------------------------------------------------------------------//

void DoubleCylinder::Reset(ValveNum _num)
{
	_valve_NC.Reset(_num);
	_valve_NO.Reset(_num);
}

//----------------------------------------------------------------------//

void DoubleCylinder::Reset(ValveNum _num_NC, ValveNum _num_NO)
{
	_valve_NC.Reset(_num_NC);
	_valve_NO.Reset(_num_NO);
}

//----------------------------------------------------------------------//

void DoubleCylinder::Reset(DoubleValve _valve, ValveNum _num)
{
	switch (_valve)
	{
		case VALVE_NC:	_valve_NC.Reset(_num);	break;
		case VALVE_NO:	_valve_NO.Reset(_num);	break;
	}
}

//----------------------------------------------------------------------//

void DoubleCylinder::Lengthen(YesNo _is_done, mSecond _wait_time /*= 0*/)
{
	if (this->_state != STATE_LONG)
	{
		if (_is_done & ~_counter.Is_running())
		{
			_counter.Start(_wait_time + WAIT_TIME);
			
			_valve_NO.Set(CLOSE);
		}
		
		if (_counter.Is_finished())
		{
			_valve_NC.Set(OPEN);
			
			if (_is_done == NO)
			{
				_counter.Finish();
				
				this->_state = STATE_LONG;
			}
		}
	}
}

//----------------------------------------------------------------------//

void DoubleCylinder::Shorten(YesNo _is_done, mSecond _wait_time /*= 0*/)
{
	if (this->_state != STATE_SHORT)
	{
		if (_is_done & ~_counter.Is_running())
		{
			_counter.Start(_wait_time + WAIT_TIME);
		}
		
		if ((_counter.Get() > Timer::General::Set_counter(_wait_time)) && (_valve_NC.Get_state() == OPEN))
		{
			_valve_NC.Set(CLOSE);
		}
		
		if (_counter.Is_finished())
		{
			_valve_NO.Set(OPEN);
			
			if (_is_done == NO)
			{
				_counter.Finish();
				
				this->_state = STATE_SHORT;
			}
		}
	}
}

//----------------------------------------------------------------------//

void DoubleCylinder::Open(YesNo _is_done, mSecond _wait_time /*= 0*/)
{
	if (this->_state != STATE_OPENING)
	{
		if (_is_done & ~_counter.Is_running())
		{
			_counter.Start(_wait_time);
		}
		
		if (_counter.Is_finished())
		{
			_valve_NC.Set(CLOSE);
			_valve_NO.Set(CLOSE);
			
			if (_is_done == NO)
			{
				_counter.Finish();
				
				this->_state = STATE_OPENING;
			}
		}
	}
}

//----------------------------------------------------------------------//

ValveNum DoubleCylinder::Get_num(DoubleValve _valve)
{
	switch (_valve)
	{
		case VALVE_NC:	return _valve_NC.Get_num();
		case VALVE_NO:	return _valve_NO.Get_num();
	}
	
	return _valve_NC.Get_num();
}

//----------------------------------------------------------------------//

ValveData DoubleCylinder::Get_data()
{
	return _valve_NC.Get_data() | _valve_NO.Get_data();
}

//----------------------------------------------------------------------//

CylinderState DoubleCylinder::Get_state()
{
	return _state;
}

//----------------------------------------------------------------------//

/************************************************************************/
