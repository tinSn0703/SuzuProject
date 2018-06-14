/**
 * @file	MDC.h
 * @brief	MDC�N���X�̒�`
 * @author	Sowa Naoki
 */

#pragma once

#include <MainCircit/Motor/Motor.h>

/**
 * @class MDC
 * MDC��H�𑀍삷�邽�߂̃N���X
 */
class MDC
{
//function
public:
	
	/**
	 * @param _uart_num		����MDC�֑��M���邽�߂�UART�̔ԍ�
	 * @param _num_of_slot	����MDC�������̃X���b�g�������ݒ肷��
	 */
	MDC(UartNum _uart_num, Byte _num_of_slot = 4);
	
	/**
	 * @fn	����MDC�̃X���b�g����Ԃ�
	 */
	uByte Get_num_of_slot();
	
	/* �I�u�W�F�N�g�����ɂ���uclass UartTransmit�v�̃A�h���X��Ԃ� */
	Uart::ModeTransmit * Get_uart_adrs();
	
	/* ���̃N���X���g�p���Ă���UART�̔ԍ���Ԃ� */
	UartNum Get_uart_num();
	
	/* �S�Ă�MD�ɓ������͂��� */
	void Set(Signal _sig);
	
	/* �S�Ă�MD��PWM����͂��� */
	void Set(Power _pwm);
	
	/**
	 * @fn	�i�X�ɂ��Đݒ肷��
	 */
	void Set_steps(StepsMode _steps_mode);
	
	/* MD�̒��ōő��PWM��Ԃ� */
	Pwm Get_max_pwm();
	
	/* LCD��MD�̃p���[��\������ */
	void Display_power(LcdAdrs _adrs);
	
	/* LCD��MD�̓����\������*/
	void Display_signal(LcdAdrs _adrs);
	
	/* LCD��MD��PWM��\������*/
	void Display_pwm(LcdAdrs _adrs);
	
	/* LCD�ɂ���MDC�̏���\������B */
	void Display_info(LcdAdrs _adrs);
	
	/* MDC�Ƀf�[�^�𑗂� */
	void Write();
	
	/* MDC���~������f�[�^�𑗂� */
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
