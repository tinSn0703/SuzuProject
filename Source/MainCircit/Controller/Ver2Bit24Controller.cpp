
#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <AVR/Uart/Uart.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/Ver2Bit24Controller.h>

/************************************************************************/

namespace Controller
{
namespace Ver2
{

/************************************************************************/

template class Bit24Controller<Controller::SingleLine>;
template class Bit24Controller<Controller::DoubleLine>;

/************************************************************************/

static uByte Store_Bit24(const UartData8bit _receive_data, ControllerData _controller_data[])
{
	_controller_data[(_receive_data >> 6) & 3] = _receive_data;
	
	return (1 << ((_receive_data >> 6) & 3));
}

/************************************************************************/

//----------------------------------------------------------------------//

template <class Receiver>
Bit24Controller<Receiver>::Bit24Controller(const UartNum _num)
	
	: _receiver(_num, Store_Bit24, 4)
{
	_receive_data[0] = 0x3f;
	_receive_data[1] = 0x7f;
	_receive_data[2] = 0x8f;
	_receive_data[3] = 0xc0;
}

//----------------------------------------------------------------------//

template <class Receiver>
Bit24Controller<Receiver>::Bit24Controller(const UartNum _num_main, const UartNum _num_sub)
	
	: _receiver(_num_main, _num_sub, Store_Bit24, 4)
{
	_receive_data[0] = 0x3f;
	_receive_data[1] = 0x7f;
	_receive_data[2] = 0x8f;
	_receive_data[3] = 0xc0;
}

//----------------------------------------------------------------------//

template <class Receiver>
Base::Bit24ControllerBase * Bit24Controller<Receiver>::Get_object()
{
	return &_controller;
}

//----------------------------------------------------------------------//

template <class Receiver>
void Bit24Controller<Receiver>::Read()
{
	ControllerPush::Stock(_controller._data._all._btns);
	
	_receiver.Read(_receive_data);
	
	_controller.Allot(_receive_data);
	
	if (_controller.Is_commnad_push())
	{
		ControllerPush::Set_btn_data(_controller._data._all._btns);
	}
}

//----------------------------------------------------------------------//

template <class Receiver>
ControllerError Bit24Controller<Receiver>::Get_error_state()
{
	return _receiver.Get_error_state();
}

//----------------------------------------------------------------------//

/************************************************************************/

};
};

/************************************************************************/
