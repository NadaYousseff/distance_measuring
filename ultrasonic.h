/******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the Ultrasonic sensor
 *
 * Author: Nada Youssef
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TRIGGER_PORT    PORTB_ID
#define TRIGGER_PIN     PIN5_ID

#define CLOCK           F_CPU_8
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description: function to initialize the ultrasonic
 * 1- initialize the ICU
 * 2- setup the ICU call back function
 * 3- setup the direction for the trigger pin as output pin
 */
void Ultrasonic_init(void);
/*
 * Description:
 * function to Send the Trigger pulse to the ultrasonic
 */
void Ultrasonic_Trigger(void);
/*
 * Description:
 * function to Send the trigger pulse by using Ultrasonic_Trigger function.
 * and start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_readDistance(void);
/*
 * Description: the call back function called by the ICU driver.
 * This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */