

#pragma once

/************************************************************************/

typedef Byte Pwm;
typedef sint Power;

/************************************************************************/

typedef usint MotorData;
typedef Byte MotorNum;

/************************************************************************/

typedef enum 
{
	STEPS_NON = 0b000,
	STEPS_USE = 0b001,
	
	STEPS_MIN  = 0b010,
	STEPS_HELF = 0b100,
	STEPS_VOID = 0b110,
	
	STEPS_02MS = 0b001,
	STEPS_04MS = 0b011,
	STEPS_08MS = 0b101,
	STEPS_16MS = 0b111,
}
StepsMode;

namespace ClassMotor
{

/************************************************************************/

typedef enum
{
	MD_DATA_0 = 0,
	MD_DATA_1 = 1
}
MdDigit;

/************************************************************************/

//MDに送信するデータのクラス
struct Motor
{
	//MDに送信するデータ。その0。
	union MotorData0
	{
		struct MotorParts0
		{
			Signal		_sig			:2; //0,1
			//YesNo		_is_steps_on	:1; //2
			StepsMode	_steps_mode		:3; //2,3,4
			MdDigit		_num_data		:1;	//5
			MotorNum	_num_md			:3; //6,7,8
		}
		_sub;
		
		MotorData _all :9;
	}
	_0;
	
	//MDに送信するデータ。その1。
	union MotorData1
	{
		struct MotorParts1
		{
			Pwm			_pwm		:5; //0,1,2,3,4
			MdDigit		_num_data	:1;	//5
			MotorNum	_num_md		:3; //6,7,8
		}
		_sub;
		
		MotorData _all :9;
	}
	_1;
};

/************************************************************************/

};

/************************************************************************/
