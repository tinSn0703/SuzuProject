
#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <AVR/Uart/Uart.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/Dualshock2.h>

/************************************************************************/

namespace Controller
{

/************************************************************************/

//----------------------------------------------------------------------//

Dualshock2::Dualshock2(const UartNum _uart_num, const YesNo _is_data_rewrite)

	: Bit24Controller(_uart_num, _is_data_rewrite)
{}

//----------------------------------------------------------------------//

/************************************************************************/

Dualshock2AddPush::Dualshock2AddPush(const UartNum _uart_num, const YesNo _is_data_rewrite)

	: Bit24Controller(_uart_num, _is_data_rewrite)
{}

//----------------------------------------------------------------------//

void Dualshock2AddPush::Read()
{
	Stock(_mem_data._all._directions);
	
	Bit24Controller::Read();
	
	if (Get_error_state() == READ_SUCCESS)
	{
		Set_btn_data(_mem_data._all._directions);
	}
}

//----------------------------------------------------------------------//

/************************************************************************/

}

/************************************************************************/
