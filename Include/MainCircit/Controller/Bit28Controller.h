
#pragma once

/************************************************************************/

#include "ControllerBase/BaseControllerRewrite.h"
#include "ControllerBase/BaseControllerLCD.h"

/************************************************************************/

namespace Controller
{

/************************************************************************/

class Bit28Controller	: public Controller::Base::ControllerRewrite
						, public Controller::Base::ControllerLCD
{
//variable
private:
	
	Uart::ModeReceive _mem_uart;
	
	YesNo _mem_is_stick_lx_high :1;
	YesNo _mem_is_stick_ly_high :1;
	
	YesNo _mem_is_stick_rx_high :1;
	YesNo _mem_is_stick_ry_high :1;
	
//function
private:
	
	void Allot(const UartData8bit _data[NUM_CONTROLLER_28BIT]);
	
public:
	
	Bit28Controller(UartNum _uart_num);
	Bit28Controller(UartNum _uart_num, YesNo _is_poss_rewrite);
	
	void Clear();
	
	YesNo Is_stick_Lx_high();
	YesNo Is_stick_Ly_high();
	
	YesNo Is_stick_Rx_high();
	YesNo Is_stick_Ry_high();
	
	void Read();
	void Read(Uart::ModeReceive &_uart);
};

/************************************************************************/

//----------------------------------------------------------------------//

inline YesNo Bit28Controller::Is_stick_Lx_high()
{
	return _mem_is_stick_lx_high;
}

//----------------------------------------------------------------------//

inline YesNo Bit28Controller::Is_stick_Ly_high()
{
	return _mem_is_stick_ly_high;
}

//----------------------------------------------------------------------//

inline YesNo Bit28Controller::Is_stick_Rx_high()
{
	return _mem_is_stick_rx_high;
}

//----------------------------------------------------------------------//

inline YesNo Bit28Controller::Is_stick_Ry_high()
{
	return _mem_is_stick_ry_high;
}

//----------------------------------------------------------------------//

inline void Bit28Controller::Read()
{
	Read(_mem_uart);
}

//----------------------------------------------------------------------//

/************************************************************************/

}

/************************************************************************/
