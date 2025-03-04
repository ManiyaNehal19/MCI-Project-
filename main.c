#include "helper.h"

uint16_t initial_cycle = 100;

void Turn_AntiClockwise(void);
void Turn_Clockwise(void);

int main(void)
{

    GPIO_Init(0, 2, 1); //Init PA2 
    GPIO_Init(0, 3, 1); //Init PA3
   
    PWM_Init(1, 3, 5, 2, 5000); //PWM(1) with Generator (3) and Pin P(F)(2)

    PWM_SetDutyCycle(1, 3, initial_cycle, 4999);

    Turn_AntiClockwise();
    while(1)
    {
        initial_cycle = initial_cycle - 1;
        if (initial_cycle <= 0) 
					initial_cycle = 100;

        PWM_SetDutyCycle(1, 3, initial_cycle, 4999);

        Delay_ms(100);
    }
}


//Spin motor in one direction by giving IN1 and IN2 signals to L298N
void Turn_Clockwise(void)
{
    GPIO_Write(0, 2, 1);
    GPIO_Write(0, 3, 0);
}

//Spin motor in other direction by giving IN1 and IN2 signals to L298N

void Turn_AntiClockwise(void)
{
    GPIO_Write(0, 2, 0);
    GPIO_Write(0, 3, 1);
}
