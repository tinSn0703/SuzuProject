
#pragma once

/************************************************************************/
/*	�O�փI���j															*/
/************************************************************************/

class ThreeOmuni : public Wheel
{
//function
private:
	
	void Adjust_power(double _persent, YesNo _is_turn_l, YesNo _is_turn_r);
	
public:
	
	/**
	 *	MD�ԍ����O�ւ�0,���ւ�1,�E�ւ�2�Ɏ����I�ɐݒ肳���B
	 *
	 *	_uart_num	: �g��UART�̔ԍ�
	**/
	ThreeOmuni(UartNum _uart_num);
	
	/**
	 *	_uart_num		: �g��UART�̔ԍ�
	 *	_front_number	: �O�ւ�MD�ԍ�
	 *	_left_number	: ���ւ�MD�ԍ�
	 *	_right_number	: �E�ւ�MD�ԍ�
	**/
	ThreeOmuni(UartNum _uart_num, MotorNum _front_number, MotorNum _left_number, MotorNum _right_number);
	
	/* �ԗւ̔ԍ���ݒ�B */
	void Set_wheel_place(ThreeWheelPlace _place, MotorNum _number);
	
	/* �ړ��B�N���X�ɐݒ肳�ꂽ�ړ����������Ƃɂ���B */
	void Move();
	
	/* �ړ��B�ړ��������p�x�Őݒ�ł���B�P�ʂ�[deg] */
	void Move(double _deg);
	
	/* ���M�n����B */
	void SpinTurn();
	
	/* ���M�n����B */
	void SpinTurn(YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* �M�n����B�w�肵���ԗւ����ɂ��Đ��񂷂�B */
	void PivotTurn(ThreeWheelPlace _turn_pivot);
	
	/* �M�n����B�w�肵���ԗւ����ɂ��Đ��񂷂�B */
	void PivotTurn(ThreeWheelPlace _turn_pivot, YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* �ɐ���A�v����ɃJ�[�u�B100�ł܂������B0�ŐM�n����? */
	void Curve(double _curve_persent);
	
	/* �ɐ���A�v����ɃJ�[�u�B100�ł܂������B0�ŐM�n����? */
	void Curve(double _curve_persent, YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* �ɐ���A�v����ɃJ�[�u�B 100�ł܂������B0�ŐM�n����? �ړ��������p�x�Őݒ�B*/
	void Curve(double _curve_persent, double _move_deg);
	
	/* �ɐ���A�v����ɃJ�[�u�B 100�ł܂������B0�ŐM�n����? �ړ��������p�x�Őݒ�B*/
	void Curve(double _curve_persent, double _move_deg, YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* �~�߂� */
	void Stop();
	
	Motor & operator [] (ThreeWheelPlace _place);
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void ThreeOmuni::Set_wheel_place
(
	const ThreeWheelPlace	_place,
	const MotorNum			_number
)
{
	_motor[_place].Reset(_number);
}

//----------------------------------------------------------------------//

inline void ThreeOmuni::Stop()
{
	_motor[0] = SIGNAL_BREAK;
	_motor[1] = SIGNAL_BREAK;
	_motor[2] = SIGNAL_BREAK;
	
	Set_record_pwm();
}

//----------------------------------------------------------------------//

inline void ThreeOmuni::SpinTurn()
{
	SpinTurn(Is_turn_l(), Is_turn_r());
}

//----------------------------------------------------------------------//

inline void ThreeOmuni::PivotTurn
(
	const ThreeWheelPlace	_turn_pivot,
	const YesNo				_is_turn_l,
	const YesNo				_is_turn_r
)
{
	SpinTurn(_is_turn_l, _is_turn_r);
	
	_motor[_turn_pivot] = SIGNAL_BREAK;
}

//----------------------------------------------------------------------//

inline void ThreeOmuni::PivotTurn(const ThreeWheelPlace _turn_pivot)
{
	PivotTurn(_turn_pivot, Is_turn_l(), Is_turn_r());
}

//----------------------------------------------------------------------//

inline void ThreeOmuni::Curve
(
	const double	_persent,
	const YesNo		_is_turn_l,
	const YesNo		_is_turn_r
)
{
	Move();
	
	Adjust_power(_persent, _is_turn_l, _is_turn_r);
}

//----------------------------------------------------------------------//

inline void ThreeOmuni::Curve(const double _curve_persent)
{
	Curve(_curve_persent, Is_turn_l(), Is_turn_r());
}

//----------------------------------------------------------------------//

inline void ThreeOmuni::Curve
(
	const double	_persent,
	double			_deg,
	const YesNo		_is_turn_l,
	const YesNo		_is_turn_r
)
{
	Move(_deg);
	
	Adjust_power(_persent, _is_turn_l, _is_turn_r);
}

//----------------------------------------------------------------------//

inline void ThreeOmuni::Curve(const double _curve_persent, const double _deg)
{
	Curve(_curve_persent, _deg, Is_turn_l(), Is_turn_r());
}

//----------------------------------------------------------------------//

inline Motor & ThreeOmuni::operator [](ThreeWheelPlace _place)
{
	return MDC::operator []((MotorNum)_place);
}

//----------------------------------------------------------------------//

/************************************************************************/
