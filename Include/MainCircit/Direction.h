

#pragma once

/************************************************************************/

namespace Direction
{

//----------------------------------------------------------------------//

enum X
{
	EAST = 1,
	WEST = 2,
	
	RIGHT = 1,
	LEFT  = 2,
	
	xCENTER = 3
};

//----------------------------------------------------------------------//

enum Y
{
	NORTH = 1,
	SOUTH = 2,
	
	OVER  = 1,
	UNDER = 2,
	
	yCENTER = 3
};

//----------------------------------------------------------------------//

}

/************************************************************************/

typedef Direction::Y DirectionY;
typedef Direction::X DirectionX;

/************************************************************************/

//----------------------------------------------------------------------//

inline DirectionY Reversal (const DirectionY _direc)
{
	return 
	(
		_direc == Direction::NORTH ? Direction::SOUTH :
		_direc == Direction::SOUTH ? Direction::NORTH :
		Direction::yCENTER
	);
}

//----------------------------------------------------------------------//

inline DirectionY To_DirectionY (const int _data)
{
	return ((_data & 3) ? (DirectionY)(_data & 3) : Direction::yCENTER);
}

//----------------------------------------------------------------------//

inline BOOL Is_Direction_north(const DirectionY _direc)
{
	return (_direc == Direction::NORTH ? TRUE : FALSE);
}

//----------------------------------------------------------------------//

inline BOOL Is_Direction_south(const DirectionY _direc)
{
	return (_direc == Direction::SOUTH ? TRUE : FALSE);
}

//----------------------------------------------------------------------//

inline BOOL Is_Direction_zero(const DirectionY _direc)
{
	return (_direc == Direction::yCENTER ? TRUE : FALSE);
}

//----------------------------------------------------------------------//

inline DirectionX Reversal(const DirectionX _direc)
{
	return
	(
		_direc == Direction::EAST ? Direction::WEST :
		_direc == Direction::WEST ? Direction::EAST :
		Direction::xCENTER
	);
}

//----------------------------------------------------------------------//

inline DirectionX To_DirectionX(const int _data)
{
	return ((_data & 0b11) ? (DirectionX)(_data & 0b11) : Direction::xCENTER);
}

//----------------------------------------------------------------------//

inline BOOL Is_Direction_east(const DirectionX _direc)
{
	return (_direc == Direction::EAST ? TRUE : FALSE);
}

//----------------------------------------------------------------------//

inline BOOL Is_Direction_west(const DirectionX _direc)
{
	return (_direc == Direction::WEST ? TRUE : FALSE);
}

//----------------------------------------------------------------------//

inline BOOL Is_Direction_zero(const DirectionX _direc)
{
	return (_direc == Direction::xCENTER ? TRUE : FALSE);
}

//----------------------------------------------------------------------//

inline void Shift_DirectionXY_by_45deg (DirectionX *_x, DirectionY *_y)
{
	const DirectionX _temp_x = To_DirectionX((*_x) &			(*_y));
	const DirectionY _temp_y = To_DirectionY((*_y) & Reversal	(*_x));

	*_x = _temp_x;
	*_y = _temp_y;
}

//----------------------------------------------------------------------//

inline void Shift_DirectionXY_by_90deg (DirectionX *_x, DirectionY *_y)
{
	const DirectionX _temp_x = (DirectionX)			(*_y);
	const DirectionY _temp_y = (DirectionY)Reversal	(*_x);

	*_x = _temp_x;
	*_y = _temp_y;
}

//----------------------------------------------------------------------//

/************************************************************************/

