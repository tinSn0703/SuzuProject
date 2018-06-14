/**
 * @file	MDC.h
 * @brief	MDCクラスの定義
 * @author	Sowa Naoki
 */

#pragma once

/************************************************************************/

#define NUM_WHEEL 4

/**
 * @class	四輪ステアリング用クラス
 * 	このクラスでの想定について
 * 	・ポテンションメータ
 * 	 ポテンションメータの値が512の時、0[deg]になっています。
　* 	・車輪の角度
 * 	　ここでは、車輪の0[deg]を、図のようにマシンの中心線に対して、45[deg]と考えています
 * 		/	\
 * 		\	/
 */
class FourSteer : public Wheel
{
//function
private:
	
	/**
	 * @fn 全ての車輪の目標角を設定する。
	 * @param _target_deg_fr 右前輪の目標角
	 * @param _target_deg_br 右後輪の目標角
	 * @param _target_deg_bl 左後輪の目標角
	 * @param _target_deg_fl 左前輪の目標角
	 */
	void Set_target_angle(double _target_deg_fr, double _target_deg_br, double _target_deg_bl, double _target_deg_fl);
	
	/**
	 * @fn 進行方向から車輪の目標角を設定する。
	 * @param _move_deg 進行方向 +180 ~ -180 にするように
	 */
	void Set_target_angle(double _move_deg);
	
	/**
	 * @fn 進行方向から車輪の目標角を設定する。
	 * @param _move_deg 進行方向 +180 ~ -180 にするように
	 */
	void Set_target_angle(double _move_deg, const double _curve_persent);
	
	void Set_angle_motor_power(uByte i);
	
	void Set_unit_power(TurnDirection _turn);
	
	void Set_unit_power(double _deg);
	
	void Dispaly_angle(LcdAdrs _adrs, double _deg);
	
public:
	
	/**
	 * @fn	コンストラクタ。
	 *		このクラスでは、四輪ステアのMDCは、全て一つのUARTにつながっていると想定しています
	 * @param _uart_num MDCにつながるUARTの番号
	 */
	FourSteer(UartNum _uart_num);
	
	/**
	 * @fn 角度用モータのMD番号とポテンションメータの番号を設定する。
	 * @param _place			変えたい位置
	 * @param _wheel_motor_num	変更する値
	 * @param _angle_motor_num	変更する値
	 * @param _ad_num			変更する値
	 */
	void Set_wheel_unit_place(FourWheelPlace _place, MotorNum _wheel_motor_num, MotorNum _angel_motor_num, ADNum _ad_num);
	
	void Set_angle_motor_reverse(FourWheelPlace _place, YesNo _want_to_reverse);
	
	void Set_wheel_motor_reverse(FourWheelPlace _place, YesNo _want_to_reverse);
	
	/** 
	 * @fn マシンの前面をずらす。ずらせる範囲は 0 <= deg <= 360
	 */
	void Set_front(sint _move_deg);
	
	/**
	 * @fn データの読み取り
	 */
	void Read();
	
	/**
	 * @fn	単一で車輪ユニットを動かす。
	 *		正転で角度上昇、逆転で角度減少
	 */
	void Move_wheel_unit(FourWheelPlace _place, Signal _sig, Pwm _pwm);
	
	/** 
	 * @fn 移動。事前の設定を参照。
	 */
	void Move();
	
	/**
	 * @fn 移動。角度で設定
	 * @param _deg 移動方向。単位は[deg]　前面が0[deg]で時計方向に+です。
	 */
	void Move(double _deg);
	
	/**
	 * @fn 移動。極座標で設定
	 * @param _power 移動の強さ 0~x~31
	 * @param _deg 移動方向。単位は[deg] 前面が0[deg]で時計方向に+です。
	 */
	void Move(Pwm _r, double _deg);
	
	/**
	 * @fn 緩旋回、要するにカーブ。移動方向、旋回方向は事前の設定を参照
	 * @param _curve_persent カーブの度合い 100でまっすぐ。0で信地旋回?
	 */
	void Curve(double _curve_persent);
	
	void Curve(YesNo _is_turn_r, YesNo _is_turn_l, double _curve_persent);
	
	/**
	 * @fn 緩旋回、要するにカーブ。旋回方向は事前の設定を参照
	 * @param _move_deg 移動方向
	 * @param _curve_persent カーブの度合い 100でまっすぐ。0で信地旋回?
	 */
	void Curve(double _move_deg, double _curve_persent);
	
	void Curve(double _move_deg, YesNo _is_turn_r, YesNo _is_turn_l, double _curve_persent);
	
	/**
	 * @fn 超信地旋回
	 */
	void SpinTurn();
	
	/** 
	 * @fn 信地旋回。指定した車輪を軸にして旋回する。
	 * @param _turn_pivot 回転中心
	 */
	void PivotTurn(FourWheelPlace _turn_pivot);	
	
	/**
	 * @fn 止める 
	 */
	void Stop();
	
	/**
	 * @fn MDCへ送信
	 */
	void Write();
	
	/**
	 * @fn クリアデータをMDCへ送信
	 */
	void Write_clear();
	
	/**
	 * @fn ポテンションメータのデータを表示
	 */
	void Dispaly_meter_data(LcdAdrs _adrs);
	
	/**
	 * @fn 現在角を表示
	 */
	void Dispaly_current_angle(LcdAdrs _adrs);
	
	/**
	 * @fn 目標角を表示
	 */
	void Dispaly_target_angle(LcdAdrs _adrs);
	
	/**
	 * @fn 角度モータの出力を表示
	 */
	void Display_angle_motor_power(LcdAdrs _adrs);
	
	/**
	 * @fn 車輪のモータの出力を表示
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

