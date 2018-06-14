
#pragma once

/************************************************************************/

#include "Uart_type.h"
#include "Uart_define.h"

/************************************************************************/

namespace Uart
{

namespace BaseClass
{

/************************************************************************/

class UartBase
{
//variable
private:
	
#if defined(_AVR_IOM640_H_)
	
	UartNum _mem_uart_num :9;
	
#else
	
	UartNum _mem_uart_num :8;
	
#endif
	
//funtion
public:
	
	UartBase(UartNum _uart_num);
	
	/**
	 * @fn UARTの番号を返す
	 */
	UartNum Get_uart_num();
	
	/**
	 * @fn 9bit通信を許可する
	 */
	void Enable_9bit();
	
	/**
	 * @fn 9bit通信を不許可する
	 */
	void Disable_9bit();
	
	/**
	 * @fn 9bit通信は許可されていますか?
	 */
	YesNo Is_enabled_9bit();

	/**
	 * @fn 割り込みを許可する
	 * @param _isr 設定する割り込み
	 */
	void Enable_isr(UartISR _isr);
	
	/**
	 * @fn 割り込みを不許可する
	 * @param _isr 設定する割り込み
	 */
	void Disable_isr(UartISR _isr);
	
	/**
	 * @fn 割り込みは許可されていますか?
	 * @param _isr 確認する割り込み
	 * @return 許可->YES, 不許可->NO
	 */
	YesNo Is_enabled_isr(UartISR _isr);
	
	/**
	 * @fn 割り込みが要求されているか
	 *  @param _isr 確認する割り込み
	 * @return YES->要求, NO->不要
	 */
	YesNo Is_request_isr(UartISR _isr);
};

/************************************************************************/

//----------------------------------------------------------------------//

inline UartNum UartBase :: Get_uart_num()
{
	return _mem_uart_num;
}

//----------------------------------------------------------------------//

/************************************************************************/

};

};

/************************************************************************/
