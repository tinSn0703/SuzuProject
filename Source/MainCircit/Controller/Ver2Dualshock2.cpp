
#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <AVR/Uart/Uart.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/Ver2Dualshock2.h>

/************************************************************************/

namespace Controller
{
namespace Ver2
{

/************************************************************************/

template class Dualshock2<Controller::SingleLine>;
template class Dualshock2<Controller::DoubleLine>;

/************************************************************************/

//----------------------------------------------------------------------//

template <class Receiver>
Dualshock2<Receiver>::Dualshock2(const UartNum _uart_num, const YesNo _is_data_rewrite)

	: Controller::Ver2::Bit24Controller<Receiver>(_uart_num)
	, Controller::Ver2::Base::ControllerRewrite(this->Get_object(), _is_data_rewrite)
	, Controller::Ver2::Base::Dualshock2Get(this->Get_object())
{
	
}

//----------------------------------------------------------------------//

template <class Receiver>
Dualshock2<Receiver>::Dualshock2(const UartNum _uart_main, const UartNum _uart_sub, const YesNo _is_data_rewrite)

	: Controller::Ver2::Bit24Controller<Receiver>(_uart_main, _uart_sub)
	, Controller::Ver2::Base::ControllerRewrite(this->Get_object(), _is_data_rewrite)
	, Controller::Ver2::Base::Dualshock2Get(this->Get_object())
{
	
}

//----------------------------------------------------------------------//

/************************************************************************/

}
}

/************************************************************************/
