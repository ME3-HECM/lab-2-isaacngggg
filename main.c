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
    //LDRbutton_init();
    RF2button_init();
    
    
    while(count < 511){
        //while (PORTAbits.RA3 == 0){
        while (PORTFbits.RF2);                 // whilst no button is pressed keep waiting
        if(!PORTFbits.RF2) {                     // if button is pressed 
            count ++;                           // count up
            LEDarray_disp_dec(count);           // light up the amount counted
            __delay_ms(100); 
            while (!PORTFbits.RF2){
                __delay_ms(300); 
                if(!PORTFbits.RF2) {
                    count ++;
                    LEDarray_disp_dec(count);
                }
                else{break;}
            }
           
            
        }
        
        //}
        //if(count > 127) {count=0;}
        //LEDarray_disp_bin(count); //output a on the LED array in binary
    }
}

