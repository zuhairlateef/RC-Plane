#define SYSDIV2 4//Frequency is 400MHz/(SYSDIV2+1) = 400MHz/(4+1) = 80 MHz

//Configure the system to get its clock from the PLL
void PLL_Init(void);