#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include <math.h>
#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  



void main(void) 
{
	unsigned int count=0;
    LEDarray_init();
    int number = 0;
    
    while(1){
        while (count < 10){
            count++; // increment count
            number = pow(2,count);
            LEDarray_disp_bin(number); //output a on the LED array in binary
            __delay_ms(50); // Delay so human eye can see change
        }
        while (count != 0) {
            count--; // increment count
            number = pow(2,count);
            LEDarray_disp_bin(number); //output a on the LED array in binary
            __delay_ms(50); // Delay so human eye can see change
        }
    }
}

