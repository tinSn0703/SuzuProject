
#pragma once

/************************************************************************/
/*	三輪オムニ															*/
/************************************************************************/

class ThreeOmuni : public Wheel
{
//function
private:
	
	void Adjust_power(double _persent, YesNo _is_turn_l, YesNo _is_turn_r);
	
public:
	
	/**
	 *	MD番号が前輪が0,左輪が1,右輪が2に自動的に設定される。
	 *
	 *	_uart_num	: 使うUARTの番号
	**/
	ThreeOmuni(UartNum _uart_num);
	
	/**
	 *	_uart_num		: 使うUARTの番号
	 *	_front_number	: 前輪のMD番号
	 *	_left_number	: 左輪のMD番号
	 *	_right_number	: 右輪のMD番号
	**/
	ThreeOmuni(UartNum _uart_num, MotorNum _front_number, MotorNum _left_number, MotorNum _right_number);
	
	/* 車輪の番号を設定。 */
	void Set_wheel_place(ThreeWheelPlace _place, MotorNum _number);
	
	/* 移動。クラスに設定された移動方向をもとにする。 */
	void Move();
	
	/* 移動。移動方向を角度で設定できる。単位は[deg] */
	void Move(double _deg);
	
	/* 超信地旋回。 */
	void SpinTurn();
	
	/* 超信地旋回。 */
	void SpinTurn(YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* 信地旋回。指定した車輪を軸にして旋回する。 */
	void PivotTurn(ThreeWheelPlace _turn_pivot);
	
	/* 信地旋回。指定した車輪を軸にして旋回する。 */
	void PivotTurn(ThreeWheelPlace _turn_pivot, YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* 緩旋回、要するにカーブ。100でまっすぐ。0で信地旋回? */
	void Curve(double _curve_persent);
	
	/* 緩旋回、要するにカーブ。100でまっすぐ。0で信地旋回? */
	void Curve(double _curve_persent, YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* 緩旋回、要するにカーブ。 100でまっすぐ。0で信地旋回? 移動方向を角度で設定。*/
	void Curve(double _curve_persent, double _move_deg);
	
	/* 緩旋回、要するにカーブ。 100でまっすぐ。0で信地旋回? 移動方向を角度で設定。*/
	void Curve(double _curve_persent, double _move_deg, YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* 止める */
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
