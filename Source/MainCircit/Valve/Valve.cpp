
#include <akilcd/akilcd.h>
#include <Others/BOOL.h>
#include <akilcd/akilcd.h>
#include <MainCircit/Valve/Valve.h>

/************************************************************************/

//----------------------------------------------------------------------//

Valve::Valve()
{
	_is_move_enabled = NO;
	
	_state = CLOSE;
}

//----------------------------------------------------------------------//

Valve::Valve(const ValveNum _num)
{
	this->_num = _num;
	
	_state = CLOSE;
	
	_is_move_enabled = YES;
}

//----------------------------------------------------------------------//

void Valve::Reset(const ValveNum _num)
{
	this->_num = _num;
	
	_is_move_enabled = YES;
}

//----------------------------------------------------------------------//

void Valve::Set(const OpenClose _open_or_close)
{
	_state = _open_or_close;
}

//----------------------------------------------------------------------//

void Valve::Open(const YesNo _is_done)
{
	if (_is_done)	_state = OPEN;
}

//----------------------------------------------------------------------//

void Valve::Close(const YesNo _is_done)
{
	if (_is_done)	_state = CLOSE;
}

//----------------------------------------------------------------------//

ValveNum Valve::Get_num()
{
	return _num;
}

//----------------------------------------------------------------------//

ValveData Valve::Get_data()
{
	return (_is_move_enabled ? (_state << _num) : 0);
}

//----------------------------------------------------------------------//

OpenClose Valve::Get_state()
{
	return _state;
}

//----------------------------------------------------------------------//

/************************************************************************/
