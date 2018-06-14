
#pragma once

/************************************************************************/

#ifdef __cplusplus	//C++の時用

namespace LCD
{

/************************************************************************/

//----------------------------------------------------------------------//

/**
 *	　LCDを使用可能な状態にする関数。
 */
inline void Initialize()
{
	INI_LCD();
}

//----------------------------------------------------------------------//

/**
 *	LCDが起動していますか?
 */
inline int Is_initialize()
{
	return IS_LCD_INI();
}

//----------------------------------------------------------------------//

/**
 *	　LCDの表示を全て消す関数。
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
 *	LCDに文字を表示する関数。
 *
 *	_adrs	: 表示する場所
 *	_char	: 表示する文字
**/
inline void Write(const LcdAdrs _adrs, const char _char)
{
	PUT_LCD(_adrs, _char);
}

//----------------------------------------------------------------------// 

/**
 *	LCDに文字列を表示する関数。
 *
 *	_adrs	: 表示の先頭の場所
 *	_str	: 表示する文字列
**/
inline void Write(const LcdAdrs _adrs, const char _str[])
{
	STR_LCD(_adrs, _str);
}

//----------------------------------------------------------------------//

/**
 *	 LCDに文字列を表示する関数。
 *	 一文字ずつ順番に表示していく
 * 
 *	_adrs	: 表示の先頭の場所
 *	_str	: 表示する文字列
 *	_ms		: 待ち時間
**/
inline void Write(const LcdAdrs _adrs, const char _str[], const int _ms)
{
	STR_LCD_WAVE(_adrs, _str, _ms);
}

//----------------------------------------------------------------------//

/**
 *	LCDに数列を表示する関数。
 * 
 *	_adrs	: 表示の先頭の場所
 *	_number	: 表示する数値
 *	_digit	: 表示したい桁数
 *	decimal	: 表示したい進数 (2 ～ 16進数まで)
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
