
#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/ControllerBase/BaseControllerBase.h>
#include <MainCircit/Controller/ControllerBase/BaseControllerGet.h>
#include <MainCircit/Controller/ControllerBase/BaseControllerPush.h>
#include <MainCircit/Controller/ControllerBase/BaseControllerRewrite.h>
#include <MainCircit/Controller/ControllerBase/BaseControllerLCD.h>

/************************************************************************/

namespace Controller
{
namespace Base
{

/************************************************************************/
/*	ControllerBase														*/
/************************************************************************/

//----------------------------------------------------------------------//

ControllerBase::ControllerBase()
{
	_mem_data._array[0] = 0x00;
	_mem_data._array[1] = 0xf0;
	_mem_data._array[2] = 0xff;
}

//----------------------------------------------------------------------//

void ControllerBase::Clear()
{
	_mem_data._array[0] = 0x00;
	_mem_data._array[1] = 0xf0;
	_mem_data._array[2] = 0xff;
}

//----------------------------------------------------------------------//

YesNo ControllerBase::Is_commnad_push()
{
	return ((_mem_data._all_data == 0xfff000) ? NO : YES);
}

//----------------------------------------------------------------------//

/************************************************************************/
/*	ControllerGet														*/
/************************************************************************/

//----------------------------------------------------------------------//

ControllerGet::ControllerGet()
{
	
}

//----------------------------------------------------------------------//

ControllerData ControllerGet::Get_data(const uByte _num)
{
	return
	(
		_num > 2 ? this->_mem_data._array[2] :
		_num < 0 ? this->_mem_data._array[0] :
		this->_mem_data._array[_num]
	);
}

//----------------------------------------------------------------------//

/************************************************************************/
/*	ControllerRewrite													*/
/************************************************************************/

//----------------------------------------------------------------------//

ControllerRewrite::ControllerRewrite(const YesNo _is_rewrite_enabled)
{
	this->_is_rewrite_enabled = _is_rewrite_enabled;
}

//----------------------------------------------------------------------//

void ControllerRewrite::Rewrite_base(const uByte _bit, const int _data, const int _and)
{
	if (_is_rewrite_enabled)
	{
		this->_mem_data._all_data &= ~(_and << _bit);
		this->_mem_data._all_data |= (_data << _bit);
	}
}

//----------------------------------------------------------------------//

/************************************************************************/
/*	ControllerPush														*/
/************************************************************************/

//----------------------------------------------------------------------//

ControllerPush::ControllerPush()
{
	_mem_stock._all._btns = 0;
	_mem_stock._all._directions = 0;
}

//----------------------------------------------------------------------//

void ControllerPush::Stock(const DataBit16 _receive_data)
{
	_mem_stock._all._btns = _receive_data;
}

//----------------------------------------------------------------------//

void ControllerPush::Set_btn_data(const DataBit16 _receive_data)
{
	_mem_stock._all._directions = _mem_stock._all._btns;
	
	_mem_stock._all._btns = _receive_data;
}

//----------------------------------------------------------------------//

Btn ControllerPush::Push(const ControllerBtn _bit)
{
	return (Btn)(((_mem_stock._all._btns & (~_mem_stock._all._directions)) >> _bit) & 1);
}

//----------------------------------------------------------------------//

/************************************************************************/

/************************************************************************/
/*	ControllerLCD														*/
/************************************************************************/

//----------------------------------------------------------------------//

ControllerLCD::ControllerLCD()
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

/************************************************************************/
