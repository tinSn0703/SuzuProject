

#pragma once

/************************************************************************/
/*	MotorBase															*/
/************************************************************************/

//----------------------------------------------------------------------//

inline void MotorBase::Initialize()
{
	_data._0._all = 0;
	_data._1._all = 0;
	
	_data._0._sub._num_data = MD_DATA_0;
	_data._1._sub._num_data = MD_DATA_1;
	
	_is_signal_reverse = NO;
}

//----------------------------------------------------------------------//

inline void MotorBase::Reset(const MotorNum _num)
{
	_data._0._sub._num_md = _data._1._sub._num_md = To_within(_num, 7, 0);
}

//----------------------------------------------------------------------//

inline MotorNum MotorBase::Get_number()
{
	return _data._0._sub._num_md;
}

//----------------------------------------------------------------------//

inline Signal MotorBase::Get_sig()
{
	return _data._0._sub._sig;
}

//----------------------------------------------------------------------//

inline Pwm MotorBase::Get_pwm()
{
	return (Is_Signal_stop(Get_sig()) ? 0 : _data._1._sub._pwm);
}

//----------------------------------------------------------------------//

inline StepsMode MotorBase::Get_steps_mode()
{
	return _data._0._sub._steps_mode;
}

//----------------------------------------------------------------------//

inline MotorData MotorBase::Get_data_0()
{
	return (_is_signal_reverse ? (_data._0._all & 0x1fc) | Reversal(Get_sig()) : _data._0._all);
}

//----------------------------------------------------------------------//

inline MotorData MotorBase::Get_data_1()
{
	return (Is_Signal_stop(Get_sig()) ? _data._1._all & 0x1e0 : _data._1._all);
}

//----------------------------------------------------------------------//

inline void MotorBase::Set(const Power _power)
{
	_data._1._sub._pwm = (To_within(_power, 31, 0));
}

//----------------------------------------------------------------------//

inline void MotorBase::Set(const Signal _sig)
{
	_data._0._sub._sig = _sig;
}

//----------------------------------------------------------------------//

inline void MotorBase::Set(const Signal _sig, const Power _power)
{
	_data._0._sub._sig = _sig;
	_data._1._sub._pwm = (To_within(_power, 31, 0));
}

//----------------------------------------------------------------------//

inline void MotorBase::Set_steps(const StepsMode _steps_mode)
{
	_data._0._sub._steps_mode = _steps_mode;
}

//----------------------------------------------------------------------//

inline void MotorBase::Want_to_reverse_signal(const YesNo _yes_no)
{
	_is_signal_reverse = _yes_no;
}

//----------------------------------------------------------------------//

inline YesNo MotorBase::Is_signal_reverse()
{
	return _is_signal_reverse;
}

//----------------------------------------------------------------------//


