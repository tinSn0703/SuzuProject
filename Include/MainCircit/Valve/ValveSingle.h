
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
	
	/* �d���ق̔ԍ����Đݒ肷��B */
	void Reset(ValveNum _valve_number);
	
	/* �d���ق̔ԍ���Ԃ� */
	ValveNum Get_valve_num();
	
	/* �d���ق͊J���Ă��܂���? */
	YesNo Is_open();
	
	/* �d���ق��J���܂���? */
	void Want_to_open(YesNo _yes_no);
	
	/* ��莞�ԑ҂��Ă���d���ق��J���B */
	void Open_by_time(YesNo _yes_no, mSecond _time_to_open);
	
	/* �d���ق��J���Ă����莞�ԑ҂��Ă���߂�B*/
	void Open_and_Close(YesNo _is_open, mSecond _time_to_close);
	
	/* ��莞�ԑ҂��ēd���ق��J���Ă����莞�ԑ҂��ĕ߂�B*/
	void Open_and_Close(YesNo _is_open, mSecond _time_to_open, mSecond _time_to_close);
	
	/* �d���ق��J����B*/
	void Open_or_Close(YesNo _want_to_move);
	
	/* ���M����`�̃f�[�^��Ԃ��B */
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
