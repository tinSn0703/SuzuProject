
#pragma once

/************************************************************************/

#define NUM_CONTROLLER_28BIT 6
#define NUM_CONTROLLER_24BIT 4
#define NUM_CONTROLLER_DATA 3

#define NUM_LIMIT_RECEIVE 12

#define TIME_RECEIVE_WAIT		 100//[ms]
#define TIME_READ_ERROR			1000//[ms]
#define TIME_READ_ERROR_DOUBLE	2000//[ms]

/************************************************************************/

typedef uByte ControllerData;

typedef BOOL Btn;

#define BTN_ON	TRUE
#define BTN_OFF	FALSE

/************************************************************************/

//----------------------------------------------------------------------//

//コントローラとの受信の状態を表す
enum ControllerError
{
	READ_NORMARY	= 0,	///何もしていない状態
	READ_SUCCESS	= 1,	//受信に成功した状態
	READ_INCOMPLETE = 2,	//全てのデータを受け取ることができなかった状態
	READ_FAILURE	= 3,	//受信に失敗した状態
};

//----------------------------------------------------------------------//

//スティックまたは十字キーの横を表す
enum ControllerDirecX
{
	R_STICK_X	= 16,
	L_STICK_X	= 20,
	BTN_CROSS_X	= 12,
};

//----------------------------------------------------------------------//

//スティックまたは十字キーの縦を表す
enum ControllerDirecY
{
	R_STICK_Y	= 18,
	L_STICK_Y	= 22,	
	BTN_CROSS_Y	= 14,
};

//----------------------------------------------------------------------//

//十字キーの横のボタンを表す
enum ControllerCrossX
{
	BTN_CROSS_RIGHT		= Direction::EAST,
	BTN_CROSS_LEFT		= Direction::WEST,
	BTN_CROSS_X_CENTER	= Direction::yCENTER
};

//----------------------------------------------------------------------//

//字キーの縦のボタンを表す
enum ControllerCrossY
{
	BTN_CROSS_OVER		= Direction::NORTH,
	BTN_CROSS_UNDER		= Direction::SOUTH,
	BTN_CROSS_Y_CENTER	= Direction::yCENTER
};

//----------------------------------------------------------------------//

enum ControllerRStickX
{
	R_STICK_RIGHT		= Direction::EAST,
	R_STICK_LEFT		= Direction::WEST,
	R_STICK_X_CENTER	= Direction::xCENTER
};

//----------------------------------------------------------------------//

enum ControllerRStickY
{
	R_STICK_OVER		= Direction::NORTH,
	R_STICK_UNDER		= Direction::SOUTH,
	R_STICK_Y_CENTER	= Direction::yCENTER
};

//----------------------------------------------------------------------//

enum ControllerLStickX
{
	L_STICK_RIGHT		= Direction::EAST,
	L_STICK_LEFT		= Direction::WEST,
	L_STICK_X_CENTER	= Direction::xCENTER
};

//----------------------------------------------------------------------//

enum ControllerLStickY
{
	L_STICK_OVER		= Direction::NORTH,
	L_STICK_UNDER		= Direction::SOUTH,
	L_STICK_Y_CENTER	= Direction::yCENTER
};

//----------------------------------------------------------------------//

//コントローラのボタンを表す
enum ControllerBtn
{
	BTN_R	= 7,
	BTN_ZR	= 4,
	
	BTN_L	= 6,
	BTN_ZL	= 5,
	
	BTN_HOME = 1,	//other_0
	
	BTN_X	= 8,
	BTN_A	= 9,
	BTN_B	= 10,
	BTN_Y	= 11,
	
	BTN_SELECT	= 0,
	BTN_R3		= 2,	//other_1
	BTN_L3		= 1,	//other_0
	BTN_START	= 3,
	
	BTN_L2	= 4,
	BTN_R2	= 5,
	BTN_L1	= 6,
	BTN_R1	= 7,
	
	BTN_TRI	= 8,
	BTN_CIR	= 9,
	BTN_CRO	= 10,
	BTN_SQU	= 11,
};

//----------------------------------------------------------------------//

/************************************************************************/

namespace Controller
{
namespace Base
{

/************************************************************************/

union ControllerCommand
{
	struct Command
	{
		//[0]
		Btn _btn_select		:1; //0bit
		Btn _btn_other_0	:1; //1bit
		Btn _btn_other_1	:1; //2bit
		Btn _btn_start		:1; //3bit
		
		Btn _btn_right_1	:1; //4bit
		Btn _btn_left_1		:1; //5bit
		Btn _btn_left_0		:1; //6bit
		Btn _btn_right_0	:1; //7bit
		
		//[1]
		Btn	_btn_mark_o	:1; //上ボタン 0bit
		Btn	_btn_mark_r	:1; //右ボタン 1bit
		Btn _btn_mark_u	:1; //下ボタン 2bit
		Btn	_btn_mark_l	:1; //左ボタン 3bit
		
		DirectionX _cross_x :2; //十字キー x軸 4,5bit
		DirectionY _cross_y :2; //十字キー y軸 6,7bit
		
		//[2]
		DirectionX _stick_right_x	:2; //右スティック x方向 0,1bit
		DirectionY _stick_right_y	:2; //右スティック y方向 2,3bit
		DirectionX _stick_left_x	:2; //左スティック x方向 4,5bit
		DirectionY _stick_left_y	:2; //左スティック y方向 6,7bit
	}
	_command;
	
	struct CommandBtn
	{
		//[0]
		Btn _btn_select		:1; //0bit
		Btn _btn_other_0	:1; //1bit
		Btn _btn_other_1	:1; //2bit
		Btn _btn_start		:1; //3bit
		
		Btn _btn_right_1	:1; //4bit
		Btn _btn_left_1		:1; //5bit
		Btn _btn_left_0		:1; //6bit
		Btn _btn_right_0	:1; //7bit
		
		//[1]
		Btn	_btn_mark_o	:1; //上ボタン 0bit
		Btn	_btn_mark_r	:1; //右ボタン 1bit
		Btn _btn_mark_u	:1; //下ボタン 2bit
		Btn	_btn_mark_l	:1; //左ボタン 3bit
	}
	_command_btn;
	
	struct Btns
	{
		uByte _other		:4;
		uByte _right_left	:4;
		uByte _mark			:4;
		
		Btn _cross_x_east :1;
		Btn _cross_x_west :1;
		Btn _cross_y_north :1;
		Btn _cross_y_south :1;
		
		Btn _sti_right_x_east :1;
		Btn _sti_right_x_west :1;
		Btn _sti_right_y_north :1;
		Btn _sti_right_y_south :1;
		
		Btn _sti_left_x_east :1;
		Btn _sti_left_x_west :1;
		Btn _sti_left_y_north :1;
		Btn _sti_left_y_south :1;
	}
	_btns;
	
	struct All
	{
		DataBit16 _btns			:12;
		DataBit16 _directions	:12;
	}
	_all;
	
	ullint _all_data :24;
	
	ControllerData _array[NUM_CONTROLLER_DATA];
};

/************************************************************************/

}
}

/************************************************************************/

