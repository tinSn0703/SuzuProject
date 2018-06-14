
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
	
	/* �g��IO���W�X�^���Đݒ肷�� */
	void Reset(IoNum _io_adrs);
	
	/* �o�͂��� */
	void Write(IoData _out_data);
	
	/* �o�͂��� */
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
	
	/* �g��IO���W�X�^���Đݒ肷�� */
	void Reset(IoNum _io_adrs);
	
	/* ���͂�ǂݎ�� */
	IoData Read();
	
	/* ���͂�ǂݎ�� */
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
	 * @fn IO�s�����Đݒ肷��
	 * @param _io_adrs	���W�X�^�̍Đݒ��
	 * @param _bit		�r�b�g�̍Đݒ��
	 */
	void Reset(IoNum _io_adrs, IoBit _bit);
	
	/**
	 * @fn �o�͂���
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
	 * @fn IO�s���𔽓]�����ēǂݎ��@�\�̐ݒ�
	 * @param _yes_no �g�� / �g��Ȃ�
	 */
	void Want_to_read_reverse(YesNo _yes_no);
	
	/** 
	 * @fn IO�s�����Đݒ肷��
	 * @param _io_adrs	���W�X�^�̍Đݒ��
	 * @param _bit		�r�b�g�̍Đݒ��
	 */
	void Reset(IoNum _io_adrs, IoBit _bit);
	
	/**
	 * @fn IO�s���̏�Ԃ�ǂݎ��
	 */
	HighLow Read();
	
	/**
	 * @fn �O��ǂ�IO�s���̏�Ԃ�Ԃ�
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
