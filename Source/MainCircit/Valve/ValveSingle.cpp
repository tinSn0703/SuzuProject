
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
	if (_is_open & ~Is_running())	//Timerスタート
	{
		Start(_time_to_open);
	}
	
	if (Is_finished())	//カウント完了
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
	if (_is_open & ~Is_running())	//開く。
	{
		Want_to_open(YES);
		
		Start(_time_to_close);
	}
	
	if (Is_finished())	//閉じる。
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
	if (_want_to_move & ~Is_running()) //Openまでのタイマ開始
	{
		Start(_time_to_open);
	}
	
	if (Is_finished()) //カウント完了
	{
		if (Is_open() == NO)
		{
			Want_to_open(YES); //Open
			
			Start(_time_to_close); //Closeまでのタイマ開始
		}
		else
		{
			Want_to_open(NO); //Close
			
			if (_want_to_move == NO) //全動作完了。次に動けるように
			{
				Finish();
			}
		}
	}
}

//----------------------------------------------------------------------//

void ValveSingle::Open_or_Close(const YesNo _want_to_moved)
{
	if (_want_to_moved & ~Is_running())	//開閉する。
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
