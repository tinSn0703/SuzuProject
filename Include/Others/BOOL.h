/**
 * @file	BOOL.h
 * @brief	�_���^�̒�`
 * @author	Sowa Naoki
 */

#pragma once

/************************************************************************/

#include "Typedef.h"

/************************************************************************/

enum BOOL
{
	FALSE	= 0,
	TRUE	= 1
};

/************************************************************************/

//----------------------------------------------------------------------//

typedef BOOL YesNo;

#define YES TRUE
#define NO	FALSE

//----------------------------------------------------------------------//

typedef BOOL HighLow;

#define HIGH	TRUE
#define LOW		FALSE

//----------------------------------------------------------------------//

typedef BOOL OnOff;

#define ON	TRUE
#define OFF	FALSE

//----------------------------------------------------------------------//

/************************************************************************/

//----------------------------------------------------------------------//

/* BOOL�ɕϊ�����B0 -> FALSE, ����ȊO -> TRUE */
inline BOOL To_BOOL(const int _data)
{
	return ((_data == 0) ? FALSE : TRUE);
}

//----------------------------------------------------------------------//

/* TRUE�AFALSE�����ւ��� */
inline BOOL Reversal(const BOOL _bool)
{
	return (BOOL)(~((uchar)_bool) & 1);
}

//----------------------------------------------------------------------//

/* �����̘_���a��Ԃ� */
inline BOOL Compute_OR_BOOL(const BOOL _left, const BOOL _right)
{
	return (BOOL)(((uchar)_left | (uchar)_right) & 1);
}

//----------------------------------------------------------------------//

/* �����̔r���I�_���a��Ԃ� */
inline BOOL Compute_XOR(const BOOL _left, const BOOL _right)
{
	return (BOOL)(((uchar)_left ^ (uchar)_right) & 1);
}

//----------------------------------------------------------------------//

/* �����̘_���ς�Ԃ� */
inline BOOL Conpute_AND(const BOOL _left, const BOOL _right)
{
	return (BOOL)(((uchar)_left & (uchar)_right) & 1);
}

//----------------------------------------------------------------------//

/* _check_data��_bit�́ATRUE�ł���? */
inline BOOL Is_true_the(const int _check_data, const int _bit)
{
	return (BOOL)((_check_data >> _bit) & 1);
}

//----------------------------------------------------------------------//

/* _check_data��_bit�́AFALSE�ł���? */
inline BOOL Is_false_the(const int _check_data, const int _bit)
{
	return (BOOL)(~(_check_data >> _bit) & 1);
}

//----------------------------------------------------------------------//

/* _check_data��_bit_0��_bit_1�́ATRUE�ł���? */
inline BOOL Are_true_the 
(
	const int	_check_data, 
	const int	_bit_0, 
	const int	_bit_1
)
{
	return (BOOL)
	(
		(_check_data >> _bit_0) & (_check_data >> _bit_1) & 1
	);
}

//----------------------------------------------------------------------//

/* _check_data��_bit_0��_bit_1�́AFALSE�ł���? */
inline BOOL Are_false_the 
(
	const int	_check_data, 
	const int	_bit_0, 
	const int	_bit_1
)
{
	return (BOOL)
	(
		~((_check_data >> _bit_0) & (_check_data >> _bit_1)) & 1
	);
}

//----------------------------------------------------------------------//

/************************************************************************/

//----------------------------------------------------------------------//

inline BOOL operator ~ (const BOOL _bool)
{
	return Reversal(_bool);
}

//----------------------------------------------------------------------//

inline BOOL operator | (const BOOL _left, const BOOL _right)
{
	return Compute_OR_BOOL(_left, _right);
}

//----------------------------------------------------------------------//

inline BOOL operator ^ (const BOOL _left, const BOOL _right)
{
	return Compute_XOR(_left, _right);
}

//----------------------------------------------------------------------//

inline BOOL operator & (const BOOL _left, const BOOL _right)
{
	return Conpute_AND(_left, _right);
}

//----------------------------------------------------------------------//

/************************************************************************/
