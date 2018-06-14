
#pragma once

#include "ValveBase/Valve_type.h"

/************************************************************************/

class ValveSingle : public Counter
{
//variable
private:
	
	YesNo _mem_is_valve_open :1;
	
	ValveNum _mem_valve_number :3;
	
//function
private:
	
	void Toggle();
	
public:
	
	ValveSingle();
	ValveSingle(ValveNum _valve_number);
	
	/* 電磁弁の番号を再設定する。 */
	void Reset(ValveNum _valve_number);
	
	/* 電磁弁の番号を返す */
	ValveNum Get_valve_num();
	
	/* 電磁弁は開いていますか? */
	YesNo Is_open();
	
	/* 電磁弁を開きますか? */
	void Want_to_open(YesNo _yes_no);
	
	/* 一定時間待ってから電磁弁を開く。 */
	void Open_by_time(YesNo _yes_no, mSecond _time_to_open);
	
	/* 電磁弁を開けてから一定時間待ってから閉める。*/
	void Open_and_Close(YesNo _is_open, mSecond _time_to_close);
	
	/* 一定時間待って電磁弁を開けてから一定時間待って閉める。*/
	void Open_and_Close(YesNo _is_open, mSecond _time_to_open, mSecond _time_to_close);
	
	/* 電磁弁を開閉する。*/
	void Open_or_Close(YesNo _want_to_move);
	
	/* 送信する形のデータを返す。 */
	ValveData Get_data();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void ValveSingle::Reset(const ValveNum _valve_slot_number)
{
	_mem_valve_number = _valve_slot_number;
}

//----------------------------------------------------------------------//

inline ValveNum ValveSingle :: Get_valve_num()
{
	return _mem_valve_number;
}

//----------------------------------------------------------------------//

inline YesNo ValveSingle::Is_open()
{
	return _mem_is_valve_open;
}

//----------------------------------------------------------------------//

inline void ValveSingle::Want_to_open(const YesNo _is_open)
{
	_mem_is_valve_open = _is_open;
}

//----------------------------------------------------------------------//

inline void ValveSingle::Toggle()
{
	_mem_is_valve_open = Reversal(_mem_is_valve_open);
}

//----------------------------------------------------------------------//

inline ValveData ValveSingle::Get_data()
{
	return (_mem_is_valve_open << _mem_valve_number);
}

//----------------------------------------------------------------------//

/************************************************************************/
