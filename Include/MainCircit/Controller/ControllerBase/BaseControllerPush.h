
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
	
	/* Getとは違い、押された瞬間のみYESとなる。 */
	Btn Push(ControllerBtn _btn);
};

/************************************************************************/

}
}

/************************************************************************/
