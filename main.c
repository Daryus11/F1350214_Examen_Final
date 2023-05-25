#include <stdint.h>
#include "incFiles/stm32f103x6.h"

int main(void)
{
	/*
	Desarrollar el flujo principal del programa utilizando las librerias motorDriver y serialUart
	*********************************************************************************************
	Definimos caracteres leidos por UART
	'W' = avanzar (57)
	'S' = retroceder (53)
	'A'	= girarDerecha (41)
	'D' = girarIzquierda (44)
	*/

	while(1)
	{
		GPIOC->ODR &= ~(0xFF);
		GPIOC->ODR |= (0<<13);
		inicializarUart();
		existeCaracter();
		leerCaracter();
		iniciarModulo();

		switch (USART1->DR)
		{
		case (0x57):
		avanzar();
			break;
		
		case (0x53):
		retroceder();
			break;
		
		case (0x41):
		girarDerecha();
			break;
		
		case (0x44):
		girarIzquierda();
			break;
		
		default:
			break;
		}
	}
}