
#pragma once

/************************************************************************/

typedef double  LolitaCycle;
typedef DataBit16 LolitaData;

/************************************************************************/

class Lolita
{
//variable
private:
	
	Uart::ModeReceive _mem_uart;
	
	YesNo _mem_is_make_round :1;
	
	LolitaData _mem_memory :10;
	
	LolitaData _mem_data :10;
	
//function
private:
	
	void Check_round();
	
public:
	
	Lolita(UartNum _uart_num);
	
	/* 初期化 */
	void Initialize();
	
	/* エンコーダ回路のデータを読む */
	void Read();
	
	/* 一周しましたか? */
	YesNo Is_round();
	
	/* エンコーダの現在値を返す。0~1023 */
	LolitaData Get();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline YesNo Lolita :: Is_round()
{
	return _mem_is_make_round;
}

//----------------------------------------------------------------------//

inline LolitaData Lolita :: Get()
{
	return (_mem_data);
}

//----------------------------------------------------------------------//

/************************************************************************/
