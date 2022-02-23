#include <xc.h>
#include "devboard.h"

#define SYSCLK		48000000L		// system clock

void __delay_us(uint32_t  d) 
{
	uint32_t delayCount, startTime;       

	startTime = _CP0_GET_COUNT();     
	delayCount = d * (SYSCLK / 2 / 1000 / 1000); 
	while((_CP0_GET_COUNT() - startTime) < delayCount);  
 }

void __delay_ms(uint32_t d)
{   
	uint32_t delayCount, startTime;       

	startTime = _CP0_GET_COUNT();   
	delayCount = d * (SYSCLK / 2 / 1000);   
	while((_CP0_GET_COUNT() - startTime) < delayCount);   
}

void DevBoard_Init() {
    LATA = 0;
    TRISAbits.TRISA0 = 1;   // Button
    ANSELAbits.ANSA0 = 0;
    TRISAbits.TRISA1 = 0;   // LED
}

void LED_On() {
    LATAbits.LATA1 = 1;
}

void LED_Off() {
    LATAbits.LATA1 = 0;
}

void LED_Toggle() {
    LATAbits.LATA1 ^= 1;
}

uint8_t Button_IsPressed() {
    return PORTAbits.RA0 == 0 ? 1 : 0;
}