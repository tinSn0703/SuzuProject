
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
	 * @fn �d���ق̔ԍ����Đݒ肷��
	 * @param _num : �Đݒ肷��ԍ�
	 */
	void Reset(ValveNum _num);
	
	/**
	 * @fn �d���ق̊J��ݒ肷��
	 * @param _open_or_close : �J��
	 */
	void Set(OpenClose _open_or_close);
	
	/**
	 * @fn �d���ق��J��
	 * @param _is_done : �J���܂���?
	 */
	void Open(YesNo _is_done);
	
	/**
	 * @fn �d���ق�߂�
	 * @param _is_done : �߂܂���?
	 */
	void Close(YesNo _is_done);
	
	/**
	 * @fn �d���ق̔ԍ���Ԃ�
	 */
	ValveNum Get_num();
	
	/**
	 * @fn �d���ق̃f�[�^��Ԃ�
	 */
	ValveData Get_data();
	
	/**
	 * @fn �d���ق̏�Ԃ�Ԃ�
	 */
	OpenClose Get_state();
	
private:
	
	ValveNum _num :3;
	
	OpenClose _state :1;
	
	YesNo _is_move_enabled :1;
};

/************************************************************************/
