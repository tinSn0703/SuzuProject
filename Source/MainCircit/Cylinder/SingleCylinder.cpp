/*
 * AirCylinder.cpp
 *
 * Created: 2018/01/03 22:21:34
 *  Author: FUJITSU
 */ 

#include <akilcd/akilcd.h>
#include <Others/BOOL.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Valve/Valve.h>
#include <MainCircit/Cylinder/SingleCylinder.h>

/************************************************************************/

//----------------------------------------------------------------------//

SingleCylinder::SingleCylinder()
{
	_state = STATE_OPENING;
}

//----------------------------------------------------------------------//

SingleCylinder::SingleCylinder(const ValveNum _num)

	: _valve(_num)
{
	_state = STATE_OPENING;
}

//----------------------------------------------------------------------//

void SingleCylinder::Reset(const ValveNum _num)
{
	_valve.Reset(_num);
}

//----------------------------------------------------------------------//

void SingleCylinder::Lengthen(const YesNo _is_done, const mSecond _wait_time /* = 0 */)
{
	if (this->_state != STATE_LONG)
	{
		if (_is_done & ~_counter.Is_running())
		{
			_counter.Start(_wait_time);
		}
		
		if (_counter.Is_finished())
		{
			_valve.Set(OPEN);
			
			if (_is_done == NO)
			{
				_counter.Finish();
			}
		}
	}
}

//----------------------------------------------------------------------//

void SingleCylinder::Open(const YesNo _is_done, const mSecond _wait_time /* = 0 */)
{
	if (this->_state != STATE_LONG)
	{
		if (_is_done & ~_counter.Is_running())
		{
			_counter.Start(_wait_time);
		}
		
		if (_counter.Is_finished())
		{
			_valve.Set(CLOSE);
			
			if (_is_done == NO)
			{
				_counter.Finish();
			}
		}
	}
}

//----------------------------------------------------------------------//

ValveNum SingleCylinder::Get_num()
{
	return _valve.Get_num();
}

//----------------------------------------------------------------------//

ValveData SingleCylinder::Get_data()
{
	return _valve.Get_data();
}

//----------------------------------------------------------------------//

CylinderState SingleCylinder::Get_state()
{
	return _state;
}

//----------------------------------------------------------------------//

/************************************************************************/
