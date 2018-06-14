
#pragma once

/************************************************************************/
/*	�l�փI���j															*/
/************************************************************************/

class FourOmuni : public Wheel
{
//function
private:
	
	void Adjust_power(double _persent);
	
public:
	
	/*
	 * _uart_num	: �g��UART�̔ԍ�
	 */
	FourOmuni(UartNum _uart_num);
	
	/* �ԗւ̔ԍ���ݒ�B */
	void Set_wheel_place(FourWheelPlace _place, MotorNum _number);
	
	/* �}�V���̑O�ʂ����炷�B���点��͈͂� 0 <= deg <= 360 */
	void Set_front(sint _move_deg);
	
	/* �ړ��B�N���X�ɐݒ肳�ꂽ�ړ����������Ƃɂ���B */
	void Move();
	
	/* �ړ��B�ړ��������p�x�Őݒ�ł���B�P�ʂ�[deg] */
	void Move(double _deg);
	
	/* �ړ��B�ړ��������p�x�Őݒ�ł���B�P�ʂ�[deg] */
	void Move(double _deg, Power _power);
	
	/* ���M�n����B */
	void SpinTurn();
	
	/* ���M�n����B */
	void SpinTurn(Power _power);
	
	/* �M�n����B�w�肵���ԗւ����ɂ��Đ��񂷂�B */
	void PivotTurn(FourWheelPlace _turn_pivot);
	
	/* �M�n����B�w�肵���ԗւ����ɂ��Đ��񂷂�B */
	void PivotTurn(FourWheelPlace _turn_pivot, Power _power);
	
	/* �ɐ���A�v����ɃJ�[�u�B100�ł܂������B0�ŐM�n����? */
	void Curve(double _curve_persent);
	
	/* �ɐ���A�v����ɃJ�[�u�B 100�ł܂������B0�ŐM�n����? �ړ��������p�x�Őݒ�B*/
	void Curve(double _curve_persent, double _deg);
	
	/* �ɐ���A�v����ɃJ�[�u�B 100�ł܂������B0�ŐM�n����? �ړ��������p�x�Őݒ�B*/
	void Curve(double _curve_persent, double _deg, Power _power);
	
	/* �ԗւ��ƂɃp���[�𒲐����� */
	void Adjust(double _fr_persent, double _br_persent, double _bl_persent, double _fl_persent);
	
	/* �~�߂� */
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
