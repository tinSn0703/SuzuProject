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
 * 読み取りか書き込みかを表す型
 */
typedef enum ReadOrWrite
{
	READ_MODE  = 0,
	WRITE_MODE = 1
}
ReadOrWrite;

//----------------------------------------------------------------------//

/**
 * IOポートを表す型
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
 * 　パラレル通信の情報を持つ型。パラレル通信のラインのピンのポート、ビット、ライン数、書き込みか読み
 * 取りかの情報を持つ。
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

#ifdef __cplusplus	//C++の時用

extern "C"	{

#endif /*__cplusplus*/

/************************************************************************/

/**
* @fn パラレル通信の初期設定を行う。
*
* @param _object		パラレル通信の型。
* @param _size			パラレル通信のライン数
* @param _read_or_write	読み込みか書き込みかを設定する
*/
Parallel * Parallel_Initialize(Parallel *_object, unsigned char _size, ReadOrWrite _read_or_write);

/**
* @fn パラレル通信のラインのピンを設定する。
*
* @param _object	パラレル通信の型
* @param _num_line	ピンを設定したいラインの番号
* @param _set_port	ラインに設定するピンのポート
* @param _set_bit	ラインに設定するピンのビット
*/
Parallel * Parallel_Set_port(Parallel *_object, unsigned char _num_line, IoPort _set_port, IoBit _set_bit);

/**
* @fn データを送信する。
*
* @param _object		パラレル通信の型
* @param _write_data	送信するデータ
*/
void Parallel_Write(Parallel *_object, unsigned long int _write_data);

/**
* @fn 1bitだけデータを送信する。
*
* @param _object		パラレル通信の型
* @param _num_line		送信したいライン
* @param _high_or_low	送信するデータ, HかLか
*/
void Parallel_Write_bit(Parallel *_object, unsigned char _num_line, BitHighLow _high_or_low);

/**
* @fn データを受信する。
*
* @param _object	パラレル通信の型
*/
unsigned long int Parallel_Read(Parallel *_object);

/**
* @fn 1bitだけデータを受信する。
*
* @param _object	パラレル通信の型
* @param _num_line	受信したいライン
*/
BitHighLow Parallel_Read_bit(Parallel *_object, unsigned char _num_line);

/************************************************************************/

#ifdef __cplusplus	//C++の時用

}

#endif /*__cplusplus*/

/************************************************************************/

#endif /* PARALLEL_H_ */

/************************************************************************/
