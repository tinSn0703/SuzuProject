
#pragma once

/************************************************************************/

#ifdef __cplusplus	//C++�̎��p

	extern "C"	{

#endif /*__cplusplus*/

/************************************************************************/

/**
 *	�@�v���O�����ɂ���Ă͂��̊֐����g���Ă���̂ŁB
 *	�@���g�͓��ɂȂ��B
 */
inline void INI_LCD_PORT()	{}

/**
 *	�@LCD���g�p�\�ȏ�Ԃɂ���֐��B
 *	�@���̊֐����Ăяo���΁ALCD���g���Ƃ��ł��܂��B
 */
void INI_LCD();

/**
 *	LCD���N�����Ă��܂���?
 */
int IS_LCD_INI();

/**
 *	�@LCD�̕\����S�ď����֐��B
 */
void CLR_DISPLAY();

/**
 *	�@������LCD�ɕ\������֐��B
 * 
 *	_adrs	: �\������ꏊ
 *	_char	: �\�����镶��
 */
void PUT_LCD(LcdAdrs _adrs, const char _char);

/**
 *	 LCD�ɕ������\������֐��B
 * 
 *	_adrs	: �\���̐擪�̏ꏊ
 *	_str	: �\�����镶����
 */
void STR_LCD(LcdAdrs _adrs, const char _str[]);

/**
 *	 LCD�ɕ������\������֐��B
 *	 �ꕶ�������Ԃɕ\�����Ă���
 * 
 *	_adrs	: �\���̐擪�̏ꏊ
 *	_str	: �\�����镶����
 *	_ms		: �҂�����
 */
void STR_LCD_WAVE(LcdAdrs _adrs, const char _str[], int _ms);

/**
 *	�@���l��LCD�ɕ\������֐��B
 * 
 *	_adrs		: �\���̐擪�̏ꏊ
 *	_number		: �\�����鐔�l
 *	_digit		: �\������������
 *	decimal		: �\���������i�� (2 �` 16�i���܂�)
 */
void PUT_NUM(LcdAdrs _adrs, unsigned long _number, Digit _digit, Decimal _decimal);

/************************************************************************/

#ifdef __cplusplus	//C++�̎��p

	}

#endif /*__cplusplus*/

/************************************************************************/
