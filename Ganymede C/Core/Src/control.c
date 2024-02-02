/*
 * control.c
 *
 *  Created on: Jan 13, 2024
 *      Author: mergo
 */

#include "control.h"
uint8_t a;

unsigned char test(void)
{
	 	 	  TIM2 -> CCR3 = 17;
		  	  TIM21 -> CCR2 = 17;
		  	  HAL_Delay(1000);
		  	  TIM2 -> CCR3 = 0;
		  	  TIM21 -> CCR2 = 0;
		  	  HAL_Delay(1000);
		  	  return 0;
}



void setPIR2(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //program mode
    for(a=0;a<40;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //program mode
    for(a=0;a<40;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //threshold
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //threshold
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //threshold
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //threshold
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //threshold
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //threshold
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //threshold
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //threshold
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //blind time
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //blind time
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //blind time
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //blind time
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //pulse counter
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //pulse counter
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //window time
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //window time
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //operation modes
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //operation modes
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Signal Source
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //Signal Source
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //reserved
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //reserved
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); //HPF Cut-off
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //reserved
    for(a=0;a<300;a++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); //pulse detection mode
    for(a=0;a<300;a++);
    //return 0;
}

unsigned char beginIRScan(void)
{
	 	 	  TIM2 -> CCR3 = 18;
		  	  TIM21 -> CCR2 = 18;
		  	  HAL_Delay(100);
		  	  TIM2 -> CCR3 = 0;
		  	  TIM21 -> CCR2 = 0;
		  	  HAL_Delay(100);

		  	  return 0;
}

unsigned char RoomEmpty(void)
{
	HAL_GPIO_TogglePin(GPIOA, Green_Pin);
	/*HAL_GPIO_WritePin(GPIOA, Green_Pin, GPIO_PIN_SET);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOA, Green_Pin, GPIO_PIN_RESET);*/

	return 0;

}

unsigned char RoomFull(void)
{
	HAL_GPIO_TogglePin(GPIOA, Red_Pin);
	/*HAL_GPIO_WritePin(GPIOA, Red_Pin, GPIO_PIN_SET);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOA, Red_Pin, GPIO_PIN_RESET);
*/
	return 0;

}

//###############################################Determine Occupancy
unsigned char determineOccu(unsigned char VBit,unsigned char HBit, unsigned char timeoutBit)
{
	unsigned char result;

	unsigned char VB,HB,TB;

	VB = VBit;
	HB = HBit;
	TB = timeoutBit;

	if (VBit == 1)
	{
		VB = 1;
	}

	else if (VBit == 2)
	{
		HB = 0;
	}

 callNextFunction(Vbit,Hbit,Firstbit)


 {
		if ((VB && HB) ==1)
		{
			result = 1;
		}

		if (VB && HB == 0)
		{
			result = 0;
		}

		if ((VB | HB) == 2)
		{
			result = 2;
		}


		return result;

		VB = 2;
		HB = 2;


 }
	/*store the bits in an array that is initialized to 3,3,3,
	the code will then compare the first element in the array to see if its anything but 3. If so, it will store the ,
	next bit in the second element of the array. This allows us to know if a bit was already stored, and what was stored first.
	It then resets the bits at the end of the occu event. It could also be useful to store these initial values and compare it to ,
	final values to see when someone leaves the room.*/

	return result;
}
