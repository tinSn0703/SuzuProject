
#pragma once

/************************************************************************/

#include "Ver2Bit24Controller.h"
#include "ControllerBase/Ver2BaseControllerRewrite.h"
#include "ControllerBase/Dualshock2Base.h"
#include "ControllerBase/Ver2Dualshock2Base.h"

/************************************************************************/

namespace Controller
{
namespace Ver2
{

/************************************************************************/

template <class Receiver>
class Dualshock2	: public Controller::Ver2::Bit24Controller<Receiver>
					, public Controller::Ver2::Base::ControllerRewrite
					, public Controller::Ver2::Base::Dualshock2Get
					, public Controller::Base::Dualshock2Push
{
public:
	
	/**
	 *	_uart_num			: �R���g���[�����q�����Ă�UART�̔ԍ�
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	Dualshock2(UartNum _uart, YesNo _is_data_rewrite = NO);
	Dualshock2(UartNum _uart_main, UartNum _uart_sub, YesNo _is_data_rewrite = NO);
};

/************************************************************************/

}
}

/************************************************************************/
