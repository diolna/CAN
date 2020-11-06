#pragma once
#include "spi.h"

class atmega8 {
public:

	unsigned char TransferSPI(unsigned char d);

atmega8(SPI s) : spi(s) {}

private:
	SPI spi;


};
