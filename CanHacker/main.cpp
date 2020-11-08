#include <avr/io.h>
#include <util/delay.h>
#include "atmega8.h"
#include <avr/interrupt.h>
#include "spi.h"
#include "mcp2515.h"




int main() {
	setup_spi(SPI_MODE_0, SPI_LSB, SPI_NO_INTERRUPT, SPI_MSTR_CLK128);

	uint8_t data[255];
	data[0] = 0;
	for(uint8_t i = 0; i < 255; i++){
		data[i]= i;
 	}


	mcp2515_loadMSG(mcp_tx_txb1, data, 255);



while(1){
setup_spi(SPI_MODE_0, SPI_LSB, SPI_NO_INTERRUPT, SPI_MSTR_CLK128);
send_spi(0b0);
send_spi(0b1);


}




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
