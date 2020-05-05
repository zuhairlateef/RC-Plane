#include <stdint.h>
#include <stdbool.h>
#include <header_project3.h>
#include <stdio.h>

void UART_Init(void);
void GPIO_Init();
void SONAR_Init();
void TransmitData(char* data);
void writeDataToRegister();
void clock_ITR_init();
void sonarTriger();
double DisConvert(double TimePassedUnitsecond);
double TimeCount(int dummyTimer);
int Timer;
double Distance;
char* data;
char dis[10];

//Configure UART0 for transmittal and recieval
void UART_Init(void){
  RCGC_UART |= 2;//enable the UART module using the RCGCUART register
  //trying to enable GPIOA PA1
  delayInt(10);
  UART1_CTL &= ~1; //disable the UART by cleaning the ****UARTEN #0 bit in UARTCTL
  RCGC_GPIO |= 2; //configure the GPIO enable
  UART1_CC = 0x5;
  UART1_IBRD = 8;
  UART1_FBRD = 44;
  UART1_LCRH |= 0x60; //write the desired serial parameters to UARTCRH suggestion 0x60
  UART1_CTL|= 0x300 ;//***TxE #8 ***RxE  #9 //both set to 1 to enable
  UART1_CTL|= 0x800 ;//enable CTSEN UICTS signal asserted
  GPIO_PCTL_B |= 0x11;
  GPIO_AFSEL_B |= 3;
  GPIO_DEN_B |= 3;//digital enable bit[0:1]
  UART1_CTL |= 1; //enable the clock ****UARTEN #0 bit =1
  delayInt(100);
}


double TimeCount(int dummyTimer){
  return dummyTimer/10000.0;
}

void TransmitData(char* data) {
  char* temp = data;
  while(*temp != '\0') {
    //If the UART is available
    while (UART1_FLAG&0x01==0);
    while ((UART1_FLAG&0x20)!=0);
    UART1_DATA = *temp;
    temp++;
  }
}


void SONAR_Init(){
  //PA3 is trigger
  //PA4 is echo
  RCGC_GPIO |= RCGC_R0; //Enable Port A GPIO
  delayInt(3);
  GPIO_AMSEL_A &= ~0x11;//Disable the analog on PA3/PA4 0b01.1000
  GPIO_PCTL_A &=~0x000FF000;
  GPIO_AFSEL_A &= ~0x11;//Regular no extra function
  GPIO_DIR_A |= 8;//Set P3 as output
  GPIO_DIR_A &=~0x10;//Set P4 as input
  GPIO_DEN_A = 0x18;//Enable P3:P4
}

//Converts distance using time passed
double DisConvert(double TimePassedUnitsecond){
  return TimePassedUnitsecond*170;//time*340(speed of sound m/s)/2
  //return unit m
}
  
 //Initialize clock and timer interrupt 
 void clock_ITR_init(){
  RCGC_TIMER |= 0x01;//set bit 0 to 1 to enable the 16/32 timer in Run Mode
  GPTM_CTL &= ~0x01;//clear the 0 bit to disable the timer A
  GPTM_CFG &= ~0x07; //set the GPTM configuration to a 16/32 timer to 32-bit timer //clear bit 2/1/0 0b.0111
  /////-----recheck if not right clear then set CFG and TAMR
  GPTM_TAMR &= ~0x03; //clear 0b.0011 TAMR bit
  GPTM_TAMR |= 0x02; //bit0:1 0x2 periodic mode  
  GPTM_TAMR &= ~0x04; //clear 0b.1000 TACDIR for counts down mode
  GPTM_TAILR = 1600; // 100us = 0.1ms  
  GPTM_IMR = 0x01;//set it to timer a Timeout mode 0b1
  NVIC_EN0_R= 0x00080000; //enabling interrupt 19 check page 142
  GPTM_CTL|=0x01;//set the 0 bit to enable the timer A
}
  
//Creats delay
void delayInt(int a){
  int count = 0;
  for (int i =0;i<a;i++)count++;
}
  
//Interrupt triggered by timer
void Timer_Handler(){
  Timer++;
  GPTM_ICR|=1;//exit the interrupt
}