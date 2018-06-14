
#pragma once

/************************************************************************/

class MotorRotationOnly
{
//variable
private:
	
	Signal _mem_signal :2;
	
	IO::ModeBitOut _mem_io_side_forward;
	IO::ModeBitOut _mem_io_side_reverse;
	
	YesNo _mem_is_io_set :1;
	
	YesNo _mem_is_signal_reverse :1;
	
//function
public:
	
	MotorRotationOnly();
	MotorRotationOnly(IoNum _adrs, IoBit _bit_side_f, IoBit _bit_side_r);
	MotorRotationOnly(IoNum _adrs_side_f, IoBit _bit_side_f, IoNum _adrs_side_r, IoBit _bit_side_r);
	
	void Reset(IoNum _adrs, IoBit _bit_side_f, IoBit _bit_side_r);
	void Reset(IoNum _adrs_side_f, IoBit _bit_side_f, IoNum _adrs_side_r, IoBit _bit_side_r);
	
	void Reset_side_forward(IoNum _adrs, IoBit _bit);
	void Reset_side_reverse(IoNum _adrs, IoBit _bit);
	
	/* ìÆçÏÇîΩì]Ç≥ÇπÇ‹Ç∑Ç© */
	void Want_to_reverse_signal(YesNo _yes_no);
	
	/* ìÆçÏÇÃê›íËÅB*/
	void Set(Signal _signal);
	
	/* ìÆçÏÇï‘Ç∑ */
	Signal Get();
	
	void Write();
	void Write_clear();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline void MotorRotationOnly::Reset
(
	const IoNum _adrs,
	const IoBit _bit_side_f,
	const IoBit _bit_side_r
)
{
	_mem_io_side_forward.Reset(_adrs, _bit_side_f);
	_mem_io_side_reverse.Reset(_adrs, _bit_side_r);
	
	_mem_is_io_set = YES;
	
	_mem_signal = SIGNAL_FREE;
	
	Write_clear();
}

//----------------------------------------------------------------------//

inline void MotorRotationOnly::Reset
(
	const IoNum _adrs_side_f,
	const IoBit _bit_side_f,
	const IoNum _adrs_side_r,
	const IoBit _bit_side_r
)
{
	_mem_io_side_forward.Reset(_adrs_side_f, _bit_side_f);
	_mem_io_side_reverse.Reset(_adrs_side_r, _bit_side_r);
	
	_mem_is_io_set = YES;
	
	_mem_signal = SIGNAL_FREE;
	
	Write_clear();
}

//----------------------------------------------------------------------//

inline void MotorRotationOnly::Reset_side_forward(const IoNum _adrs, const IoBit _bit)
{
	_mem_io_side_forward.Reset(_adrs, _bit);
}

//----------------------------------------------------------------------//

inline void MotorRotationOnly::Reset_side_reverse(const IoNum _adrs, const IoBit _bit)
{
	_mem_io_side_reverse.Reset(_adrs, _bit);
}

//----------------------------------------------------------------------//

inline void MotorRotationOnly::Want_to_reverse_signal(const YesNo _yes_no)
{
	_mem_is_signal_reverse = _yes_no;
}

//----------------------------------------------------------------------//

inline void MotorRotationOnly::Set(const Signal _signal)
{
	_mem_signal = (_mem_is_signal_reverse ? Reversal(_signal) : _signal);
}

//----------------------------------------------------------------------//

inline Signal MotorRotationOnly::Get()
{
	return _mem_signal;
}

//----------------------------------------------------------------------//

/************************************************************************/
