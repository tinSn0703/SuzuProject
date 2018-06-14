/*
* Parallel.h
*
* Created: 2018/03/20 14:19:12
*  Author: Sowa Naoki
*/

#ifndef PARALLEL_H_
#define PARALLEL_H_

/************************************************************************/

#define PARALLEL_NUM_LINE_LIMIT 20

/************************************************************************/

//----------------------------------------------------------------------//

typedef unsigned char IoBit;

//----------------------------------------------------------------------//

typedef enum BitHighLow
{
	BIT_LOW  = 0,
	BIT_HIGH = 1,
}
BitHighLow;

//----------------------------------------------------------------------//

/**
 * �ǂݎ�肩�������݂���\���^
 */
typedef enum ReadOrWrite
{
	READ_MODE  = 0,
	WRITE_MODE = 1
}
ReadOrWrite;

//----------------------------------------------------------------------//

/**
 * IO�|�[�g��\���^
 */
typedef enum IoPort
{
	NUM_A = 0,
	NUM_B = 1,
	NUM_C = 2,
	NUM_D = 3,
	NUM_E = 4,
	NUM_F = 5,
	NUM_G = 6,
	NUM_H = 7,
	NUM_J = 8,
	NUM_K = 9,
	NUM_L = 10,
}
IoPort;

//----------------------------------------------------------------------//

/************************************************************************/

/**
 * �@�p�������ʐM�̏������^�B�p�������ʐM�̃��C���̃s���̃|�[�g�A�r�b�g�A���C�����A�������݂��ǂ�
 * ��肩�̏������B
 */
typedef struct ParallelLine
{
	IoPort _port :4;
	unsigned char _bit_head :3;
	unsigned char _bit_tail :3;
	unsigned char _data_bit :8;
	unsigned char _and :8;
	unsigned char _and_r :8;
}
ParallelLine;

typedef struct Parallel
{
	ParallelLine _line[PARALLEL_NUM_LINE_LIMIT];
	
	unsigned char _is_setting_start :1;
	unsigned char _num_set_line :6;
	
	unsigned char _size :6;
	
	ReadOrWrite _read_or_write :1;
}
Parallel;

/************************************************************************/

#ifdef __cplusplus	//C++�̎��p

extern "C"	{

#endif /*__cplusplus*/

/************************************************************************/

/**
* @fn �p�������ʐM�̏����ݒ���s���B
*
* @param _object		�p�������ʐM�̌^�B
* @param _size			�p�������ʐM�̃��C����
* @param _read_or_write	�ǂݍ��݂��������݂���ݒ肷��
*/
Parallel * Parallel_Initialize(Parallel *_object, unsigned char _size, ReadOrWrite _read_or_write);

/**
* @fn �p�������ʐM�̃��C���̃s����ݒ肷��B
*
* @param _object	�p�������ʐM�̌^
* @param _num_line	�s����ݒ肵�������C���̔ԍ�
* @param _set_port	���C���ɐݒ肷��s���̃|�[�g
* @param _set_bit	���C���ɐݒ肷��s���̃r�b�g
*/
Parallel * Parallel_Set_port(Parallel *_object, unsigned char _num_line, IoPort _set_port, IoBit _set_bit);

/**
* @fn �f�[�^�𑗐M����B
*
* @param _object		�p�������ʐM�̌^
* @param _write_data	���M����f�[�^
*/
void Parallel_Write(Parallel *_object, unsigned long int _write_data);

/**
* @fn 1bit�����f�[�^�𑗐M����B
*
* @param _object		�p�������ʐM�̌^
* @param _num_line		���M���������C��
* @param _high_or_low	���M����f�[�^, H��L��
*/
void Parallel_Write_bit(Parallel *_object, unsigned char _num_line, BitHighLow _high_or_low);

/**
* @fn �f�[�^����M����B
*
* @param _object	�p�������ʐM�̌^
*/
unsigned long int Parallel_Read(Parallel *_object);

/**
* @fn 1bit�����f�[�^����M����B
*
* @param _object	�p�������ʐM�̌^
* @param _num_line	��M���������C��
*/
BitHighLow Parallel_Read_bit(Parallel *_object, unsigned char _num_line);

/************************************************************************/

#ifdef __cplusplus	//C++�̎��p

}

#endif /*__cplusplus*/

/************************************************************************/

#endif /* PARALLEL_H_ */

/************************************************************************/
