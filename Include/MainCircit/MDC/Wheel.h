/**
 * @file	Wheel.h
 * @brief	Wheel�N���X�̒�`
 * @author	Sowa Naoki
 */

#pragma once

#include "Wheel_type.h"

/************************************************************************/

class Wheel : public MDC
{
//function
protected:
	
	/* MD�ɂ��炩���ߐݒ肳�ꂽPWM����͂��� */
	void Set_record_pwm();
	
public:
	
	Wheel(UartNum _uart_num, Byte _num_wheel);
	
	/**
	 * @fn ���E�̈ړ������̐ݒ�
	 * @param _direc ���E�Ői�݂�������
	**/
	void Set_move_direction(DirectionX _direc);

	/* �O��̈ړ������̐ݒ� */
	void Set_move_direction(DirectionY _direc);

	/* �ړ������̐ݒ� */
	void Set_move_direction(DirectionX _direc_x, DirectionY _direc_y);
	
	/**
	 * @fn ��������̐ݒ�
	 * @param _turn �������
	 */
	void Set_turn_direction(TurnDirection _turn);
	
	/**
	 * @fn ��������̐ݒ�
	 * @param _is_turn_left		�����񂵂܂���
	 * @param _is_turn_right	�E���񂵂܂���
	 */
	void Set_turn_direction(YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* ���E�̈ړ�������Ԃ� */
	DirectionX Get_move_direc_x();

	/* �O��̈ړ�������Ԃ� */
	DirectionY Get_move_direc_y();
	
	TurnDirection Get_turn_direc();
	
	/* �E����ł���? */
	YesNo Is_turn_r();

	/* ������ł���? */
	YesNo Is_turn_l();
	
	/* �ړ����܂���? */
	YesNo Is_move();
	
	/**
	 * @fn �����̃p���[��ݒ肷��
	 * @param _power �p���[ 31�i�K��
	 */
	void Set(Power _power);
	
	/* ���͂��ꂽPWM��Ԃ� */
	Pwm Get_pwm();
	
	/**
	 * ���͂���Ă���PWM���C���N�������g
	**/
	void operator ++ (int );
	
	/* ���͂���Ă���PWM���f�N�������g */
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

