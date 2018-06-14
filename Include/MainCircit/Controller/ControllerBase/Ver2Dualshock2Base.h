
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

class Dualshock2Get : public ControllerLCD
{
public:
	
	Dualshock2Get(Bit24ControllerBase *_object);
	
	Btn Get_Triangle();
	Btn Get_Cross();
	Btn Get_Circle();
	Btn Get_Square();
	
	Btn Get_R1();
	Btn Get_R2();
	Btn Get_R3();
	
	Btn Get_L1();
	Btn Get_L2();
	Btn Get_L3();
	
	Btn Get_START();
	Btn Get_SELECT();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline Dualshock2Get::Dualshock2Get(Bit24ControllerBase *_object)

	: ControllerLCD(_object)
{}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_Triangle()
{
	return _controller_data->_data._command._btn_mark_o;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_Cross()
{
	return _controller_data->_data._command._btn_mark_u;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_Circle()
{
	return _controller_data->_data._command._btn_mark_r;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_Square()
{
	return _controller_data->_data._command._btn_mark_l;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_R1()
{
	return _controller_data->_data._command._btn_right_0;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_R2()
{
	return _controller_data->_data._command._btn_right_1;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_R3()
{
	return _controller_data->_data._command._btn_other_1;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_L1()
{
	return _controller_data->_data._command._btn_left_0;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_L2()
{
	return _controller_data->_data._command._btn_left_1;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_L3()
{
	return _controller_data->_data._command._btn_other_0;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_START()
{
	return _controller_data->_data._command._btn_start;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_SELECT()
{
	return  _controller_data->_data._command._btn_select;
}

//----------------------------------------------------------------------//

/************************************************************************/

}
}
}

/************************************************************************/
