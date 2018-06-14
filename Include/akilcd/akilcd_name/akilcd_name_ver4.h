
#pragma once

/************************************************************************/

#ifdef __cplusplus	//C++�̎��p

namespace LCD
{

/************************************************************************/

//----------------------------------------------------------------------//

/**
 *	�@LCD���g�p�\�ȏ�Ԃɂ���֐��B
 */
inline void Initialize()
{
	INI_LCD();
}

//----------------------------------------------------------------------//

/**
 *	LCD���N�����Ă��܂���?
 */
inline int Is_initialize()
{
	return IS_LCD_INI();
}

//----------------------------------------------------------------------//

/**
 *	�@LCD�̕\����S�ď����֐��B
 */
inline void Clear()
{
	CLR_DISPLAY();
}

//----------------------------------------------------------------------//

inline void Clear_over()
{
	STR_LCD(0x00, LCD_SEMI_CLEAR);
}

//----------------------------------------------------------------------//

inline void Clear_under()
{
	STR_LCD(0x40, LCD_SEMI_CLEAR);
}

//----------------------------------------------------------------------//

/**
 *	LCD�ɕ�����\������֐��B
 *
 *	_adrs	: �\������ꏊ
 *	_char	: �\�����镶��
**/
inline void Write(const LcdAdrs _adrs, const char _char)
{
	PUT_LCD(_adrs, _char);
}

//----------------------------------------------------------------------// 

/**
 *	LCD�ɕ������\������֐��B
 *
 *	_adrs	: �\���̐擪�̏ꏊ
 *	_str	: �\�����镶����
**/
inline void Write(const LcdAdrs _adrs, const char _str[])
{
	STR_LCD(_adrs, _str);
}

//----------------------------------------------------------------------//

/**
 *	 LCD�ɕ������\������֐��B
 *	 �ꕶ�������Ԃɕ\�����Ă���
 * 
 *	_adrs	: �\���̐擪�̏ꏊ
 *	_str	: �\�����镶����
 *	_ms		: �҂�����
**/
inline void Write(const LcdAdrs _adrs, const char _str[], const int _ms)
{
	STR_LCD_WAVE(_adrs, _str, _ms);
}

//----------------------------------------------------------------------//

/**
 *	LCD�ɐ����\������֐��B
 * 
 *	_adrs	: �\���̐擪�̏ꏊ
 *	_number	: �\�����鐔�l
 *	_digit	: �\������������
 *	decimal	: �\���������i�� (2 �` 16�i���܂�)
**/
inline void Write
(
	const LcdAdrs	_adrs,
	unsigned long	_number,
	const Digit		_digit,
	const Decimal	_decimal
)
{
	PUT_NUM(_adrs, _number, _digit, _decimal);
}

//----------------------------------------------------------------------//

inline void Write_integer
(
	const LcdAdrs	_adrs,
	const long		_number,
	const Digit		_digit,
	const Decimal	_decimal
)
{
	if (_number < 0)
	{
		PUT_LCD(_adrs, '-');
		
		PUT_NUM(_adrs + 1, _number * -1, _digit, _decimal);
	}
	else
	{
		PUT_LCD(_adrs, ' ');
		
		PUT_NUM(_adrs + 1, _number, _digit, _decimal);
	}
}

//----------------------------------------------------------------------//

/************************************************************************/

};

#endif /*__cplusplus*/

/************************************************************************/
