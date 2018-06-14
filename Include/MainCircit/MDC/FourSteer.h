/**
 * @file	MDC.h
 * @brief	MDC�N���X�̒�`
 * @author	Sowa Naoki
 */

#pragma once

/************************************************************************/

#define NUM_WHEEL 4

/**
 * @class	�l�փX�e�A�����O�p�N���X
 * 	���̃N���X�ł̑z��ɂ���
 * 	�E�|�e���V�������[�^
 * 	 �|�e���V�������[�^�̒l��512�̎��A0[deg]�ɂȂ��Ă��܂��B
�@* 	�E�ԗւ̊p�x
 * 	�@�����ł́A�ԗւ�0[deg]���A�}�̂悤�Ƀ}�V���̒��S���ɑ΂��āA45[deg]�ƍl���Ă��܂�
 * 		/	\
 * 		\	/
 */
class FourSteer : public Wheel
{
//function
private:
	
	/**
	 * @fn �S�Ă̎ԗւ̖ڕW�p��ݒ肷��B
	 * @param _target_deg_fr �E�O�ւ̖ڕW�p
	 * @param _target_deg_br �E��ւ̖ڕW�p
	 * @param _target_deg_bl ����ւ̖ڕW�p
	 * @param _target_deg_fl ���O�ւ̖ڕW�p
	 */
	void Set_target_angle(double _target_deg_fr, double _target_deg_br, double _target_deg_bl, double _target_deg_fl);
	
	/**
	 * @fn �i�s��������ԗւ̖ڕW�p��ݒ肷��B
	 * @param _move_deg �i�s���� +180 ~ -180 �ɂ���悤��
	 */
	void Set_target_angle(double _move_deg);
	
	/**
	 * @fn �i�s��������ԗւ̖ڕW�p��ݒ肷��B
	 * @param _move_deg �i�s���� +180 ~ -180 �ɂ���悤��
	 */
	void Set_target_angle(double _move_deg, const double _curve_persent);
	
	void Set_angle_motor_power(uByte i);
	
	void Set_unit_power(TurnDirection _turn);
	
	void Set_unit_power(double _deg);
	
	void Dispaly_angle(LcdAdrs _adrs, double _deg);
	
public:
	
	/**
	 * @fn	�R���X�g���N�^�B
	 *		���̃N���X�ł́A�l�փX�e�A��MDC�́A�S�Ĉ��UART�ɂȂ����Ă���Ƒz�肵�Ă��܂�
	 * @param _uart_num MDC�ɂȂ���UART�̔ԍ�
	 */
	FourSteer(UartNum _uart_num);
	
	/**
	 * @fn �p�x�p���[�^��MD�ԍ��ƃ|�e���V�������[�^�̔ԍ���ݒ肷��B
	 * @param _place			�ς������ʒu
	 * @param _wheel_motor_num	�ύX����l
	 * @param _angle_motor_num	�ύX����l
	 * @param _ad_num			�ύX����l
	 */
	void Set_wheel_unit_place(FourWheelPlace _place, MotorNum _wheel_motor_num, MotorNum _angel_motor_num, ADNum _ad_num);
	
	void Set_angle_motor_reverse(FourWheelPlace _place, YesNo _want_to_reverse);
	
	void Set_wheel_motor_reverse(FourWheelPlace _place, YesNo _want_to_reverse);
	
	/** 
	 * @fn �}�V���̑O�ʂ����炷�B���点��͈͂� 0 <= deg <= 360
	 */
	void Set_front(sint _move_deg);
	
	/**
	 * @fn �f�[�^�̓ǂݎ��
	 */
	void Read();
	
	/**
	 * @fn	�P��Ŏԗփ��j�b�g�𓮂����B
	 *		���]�Ŋp�x�㏸�A�t�]�Ŋp�x����
	 */
	void Move_wheel_unit(FourWheelPlace _place, Signal _sig, Pwm _pwm);
	
	/** 
	 * @fn �ړ��B���O�̐ݒ���Q�ƁB
	 */
	void Move();
	
	/**
	 * @fn �ړ��B�p�x�Őݒ�
	 * @param _deg �ړ������B�P�ʂ�[deg]�@�O�ʂ�0[deg]�Ŏ��v������+�ł��B
	 */
	void Move(double _deg);
	
	/**
	 * @fn �ړ��B�ɍ��W�Őݒ�
	 * @param _power �ړ��̋��� 0~x~31
	 * @param _deg �ړ������B�P�ʂ�[deg] �O�ʂ�0[deg]�Ŏ��v������+�ł��B
	 */
	void Move(Pwm _r, double _deg);
	
	/**
	 * @fn �ɐ���A�v����ɃJ�[�u�B�ړ������A��������͎��O�̐ݒ���Q��
	 * @param _curve_persent �J�[�u�̓x���� 100�ł܂������B0�ŐM�n����?
	 */
	void Curve(double _curve_persent);
	
	void Curve(YesNo _is_turn_r, YesNo _is_turn_l, double _curve_persent);
	
	/**
	 * @fn �ɐ���A�v����ɃJ�[�u�B��������͎��O�̐ݒ���Q��
	 * @param _move_deg �ړ�����
	 * @param _curve_persent �J�[�u�̓x���� 100�ł܂������B0�ŐM�n����?
	 */
	void Curve(double _move_deg, double _curve_persent);
	
	void Curve(double _move_deg, YesNo _is_turn_r, YesNo _is_turn_l, double _curve_persent);
	
	/**
	 * @fn ���M�n����
	 */
	void SpinTurn();
	
	/** 
	 * @fn �M�n����B�w�肵���ԗւ����ɂ��Đ��񂷂�B
	 * @param _turn_pivot ��]���S
	 */
	void PivotTurn(FourWheelPlace _turn_pivot);	
	
	/**
	 * @fn �~�߂� 
	 */
	void Stop();
	
	/**
	 * @fn MDC�֑��M
	 */
	void Write();
	
	/**
	 * @fn �N���A�f�[�^��MDC�֑��M
	 */
	void Write_clear();
	
	/**
	 * @fn �|�e���V�������[�^�̃f�[�^��\��
	 */
	void Dispaly_meter_data(LcdAdrs _adrs);
	
	/**
	 * @fn ���݊p��\��
	 */
	void Dispaly_current_angle(LcdAdrs _adrs);
	
	/**
	 * @fn �ڕW�p��\��
	 */
	void Dispaly_target_angle(LcdAdrs _adrs);
	
	/**
	 * @fn �p�x���[�^�̏o�͂�\��
	 */
	void Display_angle_motor_power(LcdAdrs _adrs);
	
	/**
	 * @fn �ԗւ̃��[�^�̏o�͂�\��
	 */
	void Display_wheel_power(LcdAdrs _adrs);
	
private:
	
	YesNo _is_angle_set :1;
	
	double _machine_front_deg;
	
	Motor _motor_angle[NUM_WHEEL];
	ADChange _angle_meter[NUM_WHEEL];
	double _current_deg[NUM_WHEEL];
	double _target_deg[NUM_WHEEL];
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void FourSteer::Set_wheel_unit_place
(
	const FourWheelPlace	_place, 
	const MotorNum			_wheel_motor_num,
	const MotorNum			_angle_motor_num, 
	const ADNum				_ad_num
)
{
	_motor[_place].Reset(_wheel_motor_num);
	_motor_angle[_place].Reset(_angle_motor_num);
	_angle_meter[_place].Reset(_ad_num, NO);
}

//----------------------------------------------------------------------//

inline void FourSteer::Set_angle_motor_reverse
(
	const FourWheelPlace _place, 
	const YesNo _want_to_reverse
)
{
	_motor_angle[_place].Want_to_reverse_signal(_want_to_reverse);
}

//----------------------------------------------------------------------//

inline void FourSteer::Set_wheel_motor_reverse
(
	const FourWheelPlace _place, 
	const YesNo _want_to_reverse
)
{
	_motor[_place].Want_to_reverse_signal(_want_to_reverse);
}

//----------------------------------------------------------------------//

inline void FourSteer::Move(const Pwm _r, const double _deg)
{
	Wheel::Set(_r);
	
	Move(_deg);
}

//----------------------------------------------------------------------//

inline void FourSteer::Curve(YesNo _is_turn_r, YesNo _is_turn_l, double _curve_persent)
{
	Wheel::Set_turn_direction(_is_turn_r, _is_turn_l);
	
	Curve(_curve_persent);
}

//----------------------------------------------------------------------//

inline void FourSteer::Display_wheel_power(const LcdAdrs _adrs)
{
	Display_power(_adrs);
}

//----------------------------------------------------------------------//

/************************************************************************/

