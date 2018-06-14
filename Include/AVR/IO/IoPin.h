
#pragma once

#include "IoBase/IO_type.h"
#include "IoBase/IoBase.h"

/************************************************************************/

namespace IO
{

/************************************************************************/

class ModeOut : private Base
{
public:
	
	ModeOut();
	ModeOut(IoNum _io_adrs);
	
	/* 使うIOレジスタを再設定する */
	void Reset(IoNum _io_adrs);
	
	/* 出力する */
	void Write(IoData _out_data);
	
	/* 出力する */
	void Write(HighLow _high_low, IoBit _bit);
	
	IoNum Get_num();
	
	~ModeOut();
};

/************************************************************************/

class ModeIn : private Base
{
public:
	
	ModeIn();
	ModeIn(IoNum _io_adrs);
	
	/* 使うIOレジスタを再設定する */
	void Reset(IoNum _io_adrs);
	
	/* 入力を読み取る */
	IoData Read();
	
	/* 入力を読み取る */
	HighLow Read(IoBit _bit);
	
	IoNum Get_num();
	
	~ModeIn();
};

/************************************************************************/

class ModeBitOut : private Base
{
private:
	
	IoBit _bit :3;
	
public:
	
	ModeBitOut();
	ModeBitOut(IoNum _io_adrs, IoBit _bit);
	
	/** 
	 * @fn IOピンを再設定する
	 * @param _io_adrs	レジスタの再設定先
	 * @param _bit		ビットの再設定先
	 */
	void Reset(IoNum _io_adrs, IoBit _bit);
	
	/**
	 * @fn 出力する
	 */
	void Write(HighLow _high_low);
	
	IoBit Get_bit();
	
	IoNum Get_num();
	
	~ModeBitOut();
};

/************************************************************************/

class ModeBitIn : private Base
{
private:
	
	IoBit _bit :3;
	
	HighLow _read_data :1;
	
	YesNo _is_read_reverse :1;
	
public:
	
	ModeBitIn();
	ModeBitIn(IoNum _io_adrs, IoBit _bit);
	
	/**
	 * @fn IOピンを反転させて読み取る機能の設定
	 * @param _yes_no 使う / 使わない
	 */
	void Want_to_read_reverse(YesNo _yes_no);
	
	/** 
	 * @fn IOピンを再設定する
	 * @param _io_adrs	レジスタの再設定先
	 * @param _bit		ビットの再設定先
	 */
	void Reset(IoNum _io_adrs, IoBit _bit);
	
	/**
	 * @fn IOピンの状態を読み取る
	 */
	HighLow Read();
	
	/**
	 * @fn 前回読んだIOピンの状態を返す
	 */
	HighLow Get();
	
	/**
	 * @fn 
	 */
	IoBit Get_bit();
	
	IoNum Get_num();
	
	~ModeBitIn();
};

/************************************************************************/

};

/************************************************************************/
