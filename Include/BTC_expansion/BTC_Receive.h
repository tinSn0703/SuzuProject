
#pragma once

/************************************************************************/

namespace Bluetooth
{

namespace Bit24
{

namespace ReceiveCircit
{
	
/************************************************************************/
	
#define NUM_CONTROLLER_DATA_24BIT 4
	
/************************************************************************/
	
	void Initialize();
	
	void Connect();
	
	void Reconnect();
	
	void Read();
	
	uByte Get_read_data(uByte _num);
	
	void Turn_on();
	
	void Turn_on(uByte _num);
	
	void Turn_on_more(uByte _byte);
	
	void Turn_off();
	
	void Turn_off(uByte _num);
	
	void Turn_off_more(uByte _byte);
	
	void Check_read_data();
	
/************************************************************************/
	
};

};

};

/************************************************************************/
