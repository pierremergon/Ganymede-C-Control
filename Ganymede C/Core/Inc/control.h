/*
 * control.h
 *
 *  Created on: Jan 13, 2024
 *      Author: mergo
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_
//#include "stm32l0xx_hal.h"
#include "main.h"

//uint8_t roomStatus = 0;
//uint8_t a;
//uint8_t z;

#define occupied 1
#define unOccupied 0

unsigned char test(void);
void setPIR2(void);

unsigned char DispleyRoomStatus(uint8_t roomStatus); //This function will determine if the room is occupied or now
unsigned char beginIRScan(void); //start IR LED
unsigned char endIRScan(void); // stop IR LED
unsigned char RoomEmpty(void); // displays when the room is open for use
unsigned char RoomFull(void); // displays LED to indicate that the room is occupied
unsigned char UnsureRoom(void); // When we are unsure if the room is empty or full, this is used
unsigned char calibration(void); // used for initial calibration and setting registers if necessary
unsigned char lowPowerMode(void); //when occu is inactive, it goes into a low power mode
unsigned char startOccuTimer(unsigned char feed); //system timeout, when no movement is detected, system goes to sleep
unsigned char reserMainTimer(void); //used to reset the timeout timer
unsigned char determineOccu(unsigned char VBit,unsigned char HBit, unsigned char timeoutBit); // Function to determine if the room is occupied or empty




#endif /* INC_CONTROL_H_ */
