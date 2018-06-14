
#pragma once

/************************************************************************/

class FourWheel : public Wheel
{	
//function
public:
	
	FourWheel(UartNum _uart_num);
	FourWheel(UartNum _uart_num, MotorNum _fr_num, MotorNum _br_num, MotorNum _bl_num, MotorNum _fl_num);
	
	/* 車輪のMD番号を設定する */
	void Set_wheel_place(FourWheelPlace _place, MotorNum _number);
	
	/* 移動。クラスに設定された移動方向をもとにする。 */
	void Move();
	
	/* 旋回 */
	void SpinTurn();
	
	/* 旋回 */
	void SpinTurn(YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* 信地旋回。指定した車輪を軸にして旋回する。 */
	void PivotTurn(FourWheelPlace _turn_pivot);
	
	/* 信地旋回。指定した車輪を軸にして旋回する。 */
	void PivotTurn(FourWheelPlace _turn_pivot, YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* 緩旋回、要するにカーブ。100でまっすぐ。0で信地旋回? */
	void Curve(double _curve_persent);
	
	/* 緩旋回、要するにカーブ。100でまっすぐ。0で信地旋回? */
	void Curve(double _curve_persent, YesNo _is_turn_l, YesNo _is_turn_r);
	
	/* 止める */
	void Stop();
	
	Motor & operator [] (FourWheelPlace _place);
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void FourWheel::Set_wheel_place
(
	const FourWheelPlace	_place,
	const MotorNum			_motor_number
)
{
	_motor[_place].Reset(_motor_number);
}

//----------------------------------------------------------------------//

inline void FourWheel::SpinTurn()
{
	SpinTurn(Is_turn_l(), Is_turn_r());
}

//----------------------------------------------------------------------//

inline void FourWheel::PivotTurn
(
	const FourWheelPlace	_turn_pivot,
	const YesNo				_is_turn_l,
	const YesNo				_is_turn_r
)
{
	SpinTurn(_is_turn_l, _is_turn_r);
	
	_motor[_turn_pivot] = SIGNAL_BREAK;
}

//----------------------------------------------------------------------//

inline void FourWheel::PivotTurn(const FourWheelPlace _turn_pivot)
{
	PivotTurn(_turn_pivot, Is_turn_l(), Is_turn_r());
}

//----------------------------------------------------------------------//

inline void FourWheel::Curve(const double _curve_persent)
{
	Curve(_curve_persent, Is_turn_l(), Is_turn_r());
}

//----------------------------------------------------------------------//

inline Motor & FourWheel::operator [](FourWheelPlace _place)
{
	return MDC::operator []((MotorNum)_place);
}

//----------------------------------------------------------------------//

/************************************************************************/
