/*
 * TecnicSteer.h
 *
 * Created: 2017/12/21 12:27:36
 *  Author: 錫
 *
 * 技術開発 四輪ステア
 */ 

#pragma once

#include <MainCircit/MainCircit.h>

/************************************************************************/

namespace Off2017
{
namespace Akiduki
{
namespace TecnicSteer
{

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
	
	FourSteer _wheel;
	
	Controller::Dualshock2 _controller;
	
	CountValue _timer_lcd_reset;
	
	YesNo _is_unlock :1;
};

/************************************************************************/

}
}
}

/************************************************************************/
