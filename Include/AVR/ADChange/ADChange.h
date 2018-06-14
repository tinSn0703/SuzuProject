
#pragma once

/************************************************************************/

typedef sint ADData;

/************************************************************************/

enum ADNum
{
	AD_NUM_0 = 0x00,
	AD_NUM_1 = 0x01,
	AD_NUM_2 = 0x02,
	AD_NUM_3 = 0x03,
	AD_NUM_4 = 0x04,
	AD_NUM_5 = 0x05,
	AD_NUM_6 = 0x06,
	AD_NUM_7 = 0x07,
	
	AD_NUM_8 = 0x08,
	AD_NUM_9 = 0x09,
	AD_NUM_A = 0x0a,
	AD_NUM_B = 0x0b,
	AD_NUM_C = 0x0c,
	AD_NUM_D = 0x0d,
	AD_NUM_E = 0x0e,
	AD_NUM_F = 0x0f,
};

/************************************************************************/

class ADChange
{
//variable
private:
	
	ADNum _mem_ad_num :4;
	
	ADData _mem_data :10;
	
//function
public:
	
	ADChange();
	ADChange(ADNum _num, YesNo _is_pullup);
	
	void Reset(ADNum _num, YesNo _is_pullup);
	
	/**
	 * @fn AD�ϊ����s���A�f�[�^���擾����
	 */
	ADData Read();
	
	/**
	 * @fn AD�ϊ���̔ԍ���Ԃ�
	 */
	ADNum Get_num();
	
	/**
	 * @fn AD�ϊ����s���Ď擾�����f�[�^��Ԃ��B�͈� : 0~1031
	 */
	ADData Get_data();
	
	/**
	 * @fn AD�ϊ����s���Ď擾�����f�[�^��[deg]�ŕԂ��B�͈� : 0~360
	 */
	double Get_deg();
	
	/**
	 * @fn AD�ϊ����s���Ď擾�����f�[�^��[rad]�ŕԂ��B�͈� : 0~2��
	 */
	double Get_rad();
};

/************************************************************************/

//----------------------------------------------------------------------//

inline ADNum ADChange :: Get_num()
{
	return _mem_ad_num;
}

//----------------------------------------------------------------------//

inline ADData ADChange ::Get_data()
{
	return _mem_data;
}

//----------------------------------------------------------------------//

/************************************************************************/
