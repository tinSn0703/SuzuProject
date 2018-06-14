
#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <AVR/Uart/Uart.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/ControllerBase/Controller_type.h>
#include <MainCircit/Controller/ControllerBase/ControllerSingleLine.h>

/************************************************************************/

namespace Controller
{

/************************************************************************/

//----------------------------------------------------------------------//

 SingleLine::SingleLine(const UartNum _num, fpStoreData _store, const uByte _num_data_byte)

	: _mem_uart(_num)
	, Store(_store)
{
	for (uByte i = 0; i < _num_data_byte; i++)
	{
		_mem_comparison_flag |= (1 << i);
	}
}

//----------------------------------------------------------------------//

SingleLine::SingleLine(const UartNum _num_0, const UartNum _num_1, fpStoreData _store, const uByte _num_data_byte)

	: _mem_uart(_num_0)
	, Store(_store)
{
	for (uByte i = 0; i < _num_data_byte; i++)
	{
		_mem_comparison_flag |= (1 << i);
	}
}

//----------------------------------------------------------------------//

void SingleLine::Start_timer(const mSecond _m_sec)
{
	if (_mem_counter.Is_running() == NO)
	{
		_mem_counter.Start(_m_sec);
		
		_mem_error = READ_NORMARY;
	}
}

//----------------------------------------------------------------------//

void SingleLine::Finish_timer()
{
	_mem_counter.Finish();
}

//----------------------------------------------------------------------//

YesNo SingleLine::Is_finshed_timer()
{
	if (_mem_counter.Is_finished())
	{
		_mem_error = READ_FAILURE;
		
		return YES;
	}
	
	return NO;
}

//----------------------------------------------------------------------//

void SingleLine::Receive(Uart::ModeReceive &_uart, ControllerData _data[])
{
	for (uByte i = 0, _flag = 0; i < NUM_LIMIT_RECEIVE; i++)
	{
		_mem_counter.Start(TIME_RECEIVE_WAIT);
		
		while (1)
		{
			if (_uart.Is_receive_finished())
			{
				if (_uart.Is_error_happen() == NO)
				{
					_flag |= (*Store)(_uart.Get_UDR_8bit(), _data);
					
					if (_flag == _mem_comparison_flag)
					{
						_mem_error = READ_SUCCESS;
						
						_mem_counter.Finish();
						
						return (void)0;
					}
					
					break;
				}
			}
			else if (_mem_counter.Is_finished())
			{
				break;
			}
		}
	}
	
	_mem_error = READ_INCOMPLETE;
	
	_mem_counter.Finish();
}

//----------------------------------------------------------------------//

void SingleLine::Read(ControllerData _data[])
{
	if (_mem_uart.Is_receive_finished())
	{
		Receive(_mem_uart, _data);
	}
	else
	{
		Start_timer(TIME_READ_ERROR);
		
		if (Is_finshed_timer())
		{
			Finish_timer();
		}
	}
}

//----------------------------------------------------------------------//

ControllerError SingleLine::Get_error_state()
{
	return _mem_error;
}

//----------------------------------------------------------------------//

/************************************************************************/

};

/************************************************************************/
