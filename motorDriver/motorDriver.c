#include "motorDriver.h"

void iniciarModulo()
{
    RCC->APB2ENR |= (1<<2)|(1<<3)|(1<<4);
    //Configuración de puertos PA4 PA5 PA6 PA7
    GPIOA->CRL &= ~(0xFFFF<<16);
    GPIOA->CRL |= (1<<17)|(1<<21)|(1<<25)|(1<<29);
    //Configuración de puerto PB8 PB9 PWM
    GPIOB->CRH &= ~(0xFF<<0);
    GPIOB->CRH |= (0xA<<0)|(0xA<<4);
    //Configuración de puerto PC13
    GPIOC->CRH &= ~(1<<21);
    GPIOC->CRH |= (1<<21);
    //Configuración del PWM
    TIM3->PSC = 7;
    TIM3->ARR = 20000; 
	TIM3->CCR4 = 10000;

	TIM3->CCMR2 |= (0x68<<8);
	TIM3->BDTR |= (1<<15);
	TIM3->CCER |= (1<<12);
	TIM3->CR1 |= (1<<7)|(1<<0);
    //Configuración del ADC
	ADC1->CR2 &= ~(0x1 << 0);

	ADC1->SQR1 &= ~(0xFFFFFF);

	ADC1->SQR3 &= ~(0x3FFFFFFF);
	ADC1->SQR3 |= (0x2 << 0);

	ADC1->CR1 &= ~((0xFFFFF) | (0xC << 20));
	ADC1->SMPR2 &= ~(0X7 << 6);
	ADC1->CR2 |= (1 << 0);
}

void avanzar()
{

}

void retroceder()
{

}

void girarDerecha()
{

}

void girarIzquierda()
{

}

/*
Implementar el codigo fuente de las fuciones
iniciarModulo(),
avanzar(),
retroceder(),
girarDerecha(),
girarIzquierda()

*/