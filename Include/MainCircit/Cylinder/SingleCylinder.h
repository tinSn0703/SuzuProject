
#pragma once

#include "Cylinder_type.h"

class SingleCylinder
{
public:
	
	SingleCylinder();
	SingleCylinder(ValveNum _num);
	
	void Reset(ValveNum _num);
	
	/**
	 * @fn �V�����_��L�΂�
	 * @param _is_done �������܂�?
	 * @param _wait_time �V�����_��L�΂��܂ł̎���
	 */
	void Lengthen(YesNo _is_done, mSecond _wait_time = 0);
	
	/**
	 * @fn �d���ق��J������
	 * @param _is_done �������܂�?
	 * @param _wait_time �d���ق��J������܂ł̑҂�����
	 */
	void Open(YesNo _is_done, mSecond _wait_time = 0);
	
	/**
	 * @fn �d���ق̔ԍ���Ԃ�
	 */
	ValveNum Get_num();
	
	/**
	 * @fn �d���ق̃f�[�^��Ԃ�
	 */
	ValveData Get_data();
	
	/**
	 * @fn �V�����_�̏�Ԃ�Ԃ�
	 */
	CylinderState Get_state();
	
private:
	
	Valve _valve;
	
	Counter _counter;
	
	CylinderState _state;
};

