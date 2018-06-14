
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
	
	YesNo _mem_is_error_happen :1;	//��M�G���[�̋L�^
	
//function
private:
	
	void Check_error();
	
public:
	
	ModeReceive(UartNum _uart_num);
	
	/* ��M���������܂�����? */
	YesNo Is_receive_finished();
	
	/* ��M�������� */
	void Enable_receive();
	
	/* ��M��s������ */
	void Disable_receive();
	
	/**
	 *	��M���ɃG���[���N�������ǂ������m�F���邽�߂̊֐�
	 *	���ʂ͎�M�ォ�玟�Ɏ�M����܂ŕێ������
	**/
	YesNo Is_error_happen();
	
	/* UDR0~7���o�͂���  */
	UartData8bit Get_UDR_8bit();
	
	/* UDR0~8���o�͂���  */
	UartData9bit Get_UDR_9bit();
	
	/* 8bit�̃f�[�^����M���A���̃f�[�^���o�͂��� */
	UartData8bit Receive_8bit();
	
	/* 9bit�̃f�[�^����M���A���̃f�[�^���o�͂��� */
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
	
	/* ���M�\�ȏ�Ԃł���? */
	YesNo Is_transmit_possible();
	
	/* ���M�������� */
	void Enable_transmit();
	
	/* ���M��s������ */
	void Disable_transmit();
	
	/* ���͂��ꂽ�f�[�^��8bit���M���� */
	void Transmit_8bit(UartData8bit _uart_data);
	
	/* ���͂��ꂽ�f�[�^��9bit���M���� */
	void Transmit_9bit(UartData9bit _uart_data);
};

/************************************************************************/

}

/************************************************************************/
