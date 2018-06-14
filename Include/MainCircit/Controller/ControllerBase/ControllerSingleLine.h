
#pragma once

/************************************************************************/

#include "Controller_type.h"

namespace Controller
{

/************************************************************************/

class SingleLine
{
public:
	
	typedef uByte (*fpStoreData)(UartData8bit , ControllerData []);
	
private:
	
	uByte _mem_comparison_flag;
	
	Counter _mem_counter;
	
	ControllerError _mem_error :2;
	
	fpStoreData Store;
	
protected:
	
	Uart::ModeReceive _mem_uart;
	
protected:
	
	void Start_timer(mSecond _m_sec);
	
	void Finish_timer();
	
	YesNo Is_finshed_timer();
	
	void Receive(Uart::ModeReceive &_uart, ControllerData _data[]);
	
public:
	
	SingleLine(UartNum _num, fpStoreData _store, uByte _num_data_byte);
	SingleLine(UartNum _num_0, UartNum _num_1, fpStoreData _store, uByte _num_data_byte);

	void Read(ControllerData _data[]);

	ControllerError Get_error_state();
};

/************************************************************************/

}

/************************************************************************/
