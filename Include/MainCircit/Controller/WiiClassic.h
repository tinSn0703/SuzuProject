
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
	 *	_uart_num			: コントローラが繋がってるUARTの番号
	 *	_is_data_rewrite	: 送られてきたデータを書き換えますか?
	**/
	WiiClassic(UartNum _uart_num, YesNo _is_data_rewrite = NO);
	
	/* コントローラのデータを読む。受信に失敗したら読み込みは打ち切られる。 */
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
	 *	_uart_num			: コントローラが繋がってるUARTの番号
	 *	_is_data_rewrite	: 送られてきたデータを書き換えますか?
	**/
	WiiClassicAddPush(UartNum _uart_num, BOOL _is_data_rewrite = NO);
	
	/* コントローラのデータを読む。受信に失敗したら読み込みは打ち切られる。 */
	void Read();
};

/************************************************************************/

};

/************************************************************************/
