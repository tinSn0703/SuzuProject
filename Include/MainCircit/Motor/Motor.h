
#pragma once

/************************************************************************/

#include "MotorBase/MotorBase.h"

/************************************************************************/

class Motor	:	public ClassMotor::MotorOperate
			,	public ClassMotor::MotorLCD
{
//function
public:
	
	Motor();
	
	/* 
	 * _motor_num			: モータ番号
	 * _is_signal_reverse	: 動作反転させます?
	 */
	Motor(MotorNum _motor_num, YesNo _is_signal_reverse = NO);
	
	/* モータの動作データを削除する */
	void Clear();
	
	/* MDにデータを送る */
	void Write(Uart::ModeTransmit *_uart);
	
	/* MDにデータを送る */
	void Write(Uart::ModeTransmit &_uart);
	
	/* MDに停止のデータを送る */
	void Write_clear(Uart::ModeTransmit *_uart);
	
	/* MDに停止のデータを送る */
	void Write_clear(Uart::ModeTransmit &_uart);
	
	Signal	operator  = (Signal _sig);
	Pwm		operator  = (Pwm _pwm);
	void	operator += (Pwm _pwm);
	void	operator -= (Pwm _pwm);
	void	operator *= (double _a);
	void	operator /= (double _a);
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void Motor::Clear()
{
	Initialize();
	
	Want_to_reverse_signal(NO);
}

//----------------------------------------------------------------------//

inline Signal Motor::operator = (const Signal _sig)
{
	Set(_sig);

	return _sig;
}

//----------------------------------------------------------------------//

inline Pwm Motor::operator  = (const Pwm _pwm)
{
	Set(_pwm);
	
	return _pwm;
}

//----------------------------------------------------------------------//

inline void Motor::operator += (const Pwm _pwm)
{
	Set(Get_pwm() + _pwm);
}

//----------------------------------------------------------------------//

inline void Motor::operator -= (const Pwm _pwm)
{
	Set(Get_pwm() - _pwm);
}

//----------------------------------------------------------------------//

inline void Motor::operator *= (const double _a)
{
	Set(Get_pwm() * _a);
}

//----------------------------------------------------------------------//

inline void Motor::operator /= (const double _a)
{
	Set(Get_pwm() / _a);
}

//----------------------------------------------------------------------//

inline BOOL operator == (Motor &_arg_motor , const Signal _arg_sig)
{
	return (_arg_motor.Get_sig() == _arg_sig ? TRUE : FALSE);
}

//----------------------------------------------------------------------//

inline BOOL operator != (Motor &_arg_motor , const Signal _arg_sig)
{
	return (_arg_motor.Get_sig() != _arg_sig ? TRUE : FALSE);
}

//----------------------------------------------------------------------//

/************************************************************************/
