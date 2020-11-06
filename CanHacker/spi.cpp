#include <avr/io.h>
#include "spi.h"


SPI::SPI(uint8_t mo, bool ma, uint8_t dev_speed, bool d_order ){

	SPCR = 0x52;
	SPSR = 0x00;

	if(d_order == true )
		SPCR |= (1<DORD);
		SPCR &= ~ (1< DORD);

	data_order = d_order;
	if(bit_is_clear(SPSR, SPI2X)) speed = dev_speed;
		speed /=dev_speed;
	speed = dev_speed;
	switch (dev_speed){
	case 4: {
		SPCR |=(1 << SPR1);
		SPCR |=(1 << SPR0);
		break;

	}
	case 16: {
		SPCR |=(1 <<SPR1);
		SPCR &=~(1<<SPR0);
		break;
	}
	case 64: {
		SPCR &=~(1<<SPR1);
		SPCR |= (1 << SPR0);
		break;
	}
	case 128: {
		SPCR &= ~ ((1 << SPR1)|(1 <<SPR0));
		break;

	}
	default:
		SPCR |=(1 << SPR1);
		SPCR |=(1 << SPR0);
	}
	mode = mo;
	switch (mode) {
	case 0 :
	{
		SPCR |= (1 << CPOL);
		SPCR |= (1 << CPHA);
		break;
	}
	case 1:
	{
		SPCR |= (1 << CPOL);
		SPCR &= ~(1 << CPHA);
		break;
	}
	case 2:
	{
		SPCR &= ~(1 << CPOL);
		SPCR |= (1 << CPHA);
		break;
	}
	case 3:
	{
		SPCR &= ~(1 << CPOL);
		SPCR &= ~(1 << CPHA);
		break;
	}
	default :
		SPCR |= (1 << CPOL);
		SPCR |= (1 << CPHA);
	}

	if(ma == true) {
		SPCR |= (1 << MSTR);
	}
	else{
			SPCR &= ~(1 << MSTR);
	}
			master = ma;


}

unsigned char  SPI::transfer(unsigned char d){
	unsigned char ret;
	  PORTB &=~(1 << PB2) ;       //сбрасываем SS в 0
	  SPDR = d;   	  //передаваемые данные


//	 loop_until_bit_is_clear(SPSR, SPIF);							//дем окончани€ передачи
	  while(!(SPSR & (1<<SPIF)));
	  PORTD |= (1 << PD4);
	  ret= SPDR;                     //считываем прин€тые данные
	  PORTB |= (1 << PB2); 	  //выставл€ем SS в 1
//	  PORTD &= ~(1 <PD4);
	  return ret;
}

unsigned char receive(){
	unsigned char data;
	SPDR = 0xFF;
	while(!(SPSR & (1 << SPIF)));  // флаг завершени€ передачи приема устанавливаетс€ после  завершени€
	// передачи приема и вызывает прерывание как у ведущего так и у ведомого. ¬ вызванном прерывании
	// можно считывать и записывать новые данные дл€ приема передачи . —брас≥ваенс€ автоматичеси при входе
	// в программу обработки прерываний
	data = SPDR;
	return data;
}

void SPI::begin() {
	SPCR |= (1 <<SPE);
	PORTB |= ((1 << PB3)|(1 << PB5) |(1 << PB2));
	PORTB &= ~(1 <<PB4);
}
