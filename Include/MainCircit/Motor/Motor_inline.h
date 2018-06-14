

#pragma once

//----------------------------------------------------------------------//

inline void Motor :: Clear()
{
	_mem_data._0._sub._sig = SIGNAL_FREE;
	_mem_data._1._sub._pwm = 0;
	
	_mem_data._0._sub._is_steps_on = FALSE;
}

//----------------------------------------------------------------------//

inline void Motor :: Reset(const MotorNum _num)
{
	_mem_data._0._sub._num_md = _mem_data._1._sub._num_md = To_within(_num, 7, 0);
}

//----------------------------------------------------------------------//

inline void Motor :: Set_uart(Uart::ModeTransmit *_uart)
{
	_mem_uart = _uart;
	
	_uart->Enable_9bit();
	
	_mem_is_uart_set = YES;
}

//----------------------------------------------------------------------//

inline Uart::ModeTransmit * Motor :: Get_uart_adrs()
{
	return _mem_uart;
}

//----------------------------------------------------------------------//

inline void Motor :: Write()
{
	Write(*_mem_uart);
}

//----------------------------------------------------------------------//

inline void Motor :: Write_clear()
{
	Write_clear(*_mem_uart);
}

//----------------------------------------------------------------------//

inline Signal Motor :: operator = (const Signal _sig)
{
	Set(_sig);

	return _sig;
}

//----------------------------------------------------------------------//

inline Pwm Motor :: operator  = (const Pwm _pwm)
{
	Set(_pwm);
	
	return _pwm;
}

//----------------------------------------------------------------------//

inline void Motor :: operator += (const Pwm _pwm)
{
	Set(Get_pwm() + _pwm);
}

//----------------------------------------------------------------------//

inline void Motor :: operator -= (const Pwm _pwm)
{
	Set(Get_pwm() - _pwm);
}

//----------------------------------------------------------------------//

inline void Motor :: operator *= (const double _a)
{
	Set(Get_pwm() * _a);
}

//----------------------------------------------------------------------//

inline void Motor :: operator /= (const double _a)
{
	Set(Get_pwm() / _a);
}

//----------------------------------------------------------------------//
