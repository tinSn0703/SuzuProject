
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
	
	/* ������ */
	void Initialize();
	
	/* �G���R�[�_��H�̃f�[�^��ǂ� */
	void Read();
	
	/* ������܂�����? */
	YesNo Is_round();
	
	/* �G���R�[�_�̌��ݒl��Ԃ��B0~1023 */
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
