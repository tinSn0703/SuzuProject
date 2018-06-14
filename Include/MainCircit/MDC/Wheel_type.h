/**
 * @file	Wheel_type.h
 * @brief	足回り関係の型、マクロの定義
 * @author	Sowa Naoki
 */

#pragma once

/************************************************************************/

#define DEG_MOVE_FRONT			  0
#define DEG_MOVE_FRONT_RIGHT	 45
#define DEG_MOVE_RIGHT			 90
#define DEG_MOVE_BACK_RIGHT		135
#define DEG_MOVE_BACK			180
#define DEG_MOVE_BACK_LEFT		225
#define DEG_MOVE_LEFT			270
#define DEG_MOVE_FRONT_LEFT		315

/************************************************************************/

namespace WheelPlace
{

//----------------------------------------------------------------------//

enum FourWheelPlace
{
	FRONT_RIGHT	= 0,
	BACK_RIGHT	= 1,
	BACK_LEFT	= 2,
	FRONT_LEFT	= 3
};

//----------------------------------------------------------------------//

enum ThreeWheelPlace
{
	FRONT	= 0,
	LEFT	= 1,
	RIGHT	= 2,
};

};

typedef WheelPlace::ThreeWheelPlace ThreeWheelPlace;
typedef WheelPlace::FourWheelPlace FourWheelPlace;

//----------------------------------------------------------------------//

enum TurnDirection
{
	LEFT_TURN	= SIGNAL_REVERSE,
	RIGHT_TURN	= SIGNAL_FORWARD,
	NON_TURN	= SIGNAL_BREAK
};

//----------------------------------------------------------------------//

/************************************************************************/
