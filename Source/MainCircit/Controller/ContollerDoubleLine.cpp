
#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <AVR/Uart/Uart.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/ControllerBase/Controller_type.h>
#include <MainCircit/Controller/ControllerBase/ControllerSingleLine.h>
#include <MainCircit/Controller/ControllerBase/ControllerDoubleLine.h>

namespace Controller
{

/************************************************************************/

//----------------------------------------------------------------------//

DoubleLine::DoubleLine
(
	const UartNum	_uart_num, 
	fpStoreData		_store,
	const uByte		_num_data_byte
)
	: SingleLine(_uart_num, _store, _num_data_byte)
	, _mem_uart_sub(_uart_num)
{
	_mem_is_main_line_use = YES;
}

//----------------------------------------------------------------------//

DoubleLine::DoubleLine
(
	const UartNum	_uart_num_main, 
	const UartNum	_uart_num_sub,
	fpStoreData		_store, 
	const uByte		_num_data_byte
)
	: SingleLine(_uart_num_main, _store, _num_data_byte)
	, _mem_uart_sub(_uart_num_sub)
{
	_mem_is_main_line_use = YES;
}

//----------------------------------------------------------------------//

void DoubleLine::Read(ControllerData _data[])
{
	if (_mem_uart.Is_receive_finished())
	{
		SingleLine::Receive(_mem_uart, _data);
		
		if (SingleLine::Get_error_state() == READ_INCOMPLETE)
		{
			if (_mem_uart_sub.Is_receive_finished())
			{
				SingleLine::Receive(_mem_uart_sub, _data);
			}
		}
	}
	else
	{
		if (_mem_uart_sub.Is_receive_finished())
		{
			SingleLine::Receive(_mem_uart_sub, _data);
		}
		else
		{
			SingleLine::Start_timer(TIME_READ_ERROR_DOUBLE);
			
			if (SingleLine::Is_finshed_timer())
			{
				SingleLine::Finish_timer();
			}
		}
	}
}

//----------------------------------------------------------------------//

//----------------------------------------------------------------------//

/************************************************************************/

}

/************************************************************************/
