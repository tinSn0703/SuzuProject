
#pragma once

namespace Controller
{

/************************************************************************/

class DoubleLine : public SingleLine
{
private:
	
	Uart::ModeReceive _mem_uart_sub;
	
	YesNo _mem_is_main_line_use :1;
	
public:
	
	DoubleLine(UartNum _num, fpStoreData _store, uByte _num_data_byte);
	DoubleLine(UartNum _num_main, UartNum _num_sub, fpStoreData _store, uByte _num_data_byte);
	
	void Read(ControllerData _data[]);
};

/************************************************************************/

}
