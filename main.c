#include <stdint.h>
#include "incFiles/stm32f103x6.h"
#include "motorDriver/motorDriver.h"
#include "serialUart/serialUart.h"

int main(void)
{
	/*
	Desarrollar el flujo principal del programa utilizando las librerias motorDriver y serialUart
	*/

	while(1)
	{
		existeCaracter();
		leerCaracter();
		uint8_t caractRx = USART1->DR & 0xFF;
		switch (caractRx)
		{
		case ('a'):
		avanzar(1);
			break;
		
		case ('w'):
		avanzar(2);
			break;
		
		case ('b'):
		retroceder(1);
			break;

		case ('s'):
		retroceder(2);
			break;
		
		case ('q'):
		girarDerecha();
			break;
		
		case ('e'):
		girarIzquierda();
			break;

		default:
			break;
		}
	}
}