
#include <akilcd/akilcd.h>
#include <Others/BOOL.h>
#include <AVR/Timer/Counter.h>
#include <AVR/Uart/Uart.h>
#include <MainCircit/Valve/ValveSingle.h>

/************************************************************************/

#define WAIT_MS_TIME 50

/************************************************************************/

//----------------------------------------------------------------------//

ValveSingle::ValveSingle()
{
	_mem_is_valve_open = NO;
}

//----------------------------------------------------------------------//

ValveSingle::ValveSingle(const ValveNum _valve_num)
{
	_mem_valve_number = _valve_num;
	
	_mem_is_valve_open = NO;
}

//----------------------------------------------------------------------//

void ValveSingle::Open_by_time(const YesNo _is_open, const mSecond _time_to_open)
{
	if (_is_open & ~Is_running())	//Timer�X�^�[�g
	{
		Start(_time_to_open);
	}
	
	if (Is_finished())	//�J�E���g����
	{
		Want_to_open(YES);
		
		if (_is_open == NO)
		{
			Finish();
		}
	}
}

//----------------------------------------------------------------------//

void ValveSingle::Open_and_Close(const YesNo _is_open, const mSecond _time_to_close)
{
	if (_is_open & ~Is_running())	//�J���B
	{
		Want_to_open(YES);
		
		Start(_time_to_close);
	}
	
	if (Is_finished())	//����B
	{
		Want_to_open(NO);
		
		if (_is_open == NO)
		{
			Finish();
		}
	}
}

//----------------------------------------------------------------------//

void ValveSingle::Open_and_Close(const YesNo _want_to_move, const mSecond _time_to_open, const mSecond _time_to_close)
{
	if (_want_to_move & ~Is_running()) //Open�܂ł̃^�C�}�J�n
	{
		Start(_time_to_open);
	}
	
	if (Is_finished()) //�J�E���g����
	{
		if (Is_open() == NO)
		{
			Want_to_open(YES); //Open
			
			Start(_time_to_close); //Close�܂ł̃^�C�}�J�n
		}
		else
		{
			Want_to_open(NO); //Close
			
			if (_want_to_move == NO) //�S���슮���B���ɓ�����悤��
			{
				Finish();
			}
		}
	}
}

//----------------------------------------------------------------------//

void ValveSingle::Open_or_Close(const YesNo _want_to_moved)
{
	if (_want_to_moved & ~Is_running())	//�J����B
	{
		Toggle();
		
		Start(WAIT_MS_TIME);
	}
	
	if (Is_finished() & ~_want_to_moved)
	{
		Finish();
	}
}

//----------------------------------------------------------------------//

/************************************************************************/
