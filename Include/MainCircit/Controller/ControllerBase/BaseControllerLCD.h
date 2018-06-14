
#pragma once

/************************************************************************/

#include "BaseControllerGet.h"

/************************************************************************/

namespace Controller
{
namespace Base
{

/************************************************************************/

class ControllerLCD : public virtual ControllerGet
{
public:
	
	ControllerLCD();
	
	void Display(LcdAdrs _adrs);
	void Display(LcdAdrs _adrs, uByte _num);
	
	void Display(LcdAdrs _adrs, ControllerBtn _command);
	void Display(LcdAdrs _adrs, ControllerDirecX _command);
	void Display(LcdAdrs _adrs, ControllerDirecY _command);
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void ControllerLCD::Display(const LcdAdrs _adrs)
{
	LCD::Write(_adrs, ControllerGet::Get_data(), 6, DECIMAL_16);
}

//----------------------------------------------------------------------//

inline void ControllerLCD::Display(const LcdAdrs _adrs, const uByte _num)
{
	LCD::Write(_adrs, ControllerGet::Get_data(_num), 2, DECIMAL_16);
}

//----------------------------------------------------------------------//

inline void ControllerLCD::Display(const LcdAdrs _adrs, const ControllerBtn _command)
{
	LCD::Write(_adrs, ControllerGet::operator () (_command), 1, DECIMAL_10);
}

//----------------------------------------------------------------------//

inline void ControllerLCD::Display(const LcdAdrs _adrs, const ControllerDirecX _command)
{
	LCD::Write(_adrs, ControllerGet::operator () (_command), 1, DECIMAL_10);
}

//----------------------------------------------------------------------//

inline void ControllerLCD::Display(const LcdAdrs _adrs, const ControllerDirecY _command)
{
	LCD::Write(_adrs, ControllerGet::operator () (_command), 1, DECIMAL_10);
}

//----------------------------------------------------------------------//

/************************************************************************/

}
}

/************************************************************************/
