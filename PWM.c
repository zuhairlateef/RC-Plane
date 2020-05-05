#include <stdint.h>
#include "tm4c123gh6pm.h"

#define PWM_0_GENA_ACTCMPAD_ONE 0x000000C0//Set the output signal to 1
#define PWM_0_GENA_ACTLOAD_ZERO 0x00000008//Set the output signal to 0
#define PWM_0_GENB_ACTCMPBD_ONE 0x00000C00//Set the output signal to 1
#define PWM_0_GENB_ACTLOAD_ZERO 0x00000008//Set the output signal to 0

#define SYSCTL_RCC_USEPWMDIV    0x00100000//Enable PWM Clock Divisor
#define SYSCTL_RCC_PWMDIV_M     0x000E0000//PWM Unit Clock Divisor
#define SYSCTL_RCC_PWMDIV_2     0x00000000//Divide clock speed by 2

//Start PWM Generator A
void PWM0A_Init(int period, int duty){
  SYSCTL_RCGCPWM_R |= 0x01;//Activate PWM0
  SYSCTL_RCGCGPIO_R |= 0x02;//Enable clock on Port B
  while((SYSCTL_PRGPIO_R&0x02) == 0){};//Wait for clock to start
  GPIO_PORTB_AFSEL_R |= 0x40;//enable alternate funct on PB6
  GPIO_PORTB_PCTL_R &= ~0x0F000000;//configure PB6 as PWM0
  GPIO_PORTB_PCTL_R |= 0x04000000;
  GPIO_PORTB_AMSEL_R &= ~0x40;//Disable analog functionality on PB6
  GPIO_PORTB_DEN_R |= 0x40;//Enable digital I/O on PB6
  SYSCTL_RCC_R = 0x00100000 |//Use PWM divider
      (SYSCTL_RCC_R & (~0x000E0000));//Configure for /2 divider
  PWM0_0_CTL_R = 0;//Set to periodic count down mode
  PWM0_0_GENA_R = 0xC8;// low on LOAD, high on CMPA down
  //PB6 goes low on LOAD
  //PB6 goes high on CMPA down
  PWM0_0_LOAD_R = period - 1;//Cycles needed to count down to 0
  PWM0_0_CMPA_R = duty - 1;//Count value at rising edge
  PWM0_0_CTL_R |= 0x00000001;//Start PWM0
  PWM0_ENABLE_R |= 0x00000001;//Enable PWM to PB6
}

//Change duty cycle of PB6
void PWM0A_Duty(int duty){
  PWM0_0_CMPA_R = duty - 1;//Count value at rising edge
}

//Start PWM Generator B
void PWM0B_Init(int period, int duty){
  volatile unsigned long delay;
  SYSCTL_RCGCPWM_R |= 0x01;//Activate PWM0
  SYSCTL_RCGCGPIO_R |= 0x02;//Enable clock to Port B
  delay = SYSCTL_RCGCGPIO_R;//Wait for clock to start
  GPIO_PORTB_AFSEL_R |= 0x80;//Enable alternate functions to PB7
  GPIO_PORTB_PCTL_R &= ~0xF0000000;//Configure PB7 as M0PWM1
  GPIO_PORTB_PCTL_R |= 0x40000000;
  GPIO_PORTB_AMSEL_R &= ~0x80;//Disable analog functionality on PB7
  GPIO_PORTB_DEN_R |= 0x80;//Enable digital I/O on PB7
  SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;//Use PWM divider
  SYSCTL_RCC_R &= ~SYSCTL_RCC_PWMDIV_M;//Clear PWM divider field
  SYSCTL_RCC_R += SYSCTL_RCC_PWMDIV_2;//Configure for /2 divider
  PWM0_0_CTL_R = 0;//Set to periodic count down mode
  PWM0_0_GENB_R = (PWM_0_GENB_ACTCMPBD_ONE|PWM_0_GENB_ACTLOAD_ZERO);
  //PB7 goes low on LOAD
  //PB7 goes high on CMPB down
  PWM0_0_LOAD_R = period - 1;//Cycles needed to count down to 0
  PWM0_0_CMPB_R = duty - 1;//Count value when output rises
  PWM0_0_CTL_R |= 0x00000001;//Start PWM0
  PWM0_ENABLE_R |= 0x00000002;//Enable PB7/M0PWM1
}
//Change duty cycle of PB7
void PWM0B_Duty(int duty){
  PWM0_0_CMPB_R = duty - 1;//Count value when output rises
}

