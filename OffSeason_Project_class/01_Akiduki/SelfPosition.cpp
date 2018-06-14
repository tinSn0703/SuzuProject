/*
 * SelfPosition.cpp
 *
 * Created: 2018/03/26 13:04:32
 *  Author: FUJITSU
 */ 

#include <math.h>

#include "SelfPosition.h"

/************************************************************************/

namespace Off2017
{
namespace Akiduki
{
namespace SelfPosition
{

/************************************************************************/

#define INIT_LED()	DDRA = 0xff; PORTA = 0x00

#define PORT_LED	PORTA

#define LED_STATE_LOCK		0x00
#define LED_STATE_UNLOCK	0x0f

/************************************************************************/

//----------------------------------------------------------------------//

WheelSelfPosition::WheelSelfPosition(UartNum _num_uart_receiver, UartNum _num_uart_mdc)

	: FourOmuni(_num_uart_mdc)
	, _uart_encoder(_num_uart_receiver)
{
	_target_element_x = 0;
	_target_element_y = 0;
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Set_target(double _x, double _y)
{
	_target_element_x = _x;
	_target_element_y = _y;
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Set_target_x(double _x)
{
	_target_element_x = _x;
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Set_target_y(double _y)
{
	_target_element_y = _y;
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Read()
{
	uchar _flag = 0x00;
	
	while (_flag != 0xff)
	{
		const UartData8bit _temp = _uart_encoder.Receive_8bit();
		
		_receive_data[(_temp >> 5) & 0b111] = _temp;
		
		_flag |= (1 << ((_temp >> 5) & 0b111));
	}
	
	if (_receive_data[2] & (1 << 3))	_element_x = 0 - Extract_element_x();
	else								_element_x = 0 + Extract_element_x();
	
	if (_receive_data[5] & (1 << 2))	_element_y = 0 - Extract_element_y();
	else								_element_y = 0 + Extract_element_y();
	
	if (_receive_data[7] & (1 << 4))	_element_rot = 0 - Extract_element_rot();
	else								_element_rot = 0 + Extract_element_rot();
}

//----------------------------------------------------------------------//

double WheelSelfPosition::Extract_element_x()
{
	return (double)((_receive_data[0] & 0x1f) + ((_receive_data[1] & 0x1f) << 5) + ((_receive_data[2] & 0x07) << 10));
}

//----------------------------------------------------------------------//

double WheelSelfPosition::Extract_element_y()
{
	return (double)(((_receive_data[2] & 0x10) >> 4) + ((_receive_data[3] & 0x1f) << 1) + ((_receive_data[4] & 0x1f) << 6) + ((_receive_data[5] & 0x03) << 11));
}

//----------------------------------------------------------------------//

double WheelSelfPosition::Extract_element_rot()
{
	return (double)(((_receive_data[5] & 0x18) >> 3) + ((_receive_data[6] & 0x1f) << 2) + ((_receive_data[7] & 0x0f) << 7));
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Move_auto()
{
	const double _deg = (_element_rot / 10) + atan2(_target_element_y - _element_y, _target_element_x - _element_x) * DEG_PER_RAD;
	
	Move(_deg);
	
	_verocity[WheelPlace::FRONT_RIGHT] = (Get_pwm() * sin((_deg -  45) * RAD_PER_DEG));
	_verocity[WheelPlace::BACK_RIGHT ] = (Get_pwm() * sin((_deg - 135) * RAD_PER_DEG));
	_verocity[WheelPlace::BACK_LEFT  ] = (Get_pwm() * sin((_deg - 225) * RAD_PER_DEG));
	_verocity[WheelPlace::FRONT_LEFT ] = (Get_pwm() * sin((_deg - 315) * RAD_PER_DEG));
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Display_verocity(LcdAdrs _adrs, FourWheelPlace _place)
{
	LCD::Write_integer(_adrs, (long)(_verocity[_place] * 1000), 8, DECIMAL_10);
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Display_x(LcdAdrs _adrs)
{
	LCD::Write_integer(_adrs, (long)(_element_x * 1000), 8, DECIMAL_10);
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Display_y(LcdAdrs _adrs)
{
	LCD::Write_integer(_adrs, (long)(_element_y * 1000), 8, DECIMAL_10);
}

//----------------------------------------------------------------------//

void WheelSelfPosition::Display_rot(LcdAdrs _adrs)
{
	LCD::Write_integer(_adrs, (long)(_element_rot * 1000), 8, DECIMAL_10);
}

//----------------------------------------------------------------------//

void WheelSelfPosition::operator () (double _x, double _y)
{
	Set_target(_x, _y);
}

//----------------------------------------------------------------------//

/************************************************************************/

//----------------------------------------------------------------------//

Main::Main()
	
	: _controller(Uart::NUM_0)
	, _wheel(Uart::NUM_3, Uart::NUM_1)
{
	INIT_LED();
	
	LCD::Initialize();
	
	_wheel.Set(10);
	
	_num_display = 0;
	
	_is_unlock = NO;
}

//----------------------------------------------------------------------//

void Main::Input()
{
	_controller.Read();
	
	_wheel.Read();
	
	if (_controller.Get_SELECT())
	{
		_is_unlock = NO;
	}
	
	if (_controller.Get_START())
	{
		LCD::Initialize();
		
		_is_unlock = YES;
	}
}

//----------------------------------------------------------------------//

void Main::Process()
{
	if (_is_unlock)
	{
		if (_controller.Get_ZR() & _controller.Get_ZL())
		{
			_wheel(0, 0);
			
			_wheel.Move_auto();
		}
		else
		{
			_wheel.Set_move_direction(_controller.Get_R_stick_x(), _controller.Get_R_stick_y());
			_wheel.Set_turn_direction(_controller.Get_R(), _controller.Get_L());
			
			_wheel.Curve(75);
		}
		
		switch (_controller.Get_cross_key_y())
		{
			case Direction::OVER:
			{
				_num_display ++;
				
				if (_num_display > 5)	_num_display = 5;
				
				break;
			}
			case Direction::UNDER:
			{
				_num_display --;
				
				if (_num_display < 0)	_num_display = 0;
				
				break;
			}
			default:	break;
		}
	}
}

//----------------------------------------------------------------------//

void Main::Output()
{
	if (_is_unlock)
	{
		if (PORT_LED == LED_STATE_LOCK)
		{
			PORT_LED = LED_STATE_UNLOCK;
		}
		
		_wheel.Write();
	}
	else
	{
		if (PORT_LED == LED_STATE_UNLOCK)
		{
			PORT_LED = LED_STATE_LOCK;
		}
		
		
		_wheel.Write_clear();
		
		switch (_num_display)
		{
			case 0:
			{
				_wheel.Display_x(0x00);
				_wheel.Display_y(0x08);
				_wheel.Display_rot(0x40);
				
				break;
			}
			case 1:
			{
				_wheel.Display_verocity(0x00, WheelPlace::FRONT_LEFT);
				_wheel.Display_verocity(0x08, WheelPlace::FRONT_RIGHT);
				_wheel.Display_verocity(0x40, WheelPlace::BACK_LEFT);
				_wheel.Display_verocity(0x48, WheelPlace::BACK_RIGHT);
				
				break;
			}
			case 2:
			{
				_wheel.Display_power(0x00);
				
				break;
			}
		}
	}
}

//----------------------------------------------------------------------//

/************************************************************************/

}
}
}

/************************************************************************/
