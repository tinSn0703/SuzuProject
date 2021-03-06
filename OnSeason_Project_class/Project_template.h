
/*************************************************************************
  プロジェクトのテンプレート。 定義。
*************************************************************************/

#pragma once

/************************************************************************/

namespace Template
{

/************************************************************************/

class Main
{
//variable
private:
	
	Controller::Bit24::Dualshock2 _controller;
	
	FourWheel _wheel;
	
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

/************************************************************************/
