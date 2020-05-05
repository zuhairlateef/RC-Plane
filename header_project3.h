#include <stdbool.h>

#ifndef __LAB3_H__
#define __LAB3_H__

#define RCGC_GPIO (*((volatile uint32_t *)0x400FE608))//address for the GPIO Run Mode Clock Gating
#define RCGCGPIO (*((volatile uint32_t *)0x400FE108))//address for the GPIO Run Mode Clock Gating
#define RCGC_UART (*((volatile uint32_t *)0x400FE618))//Offset 0x618 

#define RCGC_R5 0x20//name is R5 for the GPIO Port F 0b10 0000
#define GPIO_DIR_F (*((volatile uint32_t *)0x40025400))//direction define for the port F APB
#define GPIO_DEN_F (*((volatile uint32_t *)0x4002551C))//offset 0x51C base 0x40025400
#define GPIO_DATA_F (*((volatile uint32_t *)0x400253FC)) //offset 0x000 base same, but based on the data sheet data bus[2:9]3FC must be set!!!! important
#define GPIO_IM_F (*((volatile uint32_t *)0x40025410))//offset 0x0410 base 0x40025400 Interrupt Mask
#define GPIO_ICR_F (*((volatile uint32_t *)0x4002541C))//offset 0x041C base 0x40025400 Interrupt Clear
//------------------port A
#define GPIO_DATA_A (*((volatile uint32_t *)0x400043FC)) //offset 0x000 base 0x4000.4000,based on the data sheet data bus[2:9]3FC must be set
#define RCGC_R0 0x01//name is R1 for the GPIO Port F 0b00 0001
#define GPIO_PCTL_A (*((volatile uint32_t *)0x4000452C)) //port control offset 0x52C base 0x4000.4000 0 as normal GPIO需要用哪个就得写哪个
#define GPIO_AFSEL_A (*((volatile uint32_t *)0x40004420))//Alternate Function Select GPIOAFSEL, offset 0x420 base 0x4000.4000
#define GPIO_AMSEL_A (*((volatile uint32_t *)0x40004528))//Anolog Mode select GPIOAMSEL, offset 0x528 base 0x4000.4000 if write select analog mode
#define GPIO_DIR_A (*((volatile uint32_t *)0x40004400))//direction define for the port A APB offset 400
#define GPIO_DEN_A (*((volatile uint32_t *)0x4000451C))//offset 0x51C base 0x40004000
#define GPIO_ICR_A (*((volatile uint32_t *)0x4000441C))//offset 0x041C base 0x40004000 Interrupt Clear
#define GPIO_IM_A (*((volatile uint32_t *)0x40004410))//offset 0x0410 base 0x40004000 Interrupt Mask
#define GPIO_IS_A (*((volatile uint32_t *)0x40004404))//offset 0x0404 base 0x40004000 Interrupt Sense
#define GPIO_IBE_A (*((volatile uint32_t *)0x40004408))//offset 0x0408 base 0x40004000 Interrupt Both edge
#define GPIO_IEV_A (*((volatile uint32_t *)0x4000440C))//offset 0x040C base 0x40004000 Interrupt Event control edge or high level
#define GPIO_LOCK_A (*((volatile uint32_t *)0x40004520))
#define GPIO_CR_A (*((volatile uint32_t *)0x40004524))

//------------------port B base 0x40005000
#define GPIO_DATA_B (*((volatile uint32_t *)0x400053FC)) //offset 0x000 base 0x4000.4000,based on the data sheet data bus[2:9]3FC must be set
#define RCGC_R1 0x02//name is R5 for the GPIO Port F 0b00 0010
#define GPIO_PCTL_B (*((volatile uint32_t *)0x4000552C)) //port control offset 0x52C base 0x4000.4000 0 as normal GPIO需要用哪个就得写哪个
#define GPIO_AFSEL_B (*((volatile uint32_t *)0x40005420))//Alternate Function Select GPIOAFSEL, offset 0x420 base 0x4000.4000
#define GPIO_AMSEL_B (*((volatile uint32_t *)0x40005528))//Anolog Mode select GPIOAMSEL, offset 0x528 base 0x4000.4000 if write select analog mode
#define GPIO_DIR_B (*((volatile uint32_t *)0x40005400))//direction define for the port A APB offset 400
#define GPIO_DEN_B (*((volatile uint32_t *)0x4000551C))//offset 0x51C base 0x40004000
#define GPIO_ICR_B (*((volatile uint32_t *)0x4000541C))//offset 0x041C base 0x40004000 Interrupt Clear
#define GPIO_IM_B (*((volatile uint32_t *)0x40005410))//offset 0x0410 base 0x40004000 Interrupt Mask
#define GPIO_IS_B (*((volatile uint32_t *)0x40005404))//offset 0x0404 base 0x40004000 Interrupt Sense
#define GPIO_IBE_B (*((volatile uint32_t *)0x40005408))//offset 0x0408 base 0x40004000 Interrupt Both edge
#define GPIO_IEV_B (*((volatile uint32_t *)0x4000540C))//offset 0x040C base 0x40004000 Interrupt Event control edge or high level
//------------------switches
#define GPIO_PUR_F (*((volatile uint32_t *)0x40025510))//offset 0x510 base 0x40025400
#define GPIO_CR_F (*((volatile uint32_t *)0x40025524))//offset 0x5524 base 0x40025400
#define GPIO_LOCK_F (*((volatile uint32_t *)0x40025520))//offset 0x5524 base 0x40025400

#define UNLOCK 0x4C4F434B
//------------

#define RED 0x2 //PF1 0b10
#define BLUE 0x4 //PF2 0b100
#define GREEN 0x8//PF3 0b1000
#define OFF 0 //data = 0ff 

//sum

#define CYAN 0xC
#define MAGENTA 0x6
#define YELLOW  0xA
#define WHITE   0xE

#define ALL 0xE //enable all three Read the other two



void LED_R_on(void);
void LED_Y_on(void);
void LED_G_on(void);
void LED_off(void);//external

void onBoard_LED_Button_init(void);

bool sw1_PF4_onboard(void);
bool sw2_PF1_onboard(void);

void delayInt(int a);
//=============lab2part====================


#define RCGC_TIMER (*((volatile uint32_t *)0x400FE604))//offset 0x604 base 0x400F.E000 

//--------------base 0x4003.0000 for timer 0

#define GPTM_CTL (*((volatile uint32_t *)0x4003000C))//offset 0x00C base 0x4003.0000 
#define GPTM_CFG (*((volatile uint32_t *)0x40030000))//offset 0x000
#define GPTM_TAMR (*((volatile uint32_t *)0x40030004))//offset 0x004 timer A mode 
#define GPTM_TAILR (*((volatile uint32_t *)0x40030028))//offset 0x028 timer A interval load 
#define GPTM_IMR (*((volatile uint32_t *)0x40030018))//offset 0x018 Interrupt Mask
#define GPTM_RIS (*((volatile uint32_t *)0x4003001C))//offset 0x01C Raw Interrupt Status //TATORS is bit 0
#define GPTM_ICR (*((volatile uint32_t *)0x40030024))//offset 0x024 Raw Interrupt Clear

//----------------------
#define NVIC_EN0_R              (*((volatile uint32_t *)0xE000E100))
//========================================
//----------------lab3-------------------

#define RCGC_ADC (*((volatile uint32_t *)0x400FE638))//offset 0x638 Base 0x400F.E000 bit 0 module 0 bit 1 module 1
#define RCC (*((volatile uint32_t *)0x400FE060))//offset 0x060 Base 0x400F.E000 reset 0x078E.3AD1 run-mode clock configuration
#define RCC2 (*((volatile uint32_t *)0x400FE070))//offset 0x070 Base 0x400F.E000 reset 0x07C0.6810 Run-Mode Clock configuration
#define RIS (*((volatile uint32_t *)0x400FE050))//offset 0x050 Base 0x400F.E000 Raw Interrupt Status
#define IMC (*((volatile uint32_t *)0x400FE054))//offset 0x054 Base 0x400F.E000 Interupt Mask Control
#define MISC (*((volatile uint32_t *)0x400FE058))//offset 0x058 Base 0x400F.E000 Masked Interrupt Status and Clear
//----------------------for ADC module 0
#define ADC_ACTSS (*((volatile uint32_t *)0x40038000))//offset 0x000 Base 0x4003.8000 Active Sample Sequencer 0disable 1 enable
#define ADC_EMUX (*((volatile uint32_t *)0x40038014))//offset 0x014 Base 0x4003.8000 Event Multiplexer Select
#define ADC_SSMUX3 (*((volatile uint32_t *)0x400380A0))//offset 0x0A0 Base 0x4003.8000 Sample Sequence Input Multiplexer
#define ADC_SSCTL3 (*((volatile uint32_t *)0x400380A4))//offset 0x0A4 Base 0x4003.8000 Sample Sequence Control
#define ADC_PSSI (*((volatile uint32_t *)0x40038028))//offset 0x028 Base 0x4003.8000 Processor Sample Sequence Initiate
#define ADC_RIS (*((volatile uint32_t *)0x40038004))//offset 0x004 Base 0x4003.8000 Raw Interrupt status
#define ADC_ISC (*((volatile uint32_t *)0x4003800C))//offset 0x00C Base 0x4003.8000  Interrupt Status and Clear
#define ADC_SSFIFO3 (*((volatile uint32_t *)0x400380A8))//offset 0x0A8 Base 0x4003.8000 ADC Sample Sequence Result FIFO3
#define ADC_IM (*((volatile uint32_t *)0x40038008))//offset 0x008 Base 0x4003.8000 ADC Interrupt Mask


//----------------------for ADC module 1 Base 0x4003.9000-----
#define ADC1_ACTSS (*((volatile uint32_t *)0x40039000))//offset 0x000 Base 0x4003.8000 Active Sample Sequencer 0disable 1 enable
#define ADC1_EMUX (*((volatile uint32_t *)0x40039014))//offset 0x014 Base 0x4003.8000 Event Multiplexer Select
#define ADC1_SSMUX3 (*((volatile uint32_t *)0x400390A0))//offset 0x0A0 Base 0x4003.8000 Sample Sequence Input Multiplexer
#define ADC1_SSCTL3 (*((volatile uint32_t *)0x400390A4))//offset 0x0A4 Base 0x4003.8000 Sample Sequence Control
#define ADC1_PSSI (*((volatile uint32_t *)0x40039028))//offset 0x028 Base 0x4003.8000 Processor Sample Sequence Initiate
#define ADC1_RIS (*((volatile uint32_t *)0x40039004))//offset 0x004 Base 0x4003.8000 Raw Interrupt status
#define ADC1_ISC (*((volatile uint32_t *)0x4003900C))//offset 0x00C Base 0x4003.8000  Interrupt Status and Clear
#define ADC1_SSFIFO3 (*((volatile uint32_t *)0x400390A8))//offset 0x0A8 Base 0x4003.8000 ADC Sample Sequence Result FIFO3
#define ADC1_IM (*((volatile uint32_t *)0x40039008))//offset 0x008 Base 0x4003.8000 ADC Interrupt Mask

//---------------------------------------------------------
//===============UART 0 base 0x4000.C000============
#define UART0_CTL (*((volatile uint32_t *)0x4000C030))//offset 0x030 Base 4000.C000 reset 0x300
#define UART0_LCRH (*((volatile uint32_t *)0x4000C02C))//offset 0x02C Base 4000.C000 line control 
#define UART0_IBRD (*((volatile uint32_t *)0x4000C024))//offset 0x024 Base 4000.C000
#define UART0_FBRD (*((volatile uint32_t *)0x4000C028))//offset 0x028 Base 4000.C000
#define UART0_CC (*((volatile uint32_t *)0x4000CFC8))//offset 0xFC8 Base 4000.C000 Clock source
#define UART0_FLAG (*((volatile uint32_t *)0x4000C018))//offset 0x018 FLAG
#define UART0_DATA (*((volatile uint32_t *)0x4000C000))//offset 0x000 dataRegister

//===============UART 1 base 0x4000.D000============

#define UART1_CTL (*((volatile uint32_t *)0x4000D030))//offset 0x030 Base 4000.C000 reset 0x300
#define UART1_LCRH (*((volatile uint32_t *)0x4000D02C))//offset 0x02C Base 4000.C000 line control 
#define UART1_IBRD (*((volatile uint32_t *)0x4000D024))//offset 0x024 Base 4000.C000
#define UART1_FBRD (*((volatile uint32_t *)0x4000D028))//offset 0x028 Base 4000.C000
#define UART1_CC (*((volatile uint32_t *)0x4000DFC8))//offset 0xFC8 Base 4000.C000 Clock source
#define UART1_FLAG (*((volatile uint32_t *)0x4000D018))//offset 0x018 FLAG
#define UART1_DATA (*((volatile uint32_t *)0x4000D000))//offset 0x000 dataRegister


#endif //__LAB3_H__