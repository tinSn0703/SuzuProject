
/*************************************************************************
  500 5号機 マシン1(万里)
*************************************************************************/

#pragma once

/************************************************************************/

namespace Gerbera
{

namespace Banri
{

/************************************************************************/

class Main
{
//variable
private:
	
	Bit24Controller::WiiClassicAddPush _controller;
	
	Mechanum _wheel;
	
	
	
	/* 動作はロックされていますか? */
	YesNo _is_movement_lock :1;
	
//function
private:
	
	void Work_wheel();
	
	
	
public:
	
	Main();
	
	/* main回路への入力 */
	void Input();
	
	/* 入力の処理。出力への変換 */
	void Process();
	
	/* 他回路などへの出力 */
	void Output();
};

/************************************************************************/

}

}

/************************************************************************/
