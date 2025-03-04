#ifndef TIVA_C_HELPER_H
#define TIVA_C_HELPER_H

#include <stdint.h>
#include "tm4c123gh6pm.h"

// Function Prototypes
void Delay_ms(int time_ms);
void timer0_delay(int ms);
void GPIO_Init(uint8_t port, uint8_t pin, uint8_t direction);
void GPIO_Write(uint8_t port, uint8_t pin, uint8_t value);
uint8_t GPIO_Read(uint8_t port, uint8_t pin);

void PWM_Init(uint8_t, uint8_t, uint8_t, uint8_t, uint16_t);
void PWM_SetDutyCycle(uint8_t, uint8_t, uint16_t, uint16_t);

void Timer_Init(uint8_t timer, uint32_t loadValue);
void Timer_Start(uint8_t timer);
uint32_t Timer_Read(uint8_t timer);

void ADC_Init(uint8_t channel);
uint16_t ADC_Read(uint8_t channel);

void UART_Init(uint8_t uart_module, uint32_t baud_rate);
void UART_SendChar(uint8_t uart_module, char data);
char UART_ReceiveChar(uint8_t uart_module);
void UART_SendString(uint8_t uart_module, const char *str);

// Function Definitions

// GPIO Initialization
void GPIO_Init(uint8_t port, uint8_t pin, uint8_t direction) {
    SYSCTL->RCGCGPIO |= (1 << port);

    if (port == 0){
        GPIOA->DEN |= 	(1<< pin);
        
        if (direction)
            GPIOA->DIR |=  (1<< pin);
        else
            GPIOA->DIR &= 	~(1<< pin);
    }

    else if (port == 1){
        GPIOB->DEN |= 	(1<< pin);
        
        if (direction)
            GPIOB->DIR |=  (1<< pin);
        else
            GPIOB->DIR &= 	~(1<< pin);
    }

    else if (port == 2){
        GPIOC->DEN |= 	(1<< pin);
        
        if (direction)
            GPIOC->DIR |=  (1<< pin);
        else
            GPIOC->DIR &= 	~(1<< pin);
    }

    else if (port == 3){
        GPIOD->DEN |= 	(1<< pin);
        
        if (direction)
            GPIOD->DIR |=  (1<< pin);
        else
            GPIOD->DIR &= 	~(1<< pin);
    }

    else if (port == 4){
        GPIOE->DEN |= 	(1<< pin);
        
        if (direction)
            GPIOE->DIR |=  (1<< pin);
        else
            GPIOE->DIR &= 	~(1<< pin);
    }

    else if (port == 5){
        GPIOF->DEN |= 	(1<< pin);
        
        if (direction)
            GPIOF->DIR |=  (1<< pin);
        else
            GPIOF->DIR &= 	~(1<< pin);
    }
    
}

// GPIO Write
void GPIO_Write(uint8_t port, uint8_t pin, uint8_t value) {
    if (port == 0){
        if (value)
            GPIOA->DATA |=  (1<< pin);
        else
            GPIOA->DATA &= 	~(1<< pin);
    }

    else if (port == 1){
        if (value)
            GPIOB->DATA |=  (1<< pin);
        else
            GPIOB->DATA &= 	~(1<< pin);
    }

    else if (port == 2){
        if (value)
            GPIOC->DATA |=  (1<< pin);
        else
            GPIOC->DATA &= 	~(1<< pin);
    }

    else if (port == 3){
        if (value)
            GPIOD->DATA |=  (1<< pin);
        else
            GPIOD->DATA &= 	~(1<< pin);
    }

    else if (port == 4){
        if (value)
            GPIOE->DATA |=  (1<< pin);
        else
            GPIOE->DATA &= 	~(1<< pin);
    }

    else if (port == 5){
        if (value)
            GPIOF->DATA |=  (1<< pin);
        else
            GPIOF->DATA &= 	~(1<< pin);
    }
}

// GPIO Read
uint8_t GPIO_Read(uint8_t port, uint8_t pin) {
    if (port == 0)
        return (GPIOA->DATA & (1 << pin)) ? 1 : 0;

    if (port == 1)
        return (GPIOB->DATA & (1 << pin)) ? 1 : 0;
    
    if (port == 2)
        return (GPIOC->DATA & (1 << pin)) ? 1 : 0;
    
    if (port == 3)
        return (GPIOD->DATA & (1 << pin)) ? 1 : 0;
    
    if (port == 4)
        return (GPIOE->DATA & (1 << pin)) ? 1 : 0;
    
    if (port == 5)
        return (GPIOF->DATA & (1 << pin)) ? 1 : 0;
}

// PWM Initialization
void PWM_Init(uint8_t module, uint8_t generator, uint8_t port, uint8_t pin, uint16_t loadValue) {
    
    SYSCTL->RCGCPWM |= (1<<module);
    SYSCTL->RCGCGPIO|= (1<<port);

	SYSCTL->RCC |= (1<<20);
    SYSCTL->RCC |= 0x000E0000;

    GPIOF->AFSEL |= (1<<pin);
    GPIOF->PCTL &= (1<<pin*4)|(1<<(pin*4)+1)|(1<<(pin*4)+2)|(1<<(pin*4)+3);
    GPIOF->PCTL |= (1<<(pin*4))|(1<<(pin*4)+2);
    GPIOF->DEN |= (1<<pin);
    
    if (module == 0){
        if (generator == 0){
            PWM0->_0_CTL &= ~(1<<0);
            PWM0->_0_CTL &= ~(1<<1);
            PWM0->_0_GENA = ~0x0000008C;
            PWM0->_0_LOAD = loadValue;
            PWM0->_0_CMPA = loadValue-1;
            PWM0->_0_CTL = 1;
        }

        else if (generator == 1){
            PWM0->_1_CTL &= ~(1<<0);
            PWM0->_1_CTL &= ~(1<<1);
            PWM0->_1_GENA = ~0x0000008C;
            PWM0->_1_LOAD = loadValue;
            PWM0->_1_CMPA = loadValue-1;
            PWM0->_1_CTL = 1;
        }

        else if (generator == 2){
            PWM0->_2_CTL &= ~(1<<0);
            PWM0->_2_CTL &= ~(1<<1);
            PWM0->_2_GENA = ~0x0000008C;
            PWM0->_2_LOAD = loadValue;
            PWM0->_2_CMPA = loadValue-1;
            PWM0->_2_CTL = 1;
        }

        else if (generator == 3){
            PWM0->_3_CTL &= ~(1<<0);
            PWM0->_3_CTL &= ~(1<<1);
            PWM0->_3_GENA = ~0x0000008C;
            PWM0->_3_LOAD = loadValue;
            PWM0->_3_CMPA = loadValue-1;
            PWM0->_3_CTL = 1;
        }

        PWM0->ENABLE = 0x40; 
    }
    
    else if (module == 1){
        if (generator == 0){
            PWM1->_0_CTL &= ~(1<<0);
            PWM1->_0_CTL &= ~(1<<1);
            PWM1->_0_GENA = ~0x0000008C;
            PWM1->_0_LOAD = loadValue;
            PWM1->_0_CMPA = loadValue-1;
            PWM1->_0_CTL = 1;
        }

        else if (generator == 1){
            PWM1->_1_CTL &= ~(1<<0);
            PWM1->_1_CTL &= ~(1<<1);
            PWM1->_1_GENA = ~0x0000008C;
            PWM1->_1_LOAD = loadValue;
            PWM1->_1_CMPA = loadValue-1;
            PWM1->_1_CTL = 1;
        }

        else if (generator == 2){
            PWM1->_2_CTL &= ~(1<<0);
            PWM1->_2_CTL &= ~(1<<1);
            PWM1->_2_GENA = ~0x0000008C;
            PWM1->_2_LOAD = loadValue;
            PWM1->_2_CMPA = loadValue-1;
            PWM1->_2_CTL = 1;
        }

        else if (generator == 3){
            PWM1->_3_CTL &= ~(1<<0);
            PWM1->_3_CTL &= ~(1<<1);
            PWM1->_3_GENA = ~0x0000008C;
            PWM1->_3_LOAD = loadValue;
            PWM1->_3_CMPA = loadValue-1;
            PWM1->_3_CTL = 1;
        }

        PWM1->ENABLE = 0x40; 
    }
}

// PWM Set Duty Cycle
void PWM_SetDutyCycle(uint8_t module, uint8_t generator, uint16_t dutyCycle, uint16_t setCycle) {
    uint8_t actualCycle = (setCycle * (100 - dutyCycle)) / 100;

    if (module == 0){
        if (generator == 0)
            PWM0->_0_CMPA = actualCycle;
        else if (generator == 1)
            PWM0->_1_CMPA = actualCycle;
        else if (generator == 2)
            PWM0->_2_CMPA = actualCycle;
        else if (generator == 3)
            PWM0->_3_CMPA = actualCycle;
    }
    else if (module == 1){
        if (generator == 0)
            PWM1->_0_CMPA = actualCycle;
        else if (generator == 1)
            PWM1->_1_CMPA = actualCycle;
        else if (generator == 2)
            PWM1->_2_CMPA = actualCycle;
        else if (generator == 3)
            PWM1->_3_CMPA = actualCycle;
    }
}


// UART Initialization
void UART_Init(uint8_t uart_module, uint32_t baud_rate) {
    SYSCTL_RCGCUART_R |= (1 << uart_module);
    while ((SYSCTL_PRUART_R & (1 << uart_module)) == 0);
    
    UART0_CTL_R &= ~0x01;
    UART0_IBRD_R = 16000000 / (16 * baud_rate);
    UART0_FBRD_R = ((64 * (16000000 % (16 * baud_rate))) / (16 * baud_rate));
    UART0_LCRH_R = 0x70;
    UART0_CTL_R |= 0x301;
}

// UART Send Character
void UART_SendChar(uint8_t uart_module, char data) {
    while ((UART0_FR_R & 0x20) != 0);
    UART0_DR_R = data;
}

// UART Receive Character
char UART_ReceiveChar(uint8_t uart_module) {
    while ((UART0_FR_R & 0x10) != 0);
    return (char)(UART0_DR_R & 0xFF);
}

// UART Send String
void UART_SendString(uint8_t uart_module, const char *str) {
    while (*str) {
        UART_SendChar(uart_module, *str++);
    }
}

void Delay_ms(int time_ms)
{
    int i, j;
    for(i = 0 ; i < time_ms; i++)
        for(j = 0; j < 3180; j++)
            {}  /* excute NOP for 1ms */
}


void timer0_delay(int ms) // ms is in milliseconds
{
	SYSCTL->RCGCTIMER |= (1<<0); //enable clock for Timer 0
	TIMER0->CTL |= 0x0; //disable timer 0 before initialization
	TIMER0->CFG = 0x0; //select configuration for timer 0
	TIMER0->TAMR = 0x1; //configure timer A for one shot mode
	TIMER0->TAILR = 160000*ms - 1; //timer A interval load value register
	TIMER0->ICR = 0x1; //clear status flag
	TIMER0->CTL |= 0x1; //enable timer 0 to start counting afterinitializtion
	while ((TIMER0->RIS & 0x1) == 0); //Wait for the GPTM Raw Interrupt Status flag to set
}


#endif // TIVA_C_HELPER_H
