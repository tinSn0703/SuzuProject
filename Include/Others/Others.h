

#pragma once

#include "Typedef.h"
#include "BOOL.h"
#include "Str.h"

#define PI 3.14159265359

#define RAD_PER_DEG 0.017453292 //(2 * PI) / 360
#define DEG_PER_RAD 57.29577951

/************************************************************************/

//----------------------------------------------------------------------//

template <class Type>
/* _value‚ÍA_max‚Æ_min‚ÌŠÔ‚Ì’l‚Å‚·‚©? */
inline BOOL Is_withen
(
	const Type _value,
	const Type _max,
	const Type _min
)
{
	if ((_max >= _value) && (_value >= _min))
	{
		return TRUE;
	}
	
	return FALSE;
}

//----------------------------------------------------------------------//

inline int To_within
(
	const int _value,
	const int _max,
	const int _min
)
{
	return 
	(
		_value > _max ? _max : 
		_value < _min ? _min :
		_value
	);
}

//----------------------------------------------------------------------//

inline int Truncate
(
	const int _value,
	const int _basic_value,
	const int _widch
)
{
	if (Is_withen(_value, (_basic_value + _widch), (_basic_value - _widch)))
	{
		return _basic_value;
	}
	
	return _value;
}

//----------------------------------------------------------------------//

/************************************************************************/
