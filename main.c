#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include <math.h>
#include "ADC.h"
#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  



void main(void) 
{
    LEDarray_init();
    ADC_init();
    int cal_max = ADC_getval();
    int cur_max = 0;
    int temp_max = 0;
    unsigned int count = 0;
    
    while(1){
        cur_max = ADC_getval();
        count ++;
        if (count > 20){
            count = 0;
            temp_max = temp_max - cal_max/9;
        }
        if (cur_max > temp_max){
            temp_max = cur_max;
        }
        LEDarray_disp_PPM(cur_max,temp_max,cal_max);
        __delay_ms(50);
    }
}

