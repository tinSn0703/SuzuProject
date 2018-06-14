/**
 * @file	MDC.h
 * @brief	MDCクラスの定義
 * @author	Sowa Naoki
 */

#pragma once

#include <MainCircit/Motor/Motor.h>

/**
 * @class MDC
 * MDC回路を操作するためのクラス
 */
class MDC
{
//function
public:
	
	/**
	 * @param _uart_num		このMDCへ送信するためのUARTの番号
	 * @param _num_of_slot	このMDCがいくつのスロットを持つか設定する
	 */
	MDC(UartNum _uart_num, Byte _num_of_slot = 4);
	
	/**
	 * @fn	このMDCのスロット数を返す
	 */
	uByte Get_num_of_slot();
	
	/* オブジェクト内部にある「class UartTransmit」のアドレスを返す */
	Uart::ModeTransmit * Get_uart_adrs();
	
	/* このクラスが使用しているUARTの番号を返す */
	UartNum Get_uart_num();
	
	/* 全てのMDに動作を入力する */
	void Set(Signal _sig);
	
	/* 全てのMDにPWMを入力する */
	void Set(Power _pwm);
	
	/**
	 * @fn	段々について設定する
	 */
	void Set_steps(StepsMode _steps_mode);
	
	/* MDの中で最大のPWMを返す */
	Pwm Get_max_pwm();
	
	/* LCDにMDのパワーを表示する */
	void Display_power(LcdAdrs _adrs);
	
	/* LCDにMDの動作を表示する*/
	void Display_signal(LcdAdrs _adrs);
	
	/* LCDにMDのPWMを表示する*/
	void Display_pwm(LcdAdrs _adrs);
	
	/* LCDにこのMDCの情報を表示する。 */
	void Display_info(LcdAdrs _adrs);
	
	/* MDCにデータを送る */
	void Write();
	
	/* MDCを停止させるデータを送る */
	void Write_clear();
	
	Motor & operator [] (MotorNum _slot);
	
//variable
private:
	
	Uart::ModeTransmit _uart;
	
	uByte _num_of_slot :2;
	
protected:
	
	Motor _motor[4];
};

/************************************************************************/

//----------------------------------------------------------------------//

inline uByte MDC::Get_num_of_slot()
{
	return _num_of_slot;
}

//----------------------------------------------------------------------//

inline Uart::ModeTransmit * MDC::Get_uart_adrs()
{
	return &_uart;
}

//----------------------------------------------------------------------//

inline UartNum MDC::Get_uart_num()
{
	return _uart.Get_uart_num();
}

//----------------------------------------------------------------------//

inline Motor & MDC::operator [] (const MotorNum _slot_num)
{
	return _motor[To_within(_slot_num, _num_of_slot, 0)];
}

//----------------------------------------------------------------------//

/************************************************************************/
