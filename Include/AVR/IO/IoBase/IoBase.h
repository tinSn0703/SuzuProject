
#pragma once

/************************************************************************/

namespace IO
{

/************************************************************************/

class Base
{
//type
private:
	
	typedef uByte (*fpReadPIN)();
	typedef uByte (*fpReadPORT)();
	typedef void (*fpWritePORT)(uByte );
	
//variable
private:
	
	IoNum _mem_io_adrs :8;
	
	fpReadPORT  _r_port;
	fpWritePORT _w_port;
	
	fpReadPIN _r_pin;
	
//function
private:
	
	void Set_DDR(IoBit _bit, BOOL _is_out_mode);
	void Set_DDR(uByte _set_in_or_out);
	
	void Set_r_pin();
	void Set_r_port();
	void Set_w_port();

public:
	
	Base();
	Base(IoNum _io_adrs, IoBit _bit, YesNo _is_out_mode);
	Base(IoNum _io_adrs, uByte _set_in_or_out);
	
	uByte PORT();
	uByte PORT(uByte _data);
	uByte PORT(IoBit _bit, BOOL _is_on);
	
	uByte PIN();
	
	void Initialize(IoNum _io_adrs, IoBit _bit, BOOL _is_out_mode);
	void Initialize(IoNum _io_adrs, uByte _set_in_or_out);
	
	/* �g���Ă���IO���W�X�^��Ԃ� */
	IoNum Get_num();
	
	/* �O���ω����荞�݂�������B���͂ɐݒ肳��Ă���Bit�S�Ă��������B */
	void Enable_isr();
	
	/* ��Őݒ肳�ꂽ�O���ω����荞�݂����ׂċ֎~����B */
	void Disable_isr();
};

/************************************************************************/

};

/************************************************************************/