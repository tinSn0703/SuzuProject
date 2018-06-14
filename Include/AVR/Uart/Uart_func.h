
#pragma once

/************************************************************************/

#include "UartBase/Uart_type.h"
#include "UartBase/Uart_define.h"

/************************************************************************/

namespace Uart
{

/************************************************************************/

void Initialize(UartNum _adrs);

void Initialize_details(UartNum _adrs, unsigned short int _ubrr, unsigned char _parity);

YesNo Is_initialize_finshe(UartNum _adrs);

UartData8bit Receive_8bit(UartNum _adrs);

UartData9bit Receive_9bit(UartNum _adrs);

void Transmit_8bit(UartNum _adrs, UartData8bit _data);

void Transmit_9bit(UartNum _adrs, UartData9bit _data);

void Enable_receive(UartNum _adrs);

void Enable_transmit(UartNum _adrs);

void Enable_9bit(UartNum _adrs);

void Disable_9bit(UartNum _adrs);

YesNo Is_enable_9bit(UartNum _adrs);

void Enable_isr(UartNum _adrs, UartISR _isr);

void Disable_isr(UartNum _adrs, UartISR _isr);

YesNo Is_enable_isr(UartNum _adrs, UartISR _isr);

YesNo Is_request_isr(UartNum _adrs, UartISR _isr);

void Release_isr(UartNum _adrs, UartISR _isr);

/************************************************************************/

};

/************************************************************************/

