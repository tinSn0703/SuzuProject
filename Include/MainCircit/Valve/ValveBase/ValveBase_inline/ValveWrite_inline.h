

#pragma once

namespace ClassValve
{

//----------------------------------------------------------------------//

inline void ValveSet :: Want_to_open_0(const BOOL _yes)	{	_mem_data._bit._0 = _yes;	}
inline void ValveSet :: Want_to_open_1(const BOOL _yes)	{	_mem_data._bit._1 = _yes;	}
inline void ValveSet :: Want_to_open_2(const BOOL _yes)	{	_mem_data._bit._2 = _yes;	}
inline void ValveSet :: Want_to_open_3(const BOOL _yes)	{	_mem_data._bit._3 = _yes;	}
inline void ValveSet :: Want_to_open_4(const BOOL _yes)	{	_mem_data._bit._4 = _yes;	}
inline void ValveSet :: Want_to_open_5(const BOOL _yes)	{	_mem_data._bit._5 = _yes;	}
inline void ValveSet :: Want_to_open_6(const BOOL _yes)	{	_mem_data._bit._6 = _yes;	}
inline void ValveSet :: Want_to_open_7(const BOOL _yes)	{	_mem_data._bit._7 = _yes;	}

//----------------------------------------------------------------------//

inline void ValveSet :: Want_to_open (const ValveNum _num, const BOOL _yes_or_no)
{
	_mem_data._all &= ~(1 << _num);
	
	_mem_data._all |= (_yes_or_no << _num);
}

//----------------------------------------------------------------------//

inline void ValveSet :: Set (const ValveData _data)
{
	_mem_data._all = _data;	
}

//----------------------------------------------------------------------//

};
