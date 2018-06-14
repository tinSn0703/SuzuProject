
#pragma once

/************************************************************************/

#include "UartBase/UartBase.h"
#include "Uart_func.h"

/************************************************************************/

namespace Uart
{

/************************************************************************/

class ModeReceive : public BaseClass::UartBase
{
//variable
private:
	
	YesNo _mem_is_error_happen :1;	//受信エラーの記録
	
//function
private:
	
	void Check_error();
	
public:
	
	ModeReceive(UartNum _uart_num);
	
	/* 受信が完了しましたか? */
	YesNo Is_receive_finished();
	
	/* 受信を許可する */
	void Enable_receive();
	
	/* 受信を不許可する */
	void Disable_receive();
	
	/**
	 *	受信時にエラーが起きたかどうかを確認するための関数
	 *	結果は受信後から次に受信するまで保持される
	**/
	YesNo Is_error_happen();
	
	/* UDR0~7を出力する  */
	UartData8bit Get_UDR_8bit();
	
	/* UDR0~8を出力する  */
	UartData9bit Get_UDR_9bit();
	
	/* 8bitのデータを受信し、そのデータを出力する */
	UartData8bit Receive_8bit();
	
	/* 9bitのデータを受信し、そのデータを出力する */
	UartData9bit Receive_9bit();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline YesNo ModeReceive :: Is_error_happen()
{
	return _mem_is_error_happen;
}

//----------------------------------------------------------------------//

/************************************************************************/

class ModeTransmit : public BaseClass::UartBase
{
public:
	
	ModeTransmit(UartNum _uart_num);
	
	/* 送信可能な状態ですか? */
	YesNo Is_transmit_possible();
	
	/* 送信を許可する */
	void Enable_transmit();
	
	/* 送信を不許可する */
	void Disable_transmit();
	
	/* 入力されたデータを8bit送信する */
	void Transmit_8bit(UartData8bit _uart_data);
	
	/* 入力されたデータを9bit送信する */
	void Transmit_9bit(UartData9bit _uart_data);
};

/************************************************************************/

}

/************************************************************************/
