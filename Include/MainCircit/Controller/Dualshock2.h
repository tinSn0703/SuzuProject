
#pragma once

/************************************************************************/

#include "Bit24Controller.h"
#include "ControllerBase/Dualshock2Base.h"

/************************************************************************/

namespace Controller
{

/************************************************************************/

class Dualshock2	: public Bit24Controller
					, public Controller::Base::Dualshock2Get
{
public:
	
	/**
	 *	_uart_num			: �R���g���[�����q�����Ă�UART�̔ԍ�
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	Dualshock2(UartNum _uart_num, YesNo _is_data_rewrite = NO);
	
	/* �R���g���[���̃f�[�^��ǂށB*/
	void Read();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void Dualshock2::Read()
{
	Bit24Controller::Read();
}

//----------------------------------------------------------------------//

/************************************************************************/

class Dualshock2AddPush	: public Bit24Controller
						, public Controller::Base::Dualshock2Get
						, public Controller::Base::Dualshock2Push
{
public:
	
	/**
	 *	_uart_num			: �R���g���[�����q�����Ă�UART�̔ԍ�
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	Dualshock2AddPush(UartNum _uart_num, YesNo _is_data_rewrite = NO);
	
	/* �R���g���[���̃f�[�^��ǂށB */
	void Read();
};

/************************************************************************/

}

/************************************************************************/
