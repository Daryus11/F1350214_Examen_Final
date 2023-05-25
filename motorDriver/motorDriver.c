#include "motorDriver.h"

#define TIM4_BASE 0x40000800
#define TIM4_PSC (*((unsigned int*) (TIM4_BASE + 0x28)))
#define TIM4_ARR (*((unsigned int*) (TIM4_BASE + 0x2C)))
#define TIM4_CCR4 (*((unsigned int*) (TIM4_BASE + 0x40)))
#define TIM4_CCMR2 (*((unsigned int*) (TIM4_BASE + 0x1C)))
#define TIM4_BDTR (*((unsigned int*) (TIM4_BASE + 0x44)))
#define TIM4_CCER (*((unsigned int*) (TIM4_BASE + 0x20)))
#define TIM4_CR1 (*((unsigned int*) (TIM4_BASE + 0x00)))

void iniciarModulo()
{
    RCC->APB2ENR |= (1<<2)|(1<<3)|(1<<4)|(1<<0);
    RCC->APB1ENR |= (1<<1);
    //Configuración de puertos PA4 PA5 PA6 PA7
    GPIOA->CRL &= ~(0xFFFF<<16);
    GPIOA->CRL |= (1<<17)|(1<<21)|(1<<25)|(1<<29);
    //Configuración de puerto PB8 PB9 PWM
    GPIOB->CRH &= ~(0xFF<<0);
    GPIOB->CRH |= (0xA<<0)|(0xA<<4);
    //Configuración de puerto PC13
    GPIOC->CRH &= ~(1<<21);
    GPIOC->CRH |= (1<<21);
    //Configuración del TIMER PWMA PB8
    TIM3->PSC = 3;
    TIM3->ARR = 40000; //pwm al 0 %
	TIM3->CCR4 = 0;

	TIM3->CCMR2 |= (0x68<<8);
	TIM3->BDTR |= (1<<15);
	TIM3->CCER |= (1<<12);
	TIM3->CR1 |= (1<<7)|(1<<0);
    //Configuración del TIMER PWMB PB9
    TIM4_PSC = 3;
    TIM4_ARR = 40000; //pwm al 0 %
	TIM4_CCR4 = 0;

	TIM4_CCMR2 |= (0x68<<8);
	TIM4_BDTR |= (1<<15);
	TIM4_CCER |= (1<<12);
	TIM4_CR1 |= (1<<7)|(1<<0);
}

void avanzar()
{
    GPIOA->ODR &= ~(0xFF);
    GPIOA->ODR |= (0x60<<0);
    while(1)
    {
        //MotorA pwm 100%
        TIM3->PSC = 3;
        TIM3->ARR = 40000; //pwm al 100 %
	    TIM3->CCR4 = 40000; 
        //MotorB pwm 100%
        TIM4_PSC = 3;
        TIM4_ARR = 40000; //pwm al 100 %
	    TIM4_CCR4 = 40000;        
    }
}

void retroceder()
{
    GPIOA->ODR &= ~(0xFF);
    GPIOA->ODR |= (0x90<<0);
    while(1)
    {
        //MotorA pwm 100%
        TIM3->PSC = 3;
        TIM3->ARR = 40000; //pwm al 100 %
	    TIM3->CCR4 = 40000; 
        //MotorB pwm 100%
        TIM4_PSC = 3;
        TIM4_ARR = 40000; //pwm al 100 %
	    TIM4_CCR4 = 40000;          
    }
}

void girarDerecha()
{
    GPIOA->ODR &= ~(0xFF);
    GPIOA->ODR |= (1<<5);
    while(1)
    {
        //MotorA pwm 50%
        TIM3->PSC = 3;
        TIM3->ARR = 40000; //pwm al 50 %
	    TIM3->CCR4 = 20000; 
        //MotorB pwm 0%
        TIM4_PSC = 3;
        TIM4_ARR = 40000; //pwm al 0 %
	    TIM4_CCR4 = 0;          
    }
}

void girarIzquierda()
{
    GPIOA->ODR &= ~(0xFF);
    GPIOA->ODR |= (1<<6);
    while(1)
    {
        //MotorA pwm 0%
        TIM3->PSC = 3;
        TIM3->ARR = 40000; //pwm al 0 %
	    TIM3->CCR4 = 0; 
        //MotorB pwm 50%
        TIM4_PSC = 3;
        TIM4_ARR = 40000; //pwm al 50 %
	    TIM4_CCR4 = 20000;          
    }
}

/*
Implementar el codigo fuente de las fuciones
iniciarModulo(),
avanzar(),
retroceder(),
girarDerecha(),
girarIzquierda()

*/