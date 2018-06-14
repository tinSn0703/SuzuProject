
#pragma once

#include "BaseControllerGet.h"
#include "BaseControllerPush.h"

/************************************************************************/

namespace Controller
{
namespace Base
{

/************************************************************************/

class Dualshock2Get : public virtual ControllerGet
{
public:
	
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

inline Btn Dualshock2Get::Get_Triangle()
{
	return _mem_data._command._btn_mark_o;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_Cross()
{
	return _mem_data._command._btn_mark_u;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_Circle()
{
	return _mem_data._command._btn_mark_r;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_Square()
{
	return _mem_data._command._btn_mark_l;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_R1()
{
	return _mem_data._command._btn_right_0;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_R2()
{
	return _mem_data._command._btn_right_1;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_R3()
{
	return _mem_data._command._btn_other_1;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_L1()
{
	return _mem_data._command._btn_left_0;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_L2()
{
	return _mem_data._command._btn_left_1;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_L3()
{
	return _mem_data._command._btn_other_0;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_START()
{
	return _mem_data._command._btn_start;
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Get::Get_SELECT()
{
	return _mem_data._command._btn_select;
}

//----------------------------------------------------------------------//

/************************************************************************/

class Dualshock2Push : public virtual ControllerPush
{
public:
	
	Btn Push_Triangle();
	Btn Push_Cross();
	Btn Push_Circle();
	Btn Push_Square();
	
	Btn Push_R1();
	Btn Push_R2();
	Btn Push_R3();
	
	Btn Push_L1();
	Btn Push_L2();
	Btn Push_L3();
	
	Btn Push_START();
	Btn Push_SELECT();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_Triangle()
{
	return Push(BTN_TRI);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_Cross()
{
	return Push(BTN_CRO);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_Circle()
{
	return Push(BTN_CIR);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_Square()
{
	return Push(BTN_SQU);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_R1()
{
	return Push(BTN_R1);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_R2()
{
	return Push(BTN_R2);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_R3()
{
	return Push(BTN_R3);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_L1()
{
	return Push(BTN_L1);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_L2()
{
	return Push(BTN_L2);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_L3()
{
	return Push(BTN_L3);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_START()
{
	return Push(BTN_START);
}

//----------------------------------------------------------------------//

inline Btn Dualshock2Push::Push_SELECT()
{
	return Push(BTN_SELECT);
}

//----------------------------------------------------------------------//

/************************************************************************/

}

}

/************************************************************************/
