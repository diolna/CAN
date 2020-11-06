#include "atmega8.h"

unsigned char atmega8::TransferSPI(unsigned char d){

	return spi.transfer(d);
}
