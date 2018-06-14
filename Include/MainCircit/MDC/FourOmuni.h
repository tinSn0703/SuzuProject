
#pragma once

/************************************************************************/
/*	四輪オムニ															*/
/************************************************************************/

class FourOmuni : public Wheel
{
//function
private:
	
	void Adjust_power(double _persent);
	
public:
	
	/*
	 * _uart_num	: 使うUARTの番号
	 */
	FourOmuni(UartNum _uart_num);
	
	/* 車輪の番号を設定。 */
	void Set_wheel_place(FourWheelPlace _place, MotorNum _number);
	
	/* マシンの前面をずらす。ずらせる範囲は 0 <= deg <= 360 */
	void Set_front(sint _move_deg);
	
	/* 移動。クラスに設定された移動方向をもとにする。 */
	void Move();
	
	/* 移動。移動方向を角度で設定できる。単位は[deg] */
	void Move(double _deg);
	
	/* 移動。移動方向を角度で設定できる。単位は[deg] */
	void Move(double _deg, Power _power);
	
	/* 超信地旋回。 */
	void SpinTurn();
	
	/* 超信地旋回。 */
	void SpinTurn(Power _power);
	
	/* 信地旋回。指定した車輪を軸にして旋回する。 */
	void PivotTurn(FourWheelPlace _turn_pivot);
	
	/* 信地旋回。指定した車輪を軸にして旋回する。 */
	void PivotTurn(FourWheelPlace _turn_pivot, Power _power);
	
	/* 緩旋回、要するにカーブ。100でまっすぐ。0で信地旋回? */
	void Curve(double _curve_persent);
	
	/* 緩旋回、要するにカーブ。 100でまっすぐ。0で信地旋回? 移動方向を角度で設定。*/
	void Curve(double _curve_persent, double _deg);
	
	/* 緩旋回、要するにカーブ。 100でまっすぐ。0で信地旋回? 移動方向を角度で設定。*/
	void Curve(double _curve_persent, double _deg, Power _power);
	
	/* 車輪ごとにパワーを調整する */
	void Adjust(double _fr_persent, double _br_persent, double _bl_persent, double _fl_persent);
	
	/* 止める */
	void Stop();
	
	Motor & operator [] (FourWheelPlace _place);
	
//variable
private:
	
	sint _mem_move_front_deg :8;
	
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void FourOmuni::Set_wheel_place
(
	const FourWheelPlace	_place,
	const MotorNum			_number
)
{
	_motor[_place].Reset(_number);
}

//----------------------------------------------------------------------//

inline void FourOmuni::Set_front(const sint _move_deg)
{
	_mem_move_front_deg = To_within(_move_deg, 360, 0);
}

//----------------------------------------------------------------------//

inline void FourOmuni::Move(double _deg, Power _power)
{
	Set(_power);
	Move(_deg);
}

//----------------------------------------------------------------------//

inline void FourOmuni::SpinTurn(Power _power)
{
	Set(_power);
	SpinTurn();
}

//----------------------------------------------------------------------//

inline void FourOmuni::PivotTurn(FourWheelPlace _turn_pivot, Power _power)
{
	Set(_power);
	PivotTurn(_turn_pivot);
}

//----------------------------------------------------------------------//

inline void FourOmuni::Stop()
{
	_motor[0] = SIGNAL_BREAK;
	_motor[1] = SIGNAL_BREAK;
	_motor[2] = SIGNAL_BREAK;
	_motor[3] = SIGNAL_BREAK;
}

//----------------------------------------------------------------------//

inline void FourOmuni::Curve(const double _persent)
{
	Move();
	
	Adjust_power(_persent);
}

//----------------------------------------------------------------------//

inline void FourOmuni::Curve(const double _persent, const double _deg)
{
	Move(_deg);
	
	Adjust_power(_persent);
}

//----------------------------------------------------------------------//

inline void FourOmuni::Curve(const double _persent, const double _deg, Power _power)
{
	Set(_power);	
	Curve(_persent, _deg);
}

//----------------------------------------------------------------------//

inline Motor & FourOmuni::operator [](FourWheelPlace _place)
{
	return MDC::operator []((MotorNum)_place);
}

//----------------------------------------------------------------------//

/************************************************************************/
