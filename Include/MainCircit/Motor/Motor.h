
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
	 * _motor_num			: ���[�^�ԍ�
	 * _is_signal_reverse	: ���씽�]�����܂�?
	 */
	Motor(MotorNum _motor_num, YesNo _is_signal_reverse = NO);
	
	/* ���[�^�̓���f�[�^���폜���� */
	void Clear();
	
	/* MD�Ƀf�[�^�𑗂� */
	void Write(Uart::ModeTransmit *_uart);
	
	/* MD�Ƀf�[�^�𑗂� */
	void Write(Uart::ModeTransmit &_uart);
	
	/* MD�ɒ�~�̃f�[�^�𑗂� */
	void Write_clear(Uart::ModeTransmit *_uart);
	
	/* MD�ɒ�~�̃f�[�^�𑗂� */
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
