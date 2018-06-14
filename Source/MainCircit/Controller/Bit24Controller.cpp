
#include <akilcd/akilcd.h>
#include <Others/Others.h>
#include <AVR/Uart/Uart.h>
#include <AVR/Timer/GeneralTimer.h>
#include <AVR/Timer/Counter.h>
#include <MainCircit/Direction.h>
#include <MainCircit/Controller/Bit24Controller.h>

/************************************************************************/

namespace Controller
{

/************************************************************************/

//----------------------------------------------------------------------//

Bit24Controller::Bit24Controller(const UartNum _uart_num, const BOOL _is_data_rewrite)

	: ControllerRewrite(_is_data_rewrite)
	, _mem_uart(_uart_num)
{
	_mem_error_state = READ_NORMARY;
	
	_mem_timer = TIMER_INITAL_VALUE;
	
	_mem_receive_data[0] = 0x3f;
	_mem_receive_data[1] = 0x7f;
	_mem_receive_data[2] = 0x8f;
	_mem_receive_data[3] = 0xc0;
}

//----------------------------------------------------------------------//

void Bit24Controller::Allot()
{
	this->_mem_data._command._cross_x	= To_DirectionX((Is_true_the(_mem_receive_data[0], 5) << 1) | Is_true_the(_mem_receive_data[1], 1));
	this->_mem_data._command._cross_y	= To_DirectionY((Is_true_the(_mem_receive_data[0], 4) << 1) | Is_true_the(_mem_receive_data[1], 0));
	
	this->_mem_data._command._stick_right_x	= To_DirectionX(_mem_receive_data[2] >> 4);
	this->_mem_data._command._stick_right_y	= To_DirectionY(_mem_receive_data[3] >> 0);
	
	this->_mem_data._command._stick_left_x	= To_DirectionX(_mem_receive_data[3] >> 2);
	this->_mem_data._command._stick_left_y	= To_DirectionY(_mem_receive_data[3] >> 4);
	
	this->_mem_data._btns._other = ((~_mem_receive_data[0]) & 0x0f);
	
	this->_mem_data._btns._right_left = ((~_mem_receive_data[1] >> 2) & 0x0f);
	
	this->_mem_data._btns._mark = ((~_mem_receive_data[2]) & 0x0f);
}

//----------------------------------------------------------------------//

void Bit24Controller::Receive(Uart::ModeReceive &_uart)
{
	for (uByte i = 0, _flag = 0; i < NUM_LIMIT_RECEIVE; i++) //��M�񐔐��� ���펞�͑��5����x�ŏI�����܂��B
	{
		_mem_timer = Timer::General::Set_counter(TIME_RECEIVE_WAIT); //��M�̐��۔��f�̃^�C�}�J�n
		
		while (1)
		{
			if (_uart.Is_receive_finished())	//��M�����B
			{
				const UartData8bit _temp = _uart.Get_UDR_8bit();	//��M�f�[�^���󂯎��
				
				if (_mem_uart.Is_error_happen() == NO)	//��M���Ƀg���u���������������m�F
				{
					_mem_receive_data[((_temp >> 6) & 3)] = _temp;
					
					_flag |= (1 << ((_temp >> 6) & 3));
					
					if (_flag == 0x0f)	//�S�Ă̎�M������
					{
						_mem_error_state = READ_SUCCESS;
						
						_mem_timer = TIMER_INITAL_VALUE;
						
						return (void)0;
					}
					else	//���̎�M�Ɉڂ�
					{
						break;
					}
				}
			}
			else if (Timer::General::Is_current_bigger_than(_mem_timer)) //��M���s �ЂƂ܂����Ɉڂ�B
			{
				break;
			}
		}
	}
	
	_mem_error_state = READ_INCOMPLETE;
	
	_mem_timer = TIMER_INITAL_VALUE;
}

//----------------------------------------------------------------------//

void Bit24Controller::Start_timer(const mSecond _time)
{
	if (_mem_timer == TIMER_INITAL_VALUE)	//��M�s�𔻒f���邽�߂̃^�C�}���J�n
	{
		_mem_timer = Timer::General::Set_counter(_time);
		
		_mem_error_state = READ_NORMARY;
	}
}

//----------------------------------------------------------------------//

void Bit24Controller::Stop_timer()
{
	_mem_timer = TIMER_INITAL_VALUE;
}

//----------------------------------------------------------------------//

YesNo Bit24Controller::Is_timer_finish()
{
	if (Timer::General::Is_current_bigger_than(_mem_timer))	//��M�s�Ɣ��f
	{
		_mem_error_state = READ_FAILURE;
		
		return YES;
	}
	
	return NO;
}

//----------------------------------------------------------------------//

void Bit24Controller::Read()
{
	if (_mem_uart.Is_receive_finished()) //�f�[�^�̓ǂݎ��ɓ���邩���m�F
	{
		Receive(_mem_uart);
		
		Allot();
	}
	else
	{
		Start_timer(TIME_READ_ERROR);
		
		if (Is_timer_finish())
		{
			Stop_timer();
		}
	}
}

//----------------------------------------------------------------------//

/************************************************************************/

};

/************************************************************************/
