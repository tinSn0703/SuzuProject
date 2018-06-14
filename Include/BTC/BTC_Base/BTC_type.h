
#pragma once

/************************************************************************/

typedef char BluetoothAdrs;

/************************************************************************/

//----------------------------------------------------------------------//

enum BluetoothNum
{
	
#if		BLUETOOTH == BLUEMASTER
	
	BLUEMASTER_01 = 0xfe,
	BLUEMASTER_02 = 0x01,
	BLUEMASTER_03 = 0xfd,
	BLUEMASTER_04 = 0x02,
	BLUEMASTER_05 = 0xfb,
	BLUEMASTER_06 = 0x04,
	BLUEMASTER_07 = 0xf7,
	BLUEMASTER_08 = 0x08,
	BLUEMASTER_09 = 0xef,
	BLUEMASTER_10 = 0x10,
	BLUEMASTER_11 = 0xdf,
	BLUEMASTER_12 = 0x20,
	BLUEMASTER_13 = 0xbf,
	BLUEMASTER_14 = 0x40,
	BLUEMASTER_15 = 0x7f,
	BLUEMASTER_16 = 0x80,
	
#elif	BLUETOOTH == ROBOBA005
	
	ROBOBA005_00 = 0x01,
	ROBOBA005_01 = 0xfe,
	ROBOBA005_02 = 0x02,
	ROBOBA005_03 = 0xfd,
	ROBOBA005_04 = 0x04,
	ROBOBA005_05 = 0xfb,
	ROBOBA005_06 = 0x08,
	ROBOBA005_07 = 0xf7,
	ROBOBA005_08 = 0x10,
	ROBOBA005_09 = 0x2f,
	ROBOBA005_10 = 0x20,
	ROBOBA005_11 = 0xdf,
	ROBOBA005_12 = 0x40,
	ROBOBA005_13 = 0xbf,
	ROBOBA005_14 = 0x80,
	ROBOBA005_15 = 0x7f,
	
#endif
	
	
};

//----------------------------------------------------------------------//

/************************************************************************/
