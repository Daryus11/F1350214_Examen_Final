#include "motorDriver.h"

void iniciarModulo(void)
{
    RCC->APB2ENR |= (1<<2)|(1<<3)|(1<<4)|(1<<0);
    RCC->APB1ENR |= (1<<1);
    //Configuración de puertos PA4 PA5 PA6 PA7
    GPIOA->CRL &= ~(0xFFFF<<16);
    GPIOA->CRL |= (1<<17)|(1<<21)|(1<<25)|(1<<29);
    GPIOA->ODR &= ~(0xF0<<0);
    //Configuración de puerto PC13
    GPIOC->CRH &= ~(1<<21);
    GPIOC->CRH |= (1<<21);
    GPIOC->ODR &= ~(0<<13);
    //Configuración de puerto PB8 PB9 PWM
    GPIOB->CRH &= ~(0xFF<<0);
    GPIOB->CRH |= (0xA<<0)|(0xA<<4);
    //Configuración del TIMER PWMA PB8
    TIM3->CCMR2 |= ((0x68<<8)|(0x68<<0));
	TIM3->BDTR |= (1<<15);
	TIM3->CCER |= (1<<12)|(1<<8);
	    
    TIM3->PSC = 7;
    TIM3->ARR = 40000; //pwm al 0 %
	TIM3->CCR4 = 0;
    TIM3->CCR3 = 0;
	
}

void avanzar(uint8_t vel)
{
    GPIOA->ODR &= ~(0xFF);
    GPIOA->ODR |= (0x60<<0);
    if (vel = 1)
    {
        //Motor A Y B pwm 50%
        TIM3->CCR3 = 20000; 
        TIM3->CCR4 = 20000;      
    }
    if (vel = 2)
    {
        //Motor A Y B pwm 100%
        TIM3->CCR3 = 40000; 
        TIM3->CCR4 = 40000;      
    }
    delay(1000);
    TIM3->CCR3 = 0; 
    TIM3->CCR4 = 0;
}

void retroceder(uint8_t vel)
{
    GPIOA->ODR &= ~(0xFF);
    GPIOA->ODR |= (0x90<<0);
    if (vel = 1)
    {
        //Motor A Y B pwm 50%
        TIM3->CCR3 = 20000; 
        TIM3->CCR4 = 20000;      
    }
    if (vel = 2)
    {
        //Motor A Y B pwm 100%
        TIM3->CCR3 = 40000; 
        TIM3->CCR4 = 40000;      
    }
    delay(1000);
    TIM3->CCR3 = 0; 
    TIM3->CCR4 = 0;
}

void girarDerecha()
{
    GPIOA->ODR &= ~(0xFF);
    GPIOA->ODR |= (0x50<<0);
    //Motor A Y B pwm 50%
    TIM3->CCR3 = 20000; 
    TIM3->CCR4 = 20000;      
    delay(1000);
    TIM3->CCR3 = 0; 
    TIM3->CCR4 = 0;
}

void girarIzquierda()
{
    GPIOA->ODR &= ~(0xFF);
    GPIOA->ODR |= (0xA0<<0);
    //Motor A Y B pwm 50%
    TIM3->CCR3 = 20000; 
    TIM3->CCR4 = 20000;      
    delay(1000);
    TIM3->CCR3 = 0; 
    TIM3->CCR4 = 0;
}

/*
Implementar el codigo fuente de las fuciones
iniciarModulo(),
avanzar(),
retroceder(),
girarDerecha(),
girarIzquierda()

*/