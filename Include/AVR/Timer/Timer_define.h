
#pragma once

/************************************************************************/

//bit TCCRA
#define WGM0  0
#define WGM1  1
#define COMC0 2
#define COMC1 3
#define COMB0 4
#define COMB1 5
#define COMA0 6
#define COMA1 7

//bit TCCRB
#define CS0  0
#define CS1  1
#define CS2  2
#define WGM2 3
#define WGM3 4
#define ICES 6
#define ICNC 7

//bit TCRRC
#define FOCC 5
#define FOCB 6
#define FOCA 7

//bit TIMSK
#define TOIE  0
#define OCIEA 1
#define OCIEB 2
#define OCIEC 3
#define ICIE  4

//bit TIFR
#define TOV  0
#define OCFA 1
#define OCFB 2
#define OCFC 3
#define ICF  5

/************************************************************************/

#define TIMER_INITAL_VALUE 0xffffffffffffffff	//8byte (2^8 - 1)

/************************************************************************/
