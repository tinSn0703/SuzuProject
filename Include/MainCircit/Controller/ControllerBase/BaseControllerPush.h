
#pragma once

#include "Controller_type.h"

/************************************************************************/

namespace Controller
{
namespace Base
{

/************************************************************************/

class ControllerPush
{
//variable
private:
	
	ControllerCommand _mem_stock;
	
//function
protected:
	
	void Stock(DataBit16 _receive_data);
	
	void Set_btn_data(DataBit16 _receive_data);
	
public:
	
	ControllerPush();
	
	/* Get�Ƃ͈Ⴂ�A�����ꂽ�u�Ԃ̂�YES�ƂȂ�B */
	Btn Push(ControllerBtn _btn);
};

/************************************************************************/

}
}

/************************************************************************/
