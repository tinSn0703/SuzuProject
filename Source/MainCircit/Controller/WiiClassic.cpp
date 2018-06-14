

#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <AVR/Uart/Uart.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/WiiClassic.h>

/************************************************************************/

namespace Controller
{

/************************************************************************/

//----------------------------------------------------------------------//

WiiClassic::WiiClassic(const UartNum _uart_num, const BOOL _is_poss_rewrite)

	: Bit24Controller(_uart_num, _is_poss_rewrite)
{
	
}

//----------------------------------------------------------------------//

/************************************************************************/

//----------------------------------------------------------------------//

WiiClassicAddPush::WiiClassicAddPush(const UartNum _uart_num, const BOOL _is_poss_rewrite)

	: Bit24Controller(_uart_num, _is_poss_rewrite)
{
	
}

//----------------------------------------------------------------------//

void WiiClassicAddPush::Read()
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
