
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
	
	/* 使っているIOレジスタを返す */
	IoNum Get_num();
	
	/* 外部変化割り込みを許可する。入力に設定されているBit全てが許可される。 */
	void Enable_isr();
	
	/* 上で設定された外部変化割り込みをすべて禁止する。 */
	void Disable_isr();
};

/************************************************************************/

};

/************************************************************************/