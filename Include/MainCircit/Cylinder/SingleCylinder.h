
#pragma once

#include "Cylinder_type.h"

class SingleCylinder
{
public:
	
	SingleCylinder();
	SingleCylinder(ValveNum _num);
	
	void Reset(ValveNum _num);
	
	/**
	 * @fn シリンダを伸ばす
	 * @param _is_done 動かします?
	 * @param _wait_time シリンダを伸ばすまでの時間
	 */
	void Lengthen(YesNo _is_done, mSecond _wait_time = 0);
	
	/**
	 * @fn 電磁弁を開放する
	 * @param _is_done 動かします?
	 * @param _wait_time 電磁弁を開放するまでの待ち時間
	 */
	void Open(YesNo _is_done, mSecond _wait_time = 0);
	
	/**
	 * @fn 電磁弁の番号を返す
	 */
	ValveNum Get_num();
	
	/**
	 * @fn 電磁弁のデータを返す
	 */
	ValveData Get_data();
	
	/**
	 * @fn シリンダの状態を返す
	 */
	CylinderState Get_state();
	
private:
	
	Valve _valve;
	
	Counter _counter;
	
	CylinderState _state;
};

