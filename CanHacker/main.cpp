#include <avr/io.h>
#include <util/delay.h>
#include "atmega8.h"
#include <avr/interrupt.h>
#include "spi.h"
#include "mcp2515.h"
#include "serial.h"


//ISR(USART_RXC_vect){
//
//	if(serialHasChar(serialAvailable())){
//		if(serialGet(serialAvailable()) == 'D'){
//			DDRC |= (1<< PC0); // настройка  порта	pc0 на вывод данных
//			PORTC |= (1 << PC0); // вывод лог 1 в порт Pc0
//		}
//
//	}
//}



int main() {
	sei();
	DDRD |= (1 << PD1);
	DDRD &= ~(1 << PD0);


//	UCSRB = (1<<RXEN)|(1<<TXEN);
//	    UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); //8 bit, 1 stop bit
	UCSRA =  0b0;
	UCSRB=0b00011000;
	UCSRC=0b10000110;
	//инициализация USART
	serialInit(serialAvailable(), BAUD(9600, F_CPU));
	DDRC = 0b00000000001;

		while(1){


		PORTC |=(1<<PC0);
		_delay_ms(500);


		PORTC &=~(1<<PD0);
		_delay_ms(500);
		serialWrite(serialAvailable(), 'd');
		serialWriteString(serialAvailable(), "Hello from UART");
			 serialWrite(serialAvailable(), serialAvailable() + '0');
			 serialWriteString(serialAvailable(), "... :)\n");

		}


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



//while(1){
//setup_spi(SPI_MODE_0, SPI_LSB, SPI_NO_INTERRUPT, SPI_MSTR_CLK128);
//send_spi(0b0);
//send_spi(0b1);
//
//
//}




	return 0;
}
