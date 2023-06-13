/******************************************************************************
 *
 * Module: distance measuring
 *
 * File Name: distance_measuring.c
 *
 * Description: source file for the app of measuring the distance using the ultrasonic sensor and display it by lcd
 *
 * Author: Nada Youssef
 *
 *******************************************************************************/
#include "lcd.h"
#include "ultrasonic.h"
#include <util/delay.h>
#include<avr/interrupt.h>

int main(void){
    /* enable the global interrupt for the icu */
	sei();
	uint16 distance =0;   /* variable to store the measured distance */

	LCD_init();  /* Initializing the lcd to display the measured distance */
	LCD_displayString("Distance=    cm");
	Ultrasonic_init();     /* initializing the ultrasonic to measure distance */

	while(1){
        /* get the measured distance from the ultrasonic sensor */
		distance = Ultrasonic_readDistance();
		/* display the measured distance using the lcd */
		LCD_moveCursor(0,9);
		LCD_intgerToString(distance);
		LCD_displayString(" ");     /* in case the previous measured value was > 99and the current value <100 */

	}
}

