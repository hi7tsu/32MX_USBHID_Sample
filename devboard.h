
#ifndef DEVKIT_H
#define	DEVKIT_H

void __delay_us(uint32_t  d);
void __delay_ms(uint32_t  d);
void DevBoard_Init();
void LED_On();
void LED_Off();
void LED_Toggle();
uint8_t Button_IsPressed();

#endif	/* DEVKIT_H */