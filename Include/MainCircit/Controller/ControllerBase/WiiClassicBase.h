
#pragma once

#include "BaseControllerGet.h"
#include "BaseControllerPush.h"

/************************************************************************/

namespace Controller
{

namespace Base
{

/************************************************************************/

class WiiClassicGet : public virtual ControllerGet
{
public:
	
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

inline Btn WiiClassicGet::Get_X()
{
	return _mem_data._command._btn_mark_o;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_B()
{
	return _mem_data._command._btn_mark_u;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet :: Get_A ()
{
	return _mem_data._command._btn_mark_r;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet :: Get_Y ()
{
	return _mem_data._command._btn_mark_l;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet :: Get_R ()
{
	return _mem_data._command._btn_right_0;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet :: Get_ZR ()
{
	return _mem_data._command._btn_right_1;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_L()
{
	return _mem_data._command._btn_left_0;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_ZL()
{
	return _mem_data._command._btn_left_1;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_HOME()
{
	return _mem_data._command._btn_other_0;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_START()
{
	return _mem_data._command._btn_start;
}

//----------------------------------------------------------------------//

inline Btn WiiClassicGet::Get_SELECT()
{
	return _mem_data._command._btn_select;
}

//----------------------------------------------------------------------//

/************************************************************************/

class WiiClassicPush : public virtual ControllerPush
{
public:
	
	Btn Push_X();
	Btn Push_B();
	Btn Push_A();
	Btn Push_Y();
	
	Btn Push_R();
	Btn Push_ZR();
	
	Btn Push_L();
	Btn Push_ZL();
	
	Btn Push_HOME();
	
	Btn Push_START();
	Btn Push_SELECT();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_X()
{
	return Push(BTN_X);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_B()
{
	return Push(BTN_B);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_A()
{
	return Push(BTN_A);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_Y()
{
	return Push(BTN_Y);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_R()
{
	return Push(BTN_R);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_ZR()
{
	return Push(BTN_ZR);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_L()
{
	return Push(BTN_L);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_ZL()
{
	return Push(BTN_ZL);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_HOME()
{
	return Push(BTN_HOME);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_START()
{
	return Push(BTN_START);
}

//----------------------------------------------------------------------//

inline Btn WiiClassicPush::Push_SELECT()
{
	return Push(BTN_SELECT);
}

//----------------------------------------------------------------------//

/************************************************************************/

};

};

/************************************************************************/
