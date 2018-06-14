
#pragma once

/************************************************************************/

namespace Bluetooth
{

/************************************************************************/

void Initialize();

void Write(const char _str[]);

void Read(char _ret_str[]);

uByte Select_partner(BluetoothAdrs _bt_adrs[], const Byte _num_bt);

uByte Select_partner(BluetoothAdrs _bt_adrs[], const BluetoothNum _num_bt);

void Pair_to_slave(const BluetoothAdrs _bt_adrs[]);

void Pair_to_master(const BluetoothAdrs _bt_adrs[]);

void Connect_to_slave(const BluetoothAdrs _bt_adrs[]);

void Connect_to_master(const BluetoothAdrs _bt_adrs[]);

void Reconnect_to_slave(const BluetoothAdrs _bt_adrs[]);

void Reconnect_to_master(const BluetoothAdrs _bt_adrs[]);

void Read_bt_adrs(BluetoothAdrs _ret_bt_adrs[]);

void Set_to_command_mode();

/************************************************************************/

};

/************************************************************************/
