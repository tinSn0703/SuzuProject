
#pragma once

/************************************************************************/

#include "ValveBase/Valve_type.h"

/************************************************************************/

class Valve
{
public:
	
	Valve();
	Valve(ValveNum _num);
	
	/**
	 * @fn 電磁弁の番号を再設定する
	 * @param _num : 再設定する番号
	 */
	void Reset(ValveNum _num);
	
	/**
	 * @fn 電磁弁の開閉を設定する
	 * @param _open_or_close : 開閉
	 */
	void Set(OpenClose _open_or_close);
	
	/**
	 * @fn 電磁弁を開く
	 * @param _is_done : 開きますか?
	 */
	void Open(YesNo _is_done);
	
	/**
	 * @fn 電磁弁を閉める
	 * @param _is_done : 閉めますか?
	 */
	void Close(YesNo _is_done);
	
	/**
	 * @fn 電磁弁の番号を返す
	 */
	ValveNum Get_num();
	
	/**
	 * @fn 電磁弁のデータを返す
	 */
	ValveData Get_data();
	
	/**
	 * @fn 電磁弁の状態を返す
	 */
	OpenClose Get_state();
	
private:
	
	ValveNum _num :3;
	
	OpenClose _state :1;
	
	YesNo _is_move_enabled :1;
};

/************************************************************************/
