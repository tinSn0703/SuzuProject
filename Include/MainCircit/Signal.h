

#pragma once

/************************************************************************/

enum Signal
{
	SIGNAL_FREE		= 0b00,	//フリー
	SIGNAL_REVERSE	= 0b01,	//逆回転
	SIGNAL_FORWARD	= 0b10,	//正回転
	SIGNAL_BREAK	= 0b11	//ブレーキ
};

/************************************************************************/

//----------------------------------------------------------------------//

inline Signal Want_to_make_forward(const YesNo _yes_no)
{
	return (_yes_no ? SIGNAL_FORWARD : SIGNAL_REVERSE);
}

//----------------------------------------------------------------------//

inline Signal Want_to_make_reverse(const YesNo _yes_no)
{
	return (_yes_no ? SIGNAL_REVERSE : SIGNAL_FORWARD);
}

//----------------------------------------------------------------------//

inline Signal To_Signal (const int _data)
{
	return (Signal)(_data & 3);
}

//----------------------------------------------------------------------//

inline Signal Reversal (const Signal _sig)
{
	return
	(
		(_sig == SIGNAL_FORWARD) ? SIGNAL_REVERSE :
		(_sig == SIGNAL_REVERSE) ? SIGNAL_FORWARD :
		_sig
	);
}

//----------------------------------------------------------------------//

inline BOOL Is_Signal_rotation (const Signal _sig)
{
	return Is_true_the(0b0110, _sig);
}

//----------------------------------------------------------------------//

inline BOOL Is_Signal_stop (const Signal _sig)
{
	return Is_true_the(0b1001, _sig);
}

//----------------------------------------------------------------------//

/************************************************************************/
