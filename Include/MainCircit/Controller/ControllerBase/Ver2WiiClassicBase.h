
#pragma once

#include "Ver2BaseControllerLCD.h"

/************************************************************************/

namespace Controller
{
namespace Ver2
{
namespace Base
{

/************************************************************************/

class WiiClassicGet : public ControllerLCD
{
public:
	
	WiiClassicGet(Bit24ControllerBase *_object);
	
	Btn Get_X();
	Btn Get_B();
	Btn Get_A();
	Btn Get_Y();
	
	Btn Get_R();
	Btn Get_ZR();
	
	Btn Get_L();
	Btn Get_ZL();
	
	Btn Get_HOME();
	
	Btn Get_START();
	Btn Get_SELECT();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline WiiClassicGet::WiiClassicGet(Bit24ControllerBase *_object)

	: ControllerLCD(_object)
{
	
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_X()
{
	return _controller_data->_data._command._btn_mark_o;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_B()
{
	return _controller_data->_data._command._btn_mark_u;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_A()
{
	return _controller_data->_data._command._btn_mark_r;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_Y()
{
	return _controller_data->_data._command._btn_mark_l;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_R()
{
	return _controller_data->_data._command._btn_right_0;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_ZR()
{
	return _controller_data->_data._command._btn_right_1;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_L()
{
	return _controller_data->_data._command._btn_left_0;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_ZL()
{
	return _controller_data->_data._command._btn_left_1;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_HOME()
{
	return _controller_data->_data._command._btn_other_0;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_START()
{
	return _controller_data->_data._command._btn_start;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_SELECT()
{
	return _controller_data->_data._command._btn_select;
}

//----------------------------------------------------------------------//

/************************************************************************/

};
};
};

/************************************************************************/
