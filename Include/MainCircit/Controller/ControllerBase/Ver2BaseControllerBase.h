
#pragma once

/************************************************************************/

#include "Controller_type.h"

/************************************************************************/

namespace Controller
{
namespace Ver2
{
namespace Base
{

/************************************************************************/

class Bit24ControllerBase
{
//variable
public:
	
	Controller::Base::ControllerCommand _data;
	
//function
public:
	
	Bit24ControllerBase();
	
	void Allot(ControllerData _data[NUM_CONTROLLER_24BIT]);
	
	/* �f�[�^���������� */
	void Clear();
	
	YesNo Is_commnad_push();
};

/************************************************************************/

};
};
};

/************************************************************************/
