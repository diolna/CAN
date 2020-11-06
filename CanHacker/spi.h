#pragma once
#include <avr/io.h>



class SPI {
public:




	SPI(uint8_t type, bool mode, uint8_t dev_speed, bool d_order);
	unsigned char transfer(unsigned char d);
	unsigned char receive();
	void begin();
	void end();



private:

	uint8_t mode;                       // режим SPI
	bool master; // if 1 spi master;    // тип устройтсва мастер или слейв  если 1 то мастер
	uint8_t speed;						// скорость вернее делитель от частоты
	bool data_order;					//порядок бит с 7 по 0 или с 0 по 7 если 1 с седьмого
	  // данные для передачи


};
