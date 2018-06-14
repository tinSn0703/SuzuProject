

#pragma once

#include <string.h>

#include "BOOL.h"

/************************************************************************/

typedef unsigned int StrSize;

/************************************************************************/

//----------------------------------------------------------------------//

inline StrSize Str_size (const char * _str)
{
	sint i = 0;
	
	while (_str[i] != '\0')	i ++;
	
	return i;
}

//----------------------------------------------------------------------//

inline BOOL Str_comp (const char _str_base[], const char _str_comp[])
{
	uByte i = 0;
	
	while (1)
	{
		if (_str_base[i] == '\0')
		{
			return TRUE;
		}
		else if (_str_base[i] != _str_comp[i])
		{
			break;
		}
		
		i ++;
	}
	
	return FALSE;
}

//----------------------------------------------------------------------//

inline BOOL Str_comp_same_time
(
	const char _str_base_0[], 
	const char _str_base_1[],
	const char _str_comp[]
)
{
	uByte i = 0;
	
	while (1)
	{
		if ((_str_base_0[i] == '\0') || (_str_base_1[i] == '\0'))
		{
			return TRUE;
		}
		else if ((_str_base_0[i] != _str_comp[i]) && (_str_base_1[i] != _str_comp[i]))
		{
			break;
		}
		
		i ++;
	}
	
	return FALSE;
}

//----------------------------------------------------------------------//

inline BOOL Str_comp_same_time
(
	const char _str_base_0[],
	const char _str_base_1[],
	const char _str_base_2[],
	const char _str_comp[]
)
{
	uByte i = 0;
	
	while (1)
	{
		if ((_str_base_0[i] == '\0') || (_str_base_1[i] == '\0') || (_str_base_2[i] == '\0'))
		{
			return TRUE;
		}
		else if ((_str_base_0[i] != _str_comp[i]) && (_str_base_1[i] != _str_comp[i]) && (_str_base_2[i] != _str_comp[i]))
		{
			break;
		}
		
		i ++;
	}
	
	return FALSE;
}

//----------------------------------------------------------------------//

inline char * Str_copy (char *_str, const char *_str_copy)
{
	sint i = 0;
	
	for (i = 0; ((_str_copy[i] != '\0') && (_str[i] != '\0')); i++)
	{
		_str[i] = _str_copy[i];
	}
	
	_str[i] = '\0';
	
	return _str;
}

//----------------------------------------------------------------------//

/* •¶š—ñ‚ğŒ‹‡‚·‚éB */
inline char * Str_add (char _str[], const char _str_add[])
{
	const StrSize _str_size = Str_size(_str);
	
	sint i = 0;
	
	for (i = 0; _str_add[i] != '\0'; i++)	_str[_str_size + i] = _str_add[i];
	
	_str[_str_size + i] = '\0';
	
	return _str;
}

//----------------------------------------------------------------------//

inline char Convert_hex_to_char (const uByte _num)
{
	switch (_num & 0xf)
	{
		case 0x0:	return '0';
		case 0x1:	return '1';
		case 0x2:	return '2';
		case 0x3:	return '3';
		case 0x4:	return '4';
		case 0x5:	return '5';
		case 0x6:	return '6';
		case 0x7:	return '7';
		case 0x8:	return '8';
		case 0x9:	return '9';
		case 0xA:	return 'A';
		case 0xB:	return 'B';
		case 0xC:	return 'C';
		case 0xD:	return 'D';
		case 0xE:	return 'E';
		case 0xF:	return 'F';
	};
	
	return '\0';
}

//----------------------------------------------------------------------//

inline uByte Convert_char_to_hex (const char _char)
{
	switch (_char)
	{
		case '0':	return 0x0;
		case '1':	return 0x1;
		case '2':	return 0x2;
		case '3':	return 0x3;
		case '4':	return 0x4;
		case '5':	return 0x5;
		case '6':	return 0x6;
		case '7':	return 0x7;
		case '8':	return 0x8;
		case '9':	return 0x9;
		case 'a':	
		case 'A':	return 0xA;
		case 'b':	
		case 'B':	return 0xB;
		case 'c':	
		case 'C':	return 0xC;
		case 'd':	
		case 'D':	return 0xD;
		case 'e':	
		case 'E':	return 0xE;
		case 'f':
		case 'F':	return 0xF;
	};
	
	return 0;
}

//----------------------------------------------------------------------//

/************************************************************************/
