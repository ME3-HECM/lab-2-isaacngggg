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
    
	//set initial output LAT values (they may have random values when powered on)
    
    LATGbits.LATG0 = 0;
    LATGbits.LATG1 = 0;
    LATAbits.LATA2 = 0;
    LATFbits.LATF6 = 0;
    LATAbits.LATA4 = 0;
    LATAbits.LATA5 = 0;
    LATFbits.LATF0 = 0;
    LATBbits.LATB0 = 0;
    LATBbits.LATB1 = 0;
    
}

void RF2button_init(void){
    TRISFbits.TRISF2=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin  
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
    
    
	//if statements and bit masks can be used to determine if a particular pin should be on/off
    if (number & 0b000000001) {
        LATGbits.LATG0 = 1;
    }
    if (number & 0b000000010) {
        LATGbits.LATG1 = 1;
    }
    if (number & 0b000000100) {
        LATAbits.LATA2 = 1;
    }
    if (number & 0b000001000) {
        LATFbits.LATF6 = 1;
    }
    if (number & 0b000010000) {
        LATAbits.LATA4 = 1;
    }
    if (number & 0b000100000) {
        LATAbits.LATA5 = 1;
    }
    if (number & 0b001000000) {
        LATFbits.LATF0 = 1;
    }
    if (number & 0b010000000) {
        LATBbits.LATB0 = 1;
    }
    if (number & 0b100000000) {
        LATBbits.LATB1 = 1;
    }
    
	//see Readme.md for examples
}

void LEDarray_disp_bin_n(int number, int max)
{
	//some code to turn on/off the pins connected to the LED array
  
    
	//if statements and bit masks can be used to determine if a particular pin should be on/off
    int increments = max/9;
    unsigned int disp_val;
	number = number - increments;
    if (number < 0){
        disp_val = 0;
        
    }
    if (number > 0){
        disp_val = 1;
        number = number - increments;
        while (number > 0){
        disp_val = disp_val << 1;
        number = number - increments;
        
        }
    }
    LEDarray_disp_bin(disp_val);
    
	//see Readme.md for examples
}
/************************************
/ Function LEDarray_disp_dec
/ Used to display a number on the LEDs
/ where each LED is a value of 10
************************************/
void LEDarray_disp_dec(int number)
{
	unsigned int disp_val;
	number = number - 10;
    if (number < 0){
        disp_val = 0;
    }
    if (number > 0){
        disp_val = 1;
        number = number - 10;
        while (number > 0){
        disp_val = disp_val << 1;
        number = number - 10;
        LEDarray_disp_bin(disp_val);
        }
    }
	//some code to manipulate the variable number into the correct
    
	//format and store in disp_val for display on the LED array

	 	//display value on LED array
    LEDarray_disp_bin(disp_val);
}

void LEDarray_disp_linear(int number, int max)
{
    int increments = max/9;
    unsigned int disp_val;
	number = number - increments;
    if (number < 0){
        disp_val = 0;
        
    }
    if (number > 0){
        disp_val = 1;
        number = number - increments;
        while (number > 0){
        disp_val = disp_val << 1;
        disp_val += 1;
        number = number - increments;
        
        }
    }
    LEDarray_disp_bin(disp_val);
	//some code to manipulate the variable number into the correct
    
	//format and store in disp_val for display on the LED array

	 	//display value on LED array
    
}

/************************************
/ LEDarray_disp_PPM
/ Function used to display a level on the LED array with peak hold
/ cur_val is the current level from the most recent sample, and max is the peak value for the last second
/ these input values need to calculated else where in your code
************************************/
void LEDarray_disp_PPM(int cur_max, int max, int cal_max)
{	
	// some code to format the variable cur_val and max, store in disp_val for display on the LED array
    int cur_val ;
    int max_val ;
    
	cur_max = cur_max - cal_max/9;
   
    if (cur_max > 0){
        cur_val = 1;
        cur_max = cur_max - cal_max/9;
        while (cur_max > 0){
            cur_val = cur_val << 1;
            cur_val += 1;
            cur_max = cur_max - cal_max/9;
        }
    }
    else {
        cur_val=0;
    }
    
    max = max - cal_max/9;
    
    if (max > 0){
            max_val = 1;
            max = max - cal_max/9;
            while (max > 0){
            max_val = max_val << 1;
            max = max - cal_max/9;
        }
    }
    else {
        max_val=0;
    }
    
	// hint: one method is to manipulate the variables separately and then combine them using the bitwise OR operator

	LEDarray_disp_bin(max_val|cur_val);	//display value on LED array
}

