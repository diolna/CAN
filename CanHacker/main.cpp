#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"
#include "atmega8.h"


int main() {
	DDRD = 0b00000011111;

//	SPI spi(0, 1, 0, 0);
//	spi.begin();
//
//	atmega8 atmega_8(spi);
//	int a= 10;
//	while(a > 0){
//
//	atmega_8.TransferSPI('a');
//	_delay_ms(500);
//	a--;
//	atmega_8.TransferSPI('d');
//	_delay_ms(500);
//	}




	while(1){

//	PORTD = 0b00000000111;
	PORTD |=(1<<PD0);
	_delay_ms(500);

//	PORTD = 0b000000000000;
	PORTD &=~(1<<PD0);
	_delay_ms(500);

	}
	return 0;
}
