
#pragma once

#include "Motor_type.h"

/************************************************************************/

namespace ClassMotor
{

/************************************************************************/

class MotorBase
{
//variable
private:
	
	Motor _data;
	
	YesNo _is_signal_reverse :1;
	
//function
protected:
	
	void Initialize();
	
public:
	
	MotorBase()	{}
	
	/* ���[�^�ԍ����Đݒ肷�� */
	void Reset(MotorNum _motor_num);
	
	/* ����𔽓]�����܂��� */
	void Want_to_reverse_signal(YesNo _yes_no);
	
	/* ����͔��]���Ă��܂���? */
	YesNo Is_signal_reverse();
	
	/* PWM��ݒ肷��B */
	void Set(Power _power);
	
	/* �����ݒ肷��B*/
	void Set(Signal _sig);
	
	/* �����PWM��ݒ肷�� */
	void Set(Signal _sig, Power _power);
	
	void Set_steps(StepsMode _steps_mode);
	
	/* ���[�^�[�ԍ���Ԃ� */
	MotorNum Get_number();
	
	/* �����Ԃ� */
	Signal Get_sig();
	
	/* PWM��Ԃ� */
	Pwm Get_pwm();
	
	StepsMode Get_steps_mode();
	
	/* 0�ԃf�[�^��Ԃ� */
	MotorData Get_data_0();
	
	/* 1�ԃf�[�^��Ԃ� */
	MotorData Get_data_1();
};

/************************************************************************/

class MotorOperate : public virtual MotorBase
{
//function
public:
	
	MotorOperate();
	MotorOperate(MotorNum _motor_num, YesNo _is_signal_reverse = NO);
	
	/*
	 * PWM�Ɖ�]�����̐ݒ�BPWM�����̎����]�A���̎��t�]
	 *
	 *	_power	: ���삳����p���[
	 */
	void Drive(Power _power);
	
	/*
	 *	���[�^��P���䂷��B
	 *		_target_value	: �ڕW�l
	 *		_current_value	: ���ݒl
	 *		_denominator	: ����
	 *		_constant		: �萔
	 */
	void Drive_P(double _target_value, double _current_value, double _denominator, double _p_constant);
	
	void operator ++ (int );
	void operator -- (int );
};

/************************************************************************/

class MotorLCD : public virtual MotorBase
{
public:
	
	MotorLCD();
	
	void Display_signal(LcdAdrs _adrs);
	void Display_pwm(LcdAdrs _adrs);
	void Display_steps(LcdAdrs _adrs);
	
	void Display_power(LcdAdrs _adrs);
	
	void Display_data0(LcdAdrs _adrs);
	void Display_data1(LcdAdrs _adrs);
};

/************************************************************************/

#include "MotorBase_inline.h"
#include "MotorLCD_inline.h"

/************************************************************************/

}

/************************************************************************/
