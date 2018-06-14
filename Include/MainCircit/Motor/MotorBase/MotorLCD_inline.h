

#pragma once

/************************************************************************/

//----------------------------------------------------------------------//

inline void MotorLCD::Display_signal(const LcdAdrs _adrs)
{
	LCD::Write(_adrs, Get_sig(), 1, DECIMAL_10);
}

//----------------------------------------------------------------------//

inline void MotorLCD::Display_pwm(const LcdAdrs _adrs)
{
	LCD::Write(_adrs, Get_pwm(), 2, DECIMAL_10);
}

//----------------------------------------------------------------------//

inline void MotorLCD::Display_steps(const LcdAdrs _adrs)
{
	LCD::Write(_adrs, Get_steps_mode(), 1, DECIMAL_10);
}

//----------------------------------------------------------------------//

inline void MotorLCD::Display_data0(const LcdAdrs _adrs)
{
	LCD::Write(_adrs, Get_data_0(), 9, DECIMAL_02);
}

//----------------------------------------------------------------------//

inline void MotorLCD::Display_data1(const LcdAdrs _adrs)
{
	LCD::Write(_adrs, Get_data_1(), 9, DECIMAL_02);
}

//----------------------------------------------------------------------//

/************************************************************************/
