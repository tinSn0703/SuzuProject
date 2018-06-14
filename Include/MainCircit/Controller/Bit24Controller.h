
#pragma once

/************************************************************************/

#include "ControllerBase/BaseControllerRewrite.h"
#include "ControllerBase/BaseControllerLCD.h"

/************************************************************************/

namespace Controller
{

/************************************************************************/

class Bit24Controller	: public Controller::Base::ControllerRewrite
						, public Controller::Base::ControllerLCD
{
//variable
private:
	
	ControllerError _mem_error_state :2;
	
	ControllerData _mem_receive_data[NUM_CONTROLLER_24BIT];
	
	CountValue _mem_timer;
	
protected:
	
	Uart::ModeReceive _mem_uart;
	
//function
public:
	
	/**
	 *	_uart_num			: コントローラが繋がってるUARTの番号
	 *	_is_data_rewrite	: 送られてきたデータを書き換えますか?
	**/
	Bit24Controller(UartNum _uart_num, YesNo _is_data_rewrite = NO);
	
	/* エラーの状況を返す */
	ControllerError Get_error_state();
	
	void Read();
	
protected:
	
	void Receive(Uart::ModeReceive &_uart);
	
	void Allot();
	
	void Start_timer(mSecond _time);
	
	void Stop_timer();
	
	YesNo Is_timer_finish();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline ControllerError Bit24Controller::Get_error_state()
{
	return _mem_error_state;
}

//----------------------------------------------------------------------//

/************************************************************************/

};

/************************************************************************/
