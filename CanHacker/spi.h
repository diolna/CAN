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

	uint8_t mode;                       // ����� SPI
	bool master; // if 1 spi master;    // ��� ���������� ������ ��� �����  ���� 1 �� ������
	uint8_t speed;						// �������� ������ �������� �� �������
	bool data_order;					//������� ��� � 7 �� 0 ��� � 0 �� 7 ���� 1 � ��������
	  // ������ ��� ��������


};
