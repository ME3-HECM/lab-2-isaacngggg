#include <xc.h>
#include "LEDarray.h"

/************************************
/ LEDarray_init
/ Function used to initialise pins to drive the LEDarray
************************************/
void LEDarray_init(void)
{
    //set up TRIS registers for pins connected to LED array
    TRISGbits.TRISG0 = 0;
    TRISGbits.TRISG1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISFbits.TRISF6 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;
    TRISFbits.TRISF0 = 0;
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISCbits.TRISC6 = 0;
    
	//set initial output LAT values (they may have random values when powered on)
    
    LATGbits.LATG0 = 1;
    LATGbits.LATG1 = 1;
    LATAbits.LATA2 = 1;
    LATFbits.LATF6 = 1;
    LATAbits.LATA4 = 1;
    LATAbits.LATA5 = 1;
    LATFbits.LATF0 = 1;
    LATBbits.LATB0 = 1;
    LATBbits.LATB1 = 1;
    LATCbits.LATC6 = 1;
    
}

/************************************
/ LEDarray_disp_bin
/ Function used to display a number on the LED array in binary
************************************/
void LEDarray_disp_bin(unsigned int number)
{
	//some code to turn on/off the pins connected to the LED array
    LATGbits.LATG0 = 0;
    LATGbits.LATG1 = 0;
    LATAbits.LATA2 = 0;
    LATFbits.LATF6 = 0;
    LATAbits.LATA4 = 0;
    LATAbits.LATA5 = 0;
    LATFbits.LATF0 = 0;
    LATBbits.LATB0 = 0;
    LATBbits.LATB1 = 0;
    LATCbits.LATC6 = 0;
    
	//if statements and bit masks can be used to determine if a particular pin should be on/off
    if (number & 0b00000001) {
        LATGbits.LATG0 = 1;
    }
    if (number & 0b00000010) {
        LATGbits.LATG1 = 1;
    }
    if (number & 0b00000100) {
        LATAbits.LATA2 = 1;
    }
    if (number & 0b00001000) {
        LATFbits.LATF6 = 1;
    }
    if (number & 0b00010000) {
        LATAbits.LATA4 = 1;
    }
    if (number & 0b00100000) {
        LATAbits.LATA5 = 1;
    }
    if (number & 0b01000000) {
        LATFbits.LATF0 = 1;
    }
    
	//see Readme.md for examples
}

/************************************
/ Function LEDarray_disp_dec
/ Used to display a number on the LEDs
/ where each LED is a value of 10
************************************/
void LEDarray_disp_dec(unsigned int number)
{
	unsigned int disp_val;
	
	//some code to manipulate the variable number into the correct
	//format and store in disp_val for display on the LED array

	LEDarray_disp_bin(disp_val); 	//display value on LED array
}


/************************************
/ LEDarray_disp_PPM
/ Function used to display a level on the LED array with peak hold
/ cur_val is the current level from the most recent sample, and max is the peak value for the last second
/ these input values need to calculated else where in your code
************************************/
void LEDarray_disp_PPM(unsigned int cur_val, unsigned int max)
{
	unsigned int disp_val;
	
	// some code to format the variable cur_val and max, store in disp_val for display on the LED array
	// hint: one method is to manipulate the variables separately and then combine them using the bitwise OR operator

	LEDarray_disp_bin(disp_val);	//display value on LED array
}

