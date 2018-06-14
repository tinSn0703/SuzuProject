
#pragma once

#include "ValveBase/Valve_type.h"

/************************************************************************/

/*	ダブルソレノイドの電磁弁用	*/
class ValveDouble
{
//variable
private:
	
	Counter _timer;
	
	OpenClose _state_valveNC :1;
	OpenClose _state_valveNO :1;
	
	ValveNum _num_valveNC :3;
	ValveNum _num_valveNO :3;
	
	DoubleValve _next_moved_valve :1; 
	
//function
private:
	
	void Toggle();
		
	void Safety();
	
public:
	
	ValveDouble(ValveNum _valveA_number, ValveNum _valveB_number);
	
	/* 電磁弁の番号を再設定する */
	void Reset(ValveNum _valveA_number, ValveNum _valveB_number);
	
	ValveNum Get_num_valveNC();
	ValveNum Get_num_valveNO();
	
	OpenClose Get_state_valveNC();
	OpenClose Get_state_valveNO();
	
	OpenClose Get_state(DoubleValve _select);
	
	/**
	 * @fn NCの電磁弁の開閉する。
	 */
	void Set_NC(OpenClose _yes_no);
	
	/**
	 * @fn NOの電磁弁の開閉する。
	 */
	void Set_NO(OpenClose _yes_no);
	
	void Set(OpenClose _is_A_open, OpenClose _is_B_open);
	
	void Set(DoubleValve _select, OpenClose _is_open);
	
	void Open(YesNo _want_to_move);
	
	void Open(YesNo _want_to_move, mSecond _wait_time);
	
	void Open_and_Close(YesNo _is_move, mSecond _close_time);
	
	void Open_and_Close(YesNo _is_move, mSecond _open_time, mSecond _close_time);
	
	void Open_valve_A(YesNo _want_to_move);
	
	void Open_valve_B(YesNo _want_to_move);
	
	/* 送信する形のデータを返す */
	ValveData Get_data();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void ValveDouble::Reset
(
	const ValveNum _valveA_num, 
	const ValveNum _valveB_num
)
{
	_num_valveNC = _valveA_num;
	_num_valveNO = _valveB_num;
}

//----------------------------------------------------------------------//

inline ValveNum ValveDouble::Get_num_valveNC()
{
	return _num_valveNC;
}

//----------------------------------------------------------------------//

inline ValveNum ValveDouble::Get_num_valveNO()
{
	return _num_valveNO;
}

//----------------------------------------------------------------------//

inline YesNo ValveDouble::Get_state_valveNC()
{
	return _state_valveNC;
}

//----------------------------------------------------------------------//

inline YesNo ValveDouble::Get_state_valveNO()
{
	return _state_valveNO;
}

//----------------------------------------------------------------------//

inline void ValveDouble::Set_NC(const YesNo _yes_no)
{
	_state_valveNC = _yes_no;
}

//----------------------------------------------------------------------//

inline void ValveDouble::Set_NO(const YesNo _yes_no)
{
	_state_valveNO = _yes_no;
}

//----------------------------------------------------------------------//

inline void ValveDouble::Set(const YesNo _is_NC_open, const YesNo _is_NO_open)
{
	_state_valveNC = _is_NC_open;
	_state_valveNO = _is_NO_open;
	
	Safety();
}

//----------------------------------------------------------------------//

inline ValveData ValveDouble :: Get_data()
{
	return 
	(
		(_state_valveNC << _num_valveNC) |
		(_state_valveNO << _num_valveNO)
	);
}

//----------------------------------------------------------------------//

/************************************************************************/
