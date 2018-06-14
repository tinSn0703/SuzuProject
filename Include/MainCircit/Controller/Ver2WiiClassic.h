
#pragma once

/************************************************************************/

#include "Bit24Controller.h"
#include "ControllerBase/WiiClassicBase.h"

/************************************************************************/

namespace Controller
{

/************************************************************************/

class WiiClassic	: public Bit24Controller
					, public Controller::Base::WiiClassicGet
{
public:
	
	/**
	 *	_uart_num			: �R���g���[�����q�����Ă�UART�̔ԍ�
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	WiiClassic(UartNum _uart_num, YesNo _is_data_rewrite = NO);
	
	/* �R���g���[���̃f�[�^��ǂށB��M�Ɏ��s������ǂݍ��݂͑ł��؂���B */
	void Read();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void WiiClassic :: Read()
{
	Bit24Controller::Read();
}

//----------------------------------------------------------------------//

/************************************************************************/

class WiiClassicAddPush	: public Bit24Controller
						, public Controller::Base::WiiClassicGet
						, public Controller::Base::WiiClassicPush
{
public:
	
	/**
	 *	_uart_num			: �R���g���[�����q�����Ă�UART�̔ԍ�
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	WiiClassicAddPush(UartNum _uart_num, BOOL _is_data_rewrite = NO);
	
	/* �R���g���[���̃f�[�^��ǂށB��M�Ɏ��s������ǂݍ��݂͑ł��؂���B */
	void Read();
};

/************************************************************************/

};

/************************************************************************/
