/*
 * SelfPosition.h
 *
 * Created: 2018/03/26 13:04:19
 *  Author: FUJITSU
 */ 

#pragma once

#include <MainCircit/MainCircit.h>

/************************************************************************/

namespace Off2017
{
namespace Akiduki
{
namespace SelfPosition
{

/************************************************************************/

class WheelSelfPosition : public FourOmuni
{
public:
	
	WheelSelfPosition(UartNum _uart_receiver, UartNum _uart_mdc);
	
	void Set_target(double _x, double _y);
	void Set_target_x(double _x);
	void Set_target_y(double _y);
	
	void Read();
	
	void Move_auto();
	
	void Display_verocity(LcdAdrs _adrs, FourWheelPlace _place);
	
	void Display_x(LcdAdrs _adrs);
	void Display_y(LcdAdrs _adrs);
	void Display_rot(LcdAdrs _adrs);
	
	void operator () (double _x, double _y);
	
private:
	
	double Extract_element_x();
	double Extract_element_y();
	double Extract_element_rot();
	
private:
	
	Uart::ModeReceive _uart_encoder;
	
	UartData8bit _receive_data[8];
	
	double _element_x;
	double _element_y;
	double _element_rot;
	
	double _target_element_x;
	double _target_element_y;
	
	double _verocity[4];
};

/************************************************************************/

class Main
{
//function
public:
	
	Main();
	
	void Input();
	
	void Process();
	
	void Output();
	
//variable
private:
	
	Controller::WiiClassic _controller;
	
	WheelSelfPosition _wheel;
	
	int _num_display;
	
	YesNo _is_unlock :1;
};

/************************************************************************/

}
}
}

/************************************************************************/
