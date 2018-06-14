
#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/ControllerBase/Ver2BaseControllerBase.h>
#include <MainCircit/Controller/ControllerBase/Ver2BaseControllerGet.h>
#include <MainCircit/Controller/ControllerBase/Ver2BaseControllerRewrite.h>
#include <MainCircit/Controller/ControllerBase/Ver2BaseControllerLCD.h>

/************************************************************************/

namespace Controller
{
namespace Ver2
{
namespace Base
{

/************************************************************************/
/*	ControllerBase														*/
/************************************************************************/

//----------------------------------------------------------------------//

Bit24ControllerBase::Bit24ControllerBase()
{
	this->_data._array[0] = 0x00;
	this->_data._array[1] = 0xf0;
	this->_data._array[2] = 0xff;
}

//----------------------------------------------------------------------//

void Bit24ControllerBase::Allot(ControllerData _receive_data[NUM_CONTROLLER_24BIT])
{
	this->_data._command._cross_x	= To_DirectionX((Is_true_the(_receive_data[0], 5) << 1) | Is_true_the(_receive_data[1], 1));
	this->_data._command._cross_y	= To_DirectionY((Is_true_the(_receive_data[0], 4) << 1) | Is_true_the(_receive_data[1], 0));
	
	this->_data._command._stick_right_x	= To_DirectionX(_receive_data[2] >> 4);
	this->_data._command._stick_right_y	= To_DirectionY(_receive_data[3] >> 0);
	
	this->_data._command._stick_left_x	= To_DirectionX(_receive_data[3] >> 2);
	this->_data._command._stick_left_y	= To_DirectionY(_receive_data[3] >> 4);
	
	this->_data._btns._other = ((~_receive_data[0]) & 0x0f);
	
	this->_data._btns._right_left = ((~_receive_data[1] >> 2) & 0x0f);
	
	this->_data._btns._mark = ((~_receive_data[2]) & 0x0f);
}

//----------------------------------------------------------------------//

void Bit24ControllerBase::Clear()
{
	this->_data._array[0] = 0x00;
	this->_data._array[1] = 0xf0;
	this->_data._array[2] = 0xff;
}

//----------------------------------------------------------------------//

YesNo Bit24ControllerBase::Is_commnad_push()
{
	return ((this->_data._all_data == 0xfff000) ? NO : YES);
}

//----------------------------------------------------------------------//

/************************************************************************/
/*	ControllerGet														*/
/************************************************************************/

//----------------------------------------------------------------------//

ControllerGet::ControllerGet(Bit24ControllerBase * _object)
{
	_controller_data = _object;
}

//----------------------------------------------------------------------//

ControllerData ControllerGet::Get_data(const uByte _num)
{
	return
	(
		_num > 2 ? this->_controller_data->_data._array[2] :
		_num < 0 ? this->_controller_data->_data._array[0] :
		this->_controller_data->_data._array[_num]
	);
}

//----------------------------------------------------------------------//

/************************************************************************/
/*	ControllerRewrite													*/
/************************************************************************/

//----------------------------------------------------------------------//

ControllerRewrite::ControllerRewrite(Bit24ControllerBase *_object, YesNo _is_rewrite_enabled)
{
	_controller_data = _object;
	
	this->_is_rewrite_enabled = _is_rewrite_enabled;
}

//----------------------------------------------------------------------//

void ControllerRewrite::Rewrite_base(const uByte _bit, const int _data, const int _and)
{
	if (_is_rewrite_enabled)
	{
		this->_controller_data->_data._all_data &= ~(_and << _bit);
		this->_controller_data->_data._all_data |= (_data << _bit);
	}
}

/************************************************************************/
/*	ControllerLCD														*/
/************************************************************************/

//----------------------------------------------------------------------//

ControllerLCD::ControllerLCD(Bit24ControllerBase * _object)
	: ControllerGet(_object)
{
	if ( ! LCD::Is_initialize())
	{
		LCD::Initialize();
	}
}

//----------------------------------------------------------------------//

/************************************************************************/

};
};
};

/************************************************************************/
