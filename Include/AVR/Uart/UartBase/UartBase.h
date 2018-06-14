
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
	 * @fn UART�̔ԍ���Ԃ�
	 */
	UartNum Get_uart_num();
	
	/**
	 * @fn 9bit�ʐM��������
	 */
	void Enable_9bit();
	
	/**
	 * @fn 9bit�ʐM��s������
	 */
	void Disable_9bit();
	
	/**
	 * @fn 9bit�ʐM�͋�����Ă��܂���?
	 */
	YesNo Is_enabled_9bit();

	/**
	 * @fn ���荞�݂�������
	 * @param _isr �ݒ肷�銄�荞��
	 */
	void Enable_isr(UartISR _isr);
	
	/**
	 * @fn ���荞�݂�s������
	 * @param _isr �ݒ肷�銄�荞��
	 */
	void Disable_isr(UartISR _isr);
	
	/**
	 * @fn ���荞�݂͋�����Ă��܂���?
	 * @param _isr �m�F���銄�荞��
	 * @return ����->YES, �s����->NO
	 */
	YesNo Is_enabled_isr(UartISR _isr);
	
	/**
	 * @fn ���荞�݂��v������Ă��邩
	 *  @param _isr �m�F���銄�荞��
	 * @return YES->�v��, NO->�s�v
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
