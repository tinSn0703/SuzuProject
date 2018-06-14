/*
 * Parallel.c
 *
 * Created: 2018/03/20 14:47:29
 *  Author: FUJITSU
 */ 

#include <avr/io.h>

#include "Parallel.h"

/************************************************************************/

typedef unsigned char uchar;
typedef unsigned long int ulint;

typedef ulint ReadData;
typedef uchar WriteData; 

typedef uchar WriteAndData;

/************************************************************************/

//----------------------------------------------------------------------//

#define Write_Base(_port)	(_port = (_port & _line) | _data)

static void Write_PORTA(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTA);	}
static void Write_PORTB(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTB);	}
static void Write_PORTC(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTC);	}
static void Write_PORTD(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTD);	}
static void Write_PORTE(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTE);	}
static void Write_PORTF(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTF);	}
static void Write_PORTG(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTG);	}
static void Write_PORTH(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTH);	}
static void Write_PORTJ(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTJ);	}
static void Write_PORTK(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTK);	}
static void Write_PORTL(WriteAndData _line, const WriteData _data)	{	Write_Base(PORTL);	}

//----------------------------------------------------------------------//

#define Read_Base(_port)  return (_port)

static ReadData Read_PINA()	{	Read_Base(PINA);	}
static ReadData Read_PINB()	{	Read_Base(PINB);	}
static ReadData Read_PINC()	{	Read_Base(PINC);	}
static ReadData Read_PIND()	{	Read_Base(PIND);	}
static ReadData Read_PINE()	{	Read_Base(PINE);	}
static ReadData Read_PINF()	{	Read_Base(PINF);	}
static ReadData Read_PING()	{	Read_Base(PING);	}
static ReadData Read_PINH()	{	Read_Base(PINH);	}
static ReadData Read_PINJ()	{	Read_Base(PINJ);	}
static ReadData Read_PINK()	{	Read_Base(PINK);	}
static ReadData Read_PINL()	{	Read_Base(PINL);	}

/*
static ReadData Read_PORTA()	{	Read_Base(PORTA);	}
static ReadData Read_PORTB()	{	Read_Base(PORTB);	}
static ReadData Read_PORTC()	{	Read_Base(PORTC);	}
static ReadData Read_PORTD()	{	Read_Base(PORTD);	}
static ReadData Read_PORTE()	{	Read_Base(PORTE);	}
static ReadData Read_PORTF()	{	Read_Base(PORTF);	}
static ReadData Read_PORTG()	{	Read_Base(PORTG);	}
static ReadData Read_PORTH()	{	Read_Base(PORTH);	}
static ReadData Read_PORTJ()	{	Read_Base(PORTJ);	}
static ReadData Read_PORTK()	{	Read_Base(PORTK);	}
static ReadData Read_PORTL()	{	Read_Base(PORTL);	}
*/

/************************************************************************/

typedef void (*fpWrite)(WriteAndData, WriteData );
typedef ReadData (*fpRead)();

/************************************************************************/

const static fpWrite Write_PORT[11] =
{
	Write_PORTA,
	Write_PORTB,
	Write_PORTC,
	Write_PORTD,
	Write_PORTE,
	Write_PORTF,
	Write_PORTG,
	Write_PORTH,
	Write_PORTJ,
	Write_PORTK,
	Write_PORTL
};

const static fpRead Read_PIN[11] =
{
	Read_PINA,
	Read_PINB,
	Read_PINC,
	Read_PIND,
	Read_PINE,
	Read_PINF,
	Read_PING,
	Read_PINH,
	Read_PINJ,
	Read_PINK,
	Read_PINL
};

/*
const fpRead Read_PORT[11] =
{
	Read_PORTA,
	Read_PORTB,
	Read_PORTC,
	Read_PORTD,
	Read_PORTE,
	Read_PORTF,
	Read_PORTG,
	Read_PORTH,
	Read_PORTJ,
	Read_PORTK,
	Read_PORTL
};
*/

/************************************************************************/

//----------------------------------------------------------------------//

Parallel * Parallel_Initialize(Parallel *_object, const unsigned char _size, const ReadOrWrite _read_or_write)
{
	_object->_size = _size;
	_object->_read_or_write = _read_or_write;
	_object->_num_set_line = 0;
	_object->_is_setting_start = 0;
	
	return _object;
}

//----------------------------------------------------------------------//

static void Parallel_Set_line_data(Parallel *_object, const IoPort _set_port, const IoBit _set_bit)
{
	if (_object->_is_setting_start == 0)
	{
		_object->_num_set_line = 0;
		_object->_is_setting_start = 1;
		
		_object->_line[_object->_num_set_line]._port = _set_port;
		_object->_line[_object->_num_set_line]._bit_head = _set_bit;
		_object->_line[_object->_num_set_line]._data_bit = 0;
	}
	else
	{
		if	(
				(_object->_line[_object->_num_set_line]._port == _set_port) &&
				(_object->_line[_object->_num_set_line]._bit_tail + 1 == _set_bit)
			)
		{
			_object->_line[_object->_num_set_line]._bit_tail = _set_bit;
		}
		else
		{
			_object->_num_set_line += 1;
			
			_object->_line[_object->_num_set_line]._port = _set_port;
			_object->_line[_object->_num_set_line]._bit_head = _set_bit;
			_object->_line[_object->_num_set_line]._data_bit = _object->_line[_object->_num_set_line - 1]._data_bit + _object->_line[_object->_num_set_line - 1]._bit_tail - _object->_line[_object->_num_set_line - 1]._bit_head + 1;
		}
	}
		
		_object->_line[_object->_num_set_line]._bit_tail = _set_bit;
		
		_object->_line[_object->_num_set_line]._and |= (1 << _set_bit);
		_object->_line[_object->_num_set_line]._and_r = ~(_object->_line[_object->_num_set_line]._and);
}

//----------------------------------------------------------------------//

Parallel * Parallel_Set_port(Parallel *_object, const unsigned char _num_line, const IoPort _set_port, const IoBit _set_bit)
{
	if ( _num_line < _object->_size)
	{
		switch (_set_port)
		{
			case NUM_A:	DDRA &= ~(1 << _set_bit);	DDRA |= (_object->_read_or_write << _set_bit);	break;
			case NUM_B:	DDRB &= ~(1 << _set_bit);	DDRB |= (_object->_read_or_write << _set_bit);	break;
			case NUM_C:	DDRC &= ~(1 << _set_bit);	DDRC |= (_object->_read_or_write << _set_bit);	break;
			case NUM_D:	DDRD &= ~(1 << _set_bit);	DDRD |= (_object->_read_or_write << _set_bit);	break;
			case NUM_E:	DDRE &= ~(1 << _set_bit);	DDRE |= (_object->_read_or_write << _set_bit);	break;
			case NUM_F:	DDRF &= ~(1 << _set_bit);	DDRF |= (_object->_read_or_write << _set_bit);	break;
			case NUM_G:	DDRG &= ~(1 << _set_bit);	DDRG |= (_object->_read_or_write << _set_bit);	break;
			case NUM_H:	DDRH &= ~(1 << _set_bit);	DDRH |= (_object->_read_or_write << _set_bit);	break;
			case NUM_J:	DDRJ &= ~(1 << _set_bit);	DDRJ |= (_object->_read_or_write << _set_bit);	break;
			case NUM_K:	DDRK &= ~(1 << _set_bit);	DDRK |= (_object->_read_or_write << _set_bit);	break;
			case NUM_L: DDRL &= ~(1 << _set_bit);	DDRL |= (_object->_read_or_write << _set_bit);	break;
		}
		
		Parallel_Set_line_data(_object, _set_port, _set_bit);
	}
	
	return _object;
}

//----------------------------------------------------------------------//

void Parallel_Write(Parallel *_object, const ulint _write_data)
{
	for (uchar i = 0; i <= _object->_num_set_line; i ++)
	{
		Write_PORT[_object->_line[i]._port](_object->_line[i]._and_r, ((_write_data >> _object->_line[i]._data_bit) << _object->_line[i]._bit_head) & _object->_line[i]._and);
	}
}

//----------------------------------------------------------------------//

ulint Parallel_Read(Parallel *_object)
{
	ulint _read_data = 0;
	
	for (uchar i = 0; i <= _object->_num_set_line; i++)
	{
		_read_data |= (((Read_PIN[_object->_line[i]._port]() & _object->_line[i]._and) >> _object->_line[i]._bit_head) << _object->_line[i]._data_bit);
	}
	
	return _read_data;
}

//----------------------------------------------------------------------//

/************************************************************************/
