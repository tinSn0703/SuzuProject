
#pragma once

/************************************************************************/

#include "ControllerBase/BaseControllerPush.h"

#include "ControllerBase/Ver2BaseControllerBase.h"

#include "ControllerBase/ControllerSingleLine.h"
#include "ControllerBase/ControllerDoubleLine.h"

/************************************************************************/

namespace Controller
{
namespace Ver2
{

/************************************************************************/

template <class Receiver>
class Bit24Controller : public virtual Controller::Base::ControllerPush
{
private:
	
	Receiver _receiver;
	
	Base::Bit24ControllerBase _controller;
	
	ControllerData _receive_data[NUM_CONTROLLER_24BIT];
	
protected:
	
	Base::Bit24ControllerBase * Get_object();
	
public:
	
	Bit24Controller(UartNum _num);
	Bit24Controller(UartNum _num_main, UartNum _num_sub);
	
	void Read();
	
	ControllerError Get_error_state();
};

/************************************************************************/

};
};

/************************************************************************/
