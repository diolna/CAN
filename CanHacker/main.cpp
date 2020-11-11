#include <avr/io.h>
#include <util/delay.h>
#include "atmega8.h"
#include <avr/interrupt.h>
#include "spi.h"
#include "mcp2515.h"
#include "serial.h"


ISR(USART_RXC_vect){

	if(serialHasChar(serialAvailable())){
		if(serialGet(serialAvailable()) == 'D'){
			DDRC |= (1<< PC0); // настройка  порта	pc0 на вывод данных
			PORTC |= (1 << PC0); // вывод лог 1 в порт Pc0
		}

	}
}



int main() {
	sei();

	//инициализация USART
	serialInit(serialAvailable(), BAUD(38400, F_CPU));

	 serialWriteString(serialAvailable(), "Hello from UART");
	 serialWrite(serialAvailable(), serialAvailable() + '0');
	 serialWriteString(serialAvailable(), "... :)\n");


	setup_spi(SPI_MODE_0, SPI_LSB, SPI_NO_INTERRUPT, SPI_MSTR_CLK128);
	mcp2515_setCanSpeed(mcp_can_speed_500);

	can_packet data[255];

	for(uint8_t i = 0; i < 255; i++){
		data[i].address = 0x000;
		for(uint8_t x = 0; x <7; x++){
		data[i].data[x] = x;
		}
		data[i].ide = 0;
		data[i].len = 4;
		data[i].rtr =0;
		data[i].srr = 1;
	}


//	mcp2515_loadMSG(mcp_tx_txb1, data, 255);



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
