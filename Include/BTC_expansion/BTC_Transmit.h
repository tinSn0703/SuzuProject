
#pragma once

/************************************************************************/

namespace Bluetooth
{

namespace Bit24
{

/************************************************************************/

#define NUM_CONTROLLER_DATA_24BIT 4

/************************************************************************/

class TransmitCircit
{
//variable
private:
	
	Uart::ModeReceive _uart_controller;
	
	UartData8bit _mem_read_data[NUM_CONTROLLER_DATA_24BIT];
	
	char _data_transmit[10];
	
//function
protected:
	
	void Receive_for_controller();
	
	uByte Get_read_data(uByte _num);
	
	void Turn_on();
	
	void Turn_on(uByte _num);
	
	void Turn_off();
	
	void Turn_off(uByte _num);
	
	void Check_read_data();
	
public:
	
	TransmitCircit(UartNum _uart_num_controller);
	
	void Connect();
	
	void Transmition();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline UartData8bit TransmitCircit::Get_read_data(const uByte _num)
{
	return _mem_read_data[_num];
}

//----------------------------------------------------------------------//

/************************************************************************/

};

};

/************************************************************************/
