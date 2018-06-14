
#pragma once

/************************************************************************/
//Bluetooth��H�̊�{�I�ȓ��삩��g����������p�̃N���X
//�����̓R���g���[���̃f�[�^���������߂̃N���X

namespace Bluetooth
{

namespace Bit24
{

/************************************************************************/

class Controller	: private ReceiveCircit
					, public Controller::Base::ControllerRewrite
					, public Controller::Base::ControllerLCD
{
//function
private:
	
	void Allot();
	
protected:
	
	void Read();
	
public:
	
	/**
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	Controller(const UartNum _num_bt_uart, const BOOL _is_data_rewrite = NO);
	
	void Turn_on();
	
	void Turn_on(uByte _num);
	
	void Turn_on_more(uByte _byte);
	
	void Turn_off();
	
	void Turn_off(uByte _num);
	
	void Turn_off_more(uByte _byte);
	
	void Check_read_data();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void Controller::Turn_on()
{
	ReceiveCircit::Turn_on();
}

//----------------------------------------------------------------------//

inline void Controller::Turn_on(const uByte _num)
{
	ReceiveCircit::Turn_on(_num);
}

//----------------------------------------------------------------------//

inline void Controller::Turn_on_more(const uByte _num)
{
	ReceiveCircit::Turn_on_more(_num);
}

//----------------------------------------------------------------------//

inline void Controller::Turn_off()
{
	ReceiveCircit::Turn_off();
}

//----------------------------------------------------------------------//

inline void Controller::Turn_off(const uByte _num)
{
	ReceiveCircit::Turn_off(_num);
}

//----------------------------------------------------------------------//

inline void Controller::Turn_off_more(const uByte _num)
{
	ReceiveCircit::Turn_off_more(_num);
}

//----------------------------------------------------------------------//

inline void Controller::Check_read_data()
{
	ReceiveCircit::Check_read_data();
}

//----------------------------------------------------------------------//

/************************************************************************/

class Dualshock2	: public Controller
					, public Controller::Base::Dualshock2Get
{
public:
	
	/**
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	Dualshock2(UartNum _num_bt_uart, YesNo _is_data_rewrite = NO);
	
	/* �R���g���[���̃f�[�^��ǂށB*/
	void Read();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void Dualshock2 :: Read()
{
	Controller::Read();
}

//----------------------------------------------------------------------//

/************************************************************************/

class Dualshock2AddPush	: public Controller
						, public Base::Dualshock2Get
						, public Base::Dualshock2Push
{
public:
	
	/**
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	Dualshock2AddPush(UartNum _num_bt_uart, YesNo _is_data_rewrite = NO);
	
	/* �R���g���[���̃f�[�^��ǂށB */
	void Read();
};

/************************************************************************/

class WiiClassic	: public Controller
					, public Base::WiiClassicGet
{
public:
	
	/**
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	WiiClassic(UartNum _num_bt_uart, YesNo _is_data_rewrite = NO);
	
	/* �R���g���[���̃f�[�^��ǂށB*/
	void Read();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void WiiClassic :: Read()
{
	Controller::Read();
}

//----------------------------------------------------------------------//

/************************************************************************/

class WiiClassicAddPush	: public Controller
						, public Base::WiiClassicGet
						, public Base::WiiClassicPush
{
public:
	
	/**
	 *	_is_data_rewrite	: �����Ă����f�[�^�����������܂���?
	**/
	WiiClassicAddPush(UartNum _num_bt_uart, BOOL _is_data_rewrite = NO);
	
	/* �R���g���[���̃f�[�^��ǂށB*/
	void Read();
};

/************************************************************************/

};

};

/************************************************************************/
