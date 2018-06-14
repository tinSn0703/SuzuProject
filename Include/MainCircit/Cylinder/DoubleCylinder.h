
#pragma once

#include "Cylinder_type.h"

class DoubleCylinder
{
public:
	
	DoubleCylinder();
	DoubleCylinder(ValveNum _num);
	DoubleCylinder(ValveNum _num_NC, ValveNum _num_NO);
	
	void Reset(ValveNum _num);
	void Reset(ValveNum _num_NC, ValveNum _num_NO);
	
	void Reset(DoubleValve _valve, ValveNum _num);
	
	/**
	 * @fn シリンダを伸ばす
	 * @param _is_done 動かします?
	 * @param _wait_time シリンダを伸ばすまでの時間
	 */
	void Lengthen(YesNo _is_done, mSecond _wait_time = 0);
	
	/**
	 * @fn シリンダを縮める
	 * @param _is_done 動かします?
	 * @param _wait_time シリンダを縮めるまでの時間
	 */
	void Shorten(YesNo _is_done, mSecond _wait_time = 0);
	
	/**
	 * @fn 電磁弁を開放する
	 * @param _is_done 動かします?
	 * @param _wait_time 電磁弁を開放するまでの待ち時間
	 */
	void Open(YesNo _is_done, mSecond _wait_time = 0);
	
	/**
	 * @fn 電磁弁の番号を返す
	 */
	ValveNum Get_num(DoubleValve _valve = VALVE_NC);
	
	/**
	 * @fn 電磁弁のデータを返す
	 */
	ValveData Get_data();
	
	/**
	 * @fn シリンダの状態を返す
	 */
	CylinderState Get_state();
	
private:
	
	Valve _valve_NC;
	Valve _valve_NO;
	
	Counter _counter;
	
	CylinderState _state;
};
