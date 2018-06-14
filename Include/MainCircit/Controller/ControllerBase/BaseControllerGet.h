
#pragma once

/************************************************************************/

#include "BaseControllerBase.h"

#include <MainCircit/Direction.h>

/************************************************************************/

namespace Controller
{
namespace Base
{

/************************************************************************/

class ControllerGet : public virtual ControllerBase
{
//function
public:
	
	ControllerGet();
	
	/* �E�X�e�B�b�N�̉��̃f�[�^��Ԃ� */
	DirectionX Get_R_stick_x();
	
	/* �E�X�e�B�b�N�̏c�̃f�[�^��Ԃ� */
	DirectionY Get_R_stick_y();
	
	/* ���X�e�B�b�N�̉��̃f�[�^��Ԃ� */
	DirectionX Get_L_stick_x();
	
	/* ���X�e�B�b�N�̏c�̃f�[�^��Ԃ� */
	DirectionY Get_L_stick_y();
	
	/* x�����̌X�� */
	DirectionX Get_cross_key_x();
	
	/* y�����̌X�� */
	DirectionY Get_cross_key_y();
	
	/* �S�Ẵf�[�^�Ԃ� */
	ullint Get_data();
	
	/* �S�Ẵf�[�^��1Byte���Ԃ� */
	ControllerData Get_data(uByte _num);
	
	/* �w�肵���R�}���h�̏�Ԃ�Ԃ� */
	Btn operator () (ControllerBtn _command);
	Btn operator () (ControllerCrossX _x, ControllerCrossY _y);
	Btn operator () (ControllerCrossX _command);
	Btn operator () (ControllerCrossY _command);
	Btn operator () (ControllerRStickX _x, ControllerRStickY _y);
	Btn operator () (ControllerRStickX _command);
	Btn operator () (ControllerRStickY _command);
	Btn operator () (ControllerLStickX _x, ControllerLStickY _y);
	Btn operator () (ControllerLStickX _command);
	Btn operator () (ControllerLStickY _command);
	DirectionX operator () (ControllerDirecX _command);
	DirectionY operator () (ControllerDirecY _command);
	
private:
	
	int Get_base(uByte _bit, uByte _and);
};

/************************************************************************/

//----------------------------------------------------------------------//

inline int ControllerGet::Get_base (const uByte _bit, const uByte _and)
{
	return ((this->_mem_data._all_data >> _bit) & _and);
}

//----------------------------------------------------------------------//

inline DirectionX ControllerGet::Get_R_stick_x()
{
	return this->_mem_data._command._stick_right_x;
}

//----------------------------------------------------------------------//

inline DirectionY ControllerGet::Get_R_stick_y()
{
	return this->_mem_data._command._stick_right_y;
}

//----------------------------------------------------------------------//

inline DirectionX ControllerGet::Get_L_stick_x()
{
	return this->_mem_data._command._stick_left_x;
}

//----------------------------------------------------------------------//

inline DirectionY ControllerGet::Get_L_stick_y()
{
	return this->_mem_data._command._stick_left_y;
}

//----------------------------------------------------------------------//

inline DirectionX ControllerGet::Get_cross_key_x()
{
	return this->_mem_data._command._cross_x;
}

//----------------------------------------------------------------------//

inline DirectionY ControllerGet::Get_cross_key_y()
{
	return this->_mem_data._command._cross_y;
}

//----------------------------------------------------------------------//

inline ullint ControllerGet::Get_data()
{
	return this->_mem_data._all_data;
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator() (const ControllerBtn _command)
{
	return (Btn)Get_base((uByte)_command, 1);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator() (const ControllerCrossX _x, const ControllerCrossY _y)
{
	return ((Get_cross_key_x() == (DirectionX)_x) && (Get_cross_key_y() == (DirectionY)_y) ? YES : NO);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator() (const ControllerCrossX _command)
{
	return ((Get_cross_key_x() == (DirectionX)_command) ? YES : NO);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator() (const ControllerCrossY _command)
{
	return ((Get_cross_key_y() == (DirectionY)_command) ? YES : NO);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator() (const ControllerRStickX _x, const ControllerRStickY _y)
{
	return ((Get_R_stick_x() == (DirectionX)_x) && (Get_R_stick_y() == (DirectionY)_y) ? YES : NO);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator() (const ControllerRStickX _command)
{
	return ((Get_R_stick_x() == (DirectionX)_command) ? YES : NO);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator () (const ControllerRStickY _command)
{
	return ((Get_R_stick_y() == (DirectionY)_command) ? YES : NO);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator () (const ControllerLStickX _x, const ControllerLStickY _y)
{
	return ((Get_L_stick_x() == (DirectionX)_x) && (Get_L_stick_y() == (DirectionY)_y)? YES : NO);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator () (const ControllerLStickX _command)
{
	return ((Get_L_stick_x() == (DirectionX)_command) ? YES : NO);
}

//----------------------------------------------------------------------//

inline Btn ControllerGet::operator () (const ControllerLStickY _command)
{
	return ((Get_L_stick_y() == (DirectionY)_command) ? YES : NO);
}

//----------------------------------------------------------------------//

inline DirectionX ControllerGet::operator () (const ControllerDirecX _command)
{
	return (DirectionX)Get_base((uByte)_command, 3);
}

//----------------------------------------------------------------------//

inline DirectionY ControllerGet::operator () (const ControllerDirecY _command)
{
	return (DirectionY)Get_base((uByte)_command, 3);
}

//----------------------------------------------------------------------//

/************************************************************************/

}
}

/************************************************************************/
