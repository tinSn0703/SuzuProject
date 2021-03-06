
#pragma once

/************************************************************************/
/*	200 : 二号機親機													*/
/************************************************************************/

namespace Physalis
{

namespace Kerberos_chan
{

/************************************************************************/

class Main
{
//variable
private:
	
	Bit24Controller::Dualshock2AddPush _controller;
	
	ThreeOmuni _wheel;
	
	Uart::ModeTransmit _uart_valve;
	
	ValveSingle _valve_catapult_trigger;
	
	ValveSingle _valve_gun_trigger_Veni; //来た
	ValveSingle _valve_gun_trigger_Vidi; //見た
	ValveSingle _valve_gun_trigger_Vici; //勝った
	
	YesNo _is_tirgger_release :1;
	
	YesNo _is_movement_lock :1;
	
//function
private:
	
	void Display_init();
	
	void Control_fire();
	
	void Move();
	
public:
	
	Main();
	
	void Receive_operation();
	
	YesNo Is_movement_lock();
	
	void Work();
	
	void Display();
	
	void Stop();	
	
};

/************************************************************************/

}

}

/************************************************************************/
