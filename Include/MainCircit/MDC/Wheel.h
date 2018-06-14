/**
 * @file	Wheel.h
 * @brief	Wheelクラスの定義
 * @author	Sowa Naoki
 */

#pragma once

#include "Wheel_type.h"

/************************************************************************/

class Wheel : public MDC
{
//function
protected:
	
	/* MDにあらかじめ設定されたPWMを入力する */
	void Set_record_pwm();
	
public:
	
	Wheel(UartNum _uart_num, Byte _num_wheel);
	
	/**
	 * @fn 左右の移動方向の設定
	 * @param _direc 左右で進みたい方向
	**/
	void Set_move_direction(DirectionX _direc);

	/* 前後の移動方向の設定 */
	void Set_move_direction(DirectionY _direc);

	/* 移動方向の設定 */
	void Set_move_direction(DirectionX _direc_x, DirectionY _direc_y);
	
	/**
	 * @fn 旋回方向の設定
	 * @param _turn 旋回方向
	 */
	void Set_turn_direction(TurnDirection _turn);
	
	/**
	 * @fn 旋回方向の設定
	 * @param _is_turn_left		左旋回しますか
	 * @param _is_turn_right	右旋回しますか
	 */
	void Set_turn_direction(YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* 左右の移動方向を返す */
	DirectionX Get_move_direc_x();

	/* 前後の移動方向を返す */
	DirectionY Get_move_direc_y();
	
	TurnDirection Get_turn_direc();
	
	/* 右旋回ですか? */
	YesNo Is_turn_r();

	/* 左旋回ですか? */
	YesNo Is_turn_l();
	
	/* 移動しますか? */
	YesNo Is_move();
	
	/**
	 * @fn 足回りのパワーを設定する
	 * @param _power パワー 31段階で
	 */
	void Set(Power _power);
	
	/* 入力されたPWMを返す */
	Pwm Get_pwm();
	
	/**
	 * 入力されているPWMをインクリメント
	**/
	void operator ++ (int );
	
	/* 入力されているPWMをデクリメント */
	void operator -- (int );
	
//variable
private:
	
	Pwm _mem_pwm : 5;
	
	DirectionX _mem_direc_x :2;
	DirectionY _mem_direc_y :2;
	
	TurnDirection _mem_direc_turn :2;
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void Wheel::Set_record_pwm()
{
	MDC::Set(_mem_pwm);
}

//----------------------------------------------------------------------//

inline void Wheel::Set_move_direction(const DirectionX _direc)
{
	_mem_direc_x = _direc;
}

//----------------------------------------------------------------------//

inline void Wheel::Set_move_direction(const DirectionY _direc)
{
	_mem_direc_y = _direc;
}

//----------------------------------------------------------------------//

inline void Wheel::Set_move_direction(const DirectionX _direc_x, const DirectionY _direc_y)
{
	_mem_direc_x = _direc_x;
	_mem_direc_y = _direc_y;
}

//----------------------------------------------------------------------//

inline void Wheel::Set_turn_direction(const TurnDirection _turn)
{
	_mem_direc_turn = _turn;
}

//----------------------------------------------------------------------//

inline DirectionX Wheel::Get_move_direc_x()
{
	return _mem_direc_x;
}

//----------------------------------------------------------------------//

inline DirectionY Wheel::Get_move_direc_y()
{
	return _mem_direc_y;
}

//----------------------------------------------------------------------//

inline TurnDirection Wheel::Get_turn_direc()
{
	return _mem_direc_turn;
}

//----------------------------------------------------------------------//

inline YesNo Wheel::Is_turn_l()
{
	return ((_mem_direc_turn == LEFT_TURN) ? YES : NO);
}

//----------------------------------------------------------------------//

inline YesNo Wheel::Is_turn_r()
{
	return ((_mem_direc_turn == RIGHT_TURN) ? YES : NO);
}

//----------------------------------------------------------------------//

inline YesNo Wheel::Is_move()
{
	return (Is_true_the(0b0111, (Byte)Get_move_direc_x() & (Byte)Get_move_direc_y()));
}

//----------------------------------------------------------------------//

inline Pwm Wheel::Get_pwm()
{
	return _mem_pwm;
};

//----------------------------------------------------------------------//

inline void Wheel::Set(const Power _power)
{
	_mem_pwm = To_within(_power, 31, 0);
}

//----------------------------------------------------------------------//

/************************************************************************/

