
/*************************************************************************
  500 5���@ �}�V��1(����)
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
	
	
	
	/* ����̓��b�N����Ă��܂���? */
	YesNo _is_movement_lock :1;
	
//function
private:
	
	void Work_wheel();
	
	
	
public:
	
	Main();
	
	/* main��H�ւ̓��� */
	void Input();
	
	/* ���͂̏����B�o�͂ւ̕ϊ� */
	void Process();
	
	/* ����H�Ȃǂւ̏o�� */
	void Output();
};

/************************************************************************/

}

}

/************************************************************************/