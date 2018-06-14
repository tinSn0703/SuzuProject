
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
	
	/* モータ番号を再設定する */
	void Reset(MotorNum _motor_num);
	
	/* 動作を反転させますか */
	void Want_to_reverse_signal(YesNo _yes_no);
	
	/* 動作は反転していますか? */
	YesNo Is_signal_reverse();
	
	/* PWMを設定する。 */
	void Set(Power _power);
	
	/* 動作を設定する。*/
	void Set(Signal _sig);
	
	/* 動作とPWMを設定する */
	void Set(Signal _sig, Power _power);
	
	void Set_steps(StepsMode _steps_mode);
	
	/* モーター番号を返す */
	MotorNum Get_number();
	
	/* 動作を返す */
	Signal Get_sig();
	
	/* PWMを返す */
	Pwm Get_pwm();
	
	StepsMode Get_steps_mode();
	
	/* 0番データを返す */
	MotorData Get_data_0();
	
	/* 1番データを返す */
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
	 * PWMと回転方向の設定。PWMが正の時正転、負の時逆転
	 *
	 *	_power	: 動作させるパワー
	 */
	void Drive(Power _power);
	
	/*
	 *	モータをP制御する。
	 *		_target_value	: 目標値
	 *		_current_value	: 現在値
	 *		_denominator	: 分母
	 *		_constant		: 定数
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
