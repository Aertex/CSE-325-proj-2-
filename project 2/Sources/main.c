/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "board.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include <string.h>

static int i = 0;

struct keyarr
{
	char letter;
	char* code;
};



//not sure if any of this will be usefull
/*
void displayMorse(char *message, int length)
{

	char temp;

	for(int i = 0; i < length; i++)
	{
		temp = message[i];

		switch(temp)
		{
		case '.':
			i = length;
				break;

		case 'A':
			turnOnFor(250);//dot
			doNothingFor(250);//space between dot/dash
			turnOnFor(750);//dash
			doNothingFor(750);//space between letter
				break;
		case 'B':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);


			doNothingFor(750);
				break;
		case 'C':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);


			doNothingFor(750);
				break;
		case 'D':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);


			doNothingFor(750);
				break;
		case 'E':
			turnOnFor(250);


			doNothingFor(750);
				break;
		case 'F':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);


			doNothingFor(750);
				break;
		case 'G':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);



			doNothingFor(750);
				break;
		case 'H':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);


			doNothingFor(750);
				break;
		case 'I':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);



			doNothingFor(750);
				break;
		case 'J':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);


			doNothingFor(750);
				break;
		case 'K':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);



			doNothingFor(750);
				break;
		case 'L':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);


			doNothingFor(750);
				break;
		case 'M':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);


			doNothingFor(750);
				break;
		case 'N':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);



			doNothingFor(750);
				break;
		case 'O':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);



			doNothingFor(750);
				break;
		case 'P':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);


			doNothingFor(750);
				break;
		case 'Q':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);


			doNothingFor(750);
				break;
		case 'R':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);



			doNothingFor(750);
				break;
		case 'S':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);



			doNothingFor(750);
				break;
		case 'T':
			turnOnFor(750);



			doNothingFor(750);
				break;
		case 'U':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);



			doNothingFor(750);
				break;
		case 'V':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);


			doNothingFor(750);
				break;
		case 'W':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);



			doNothingFor(750);
				break;
		case 'X':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);


			doNothingFor(750);
				break;
		case 'Y':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);


			doNothingFor(750);
				break;
		case 'Z':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);


			doNothingFor(750);
				break;

		case '0':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);

			doNothingFor(750);
				break;
		case '1':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);

			doNothingFor(750);
				break;
		case '2':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);

			doNothingFor(750);
				break;
		case '3':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);

			doNothingFor(750);
				break;
		case '4':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(750);

			doNothingFor(750);
				break;
		case '5':
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);

			doNothingFor(750);
				break;
		case '6':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);

			doNothingFor(750);
				break;
		case '7':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);

			doNothingFor(750);
				break;
		case '8':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);
			doNothingFor(250);
			turnOnFor(250);

			doNothingFor(750);
				break;
		case '9':
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(750);
			doNothingFor(250);
			turnOnFor(250);

			doNothingFor(750);
				break;

		case ' ':
			doNothingFor(1000);
				break;
		default:
			doNothingFor(1000);
				break;

		}
	}
}
void turnOnFor(int time)
{

	LED1_ON;//led toggle on
	for(int i =0;i<4000*time;i++)//led wait 'time'
	{

	}
	LED1_OFF;//led toggle off
}

void doNothingFor(int time)
{

	for(int i =0;i<4000*time;i++)//do nothing time
	{

	}
}
*/

char codesearch(char* code) //give concatinated string to search for
{
	char letter;
	/*keyarr key[] =
					{ //huge array to compare things to
		{ 'A', "./" }, { 'B', "/..." }, { 'C', "/./." }, { 'D', "/.." }, { 'E', "." }, { 'F', "../." }, { 'G', "//." },

		{ 'H', "...." }, { 'I', ".." }, { 'J', ".///" }, { 'K', "/./" }, { 'L', "./.." }, { 'M', "//" }, { 'N', "/." }, { 'O', "///" },

		{ 'P', ".//." }, { 'Q', "//./" }, { 'R', "./." }, { 'S', "..." }, { 'T', "/" }, { 'U', "../" }, { 'V', ".../" }, { 'W', ".//" },

		{ 'X', "/../" }, { 'Y', "/.//" }, { 'Z', "//.." },

		{ '1', ".////" }, { '2', "..///" }, { '3', "...//" }, { '4', "..../" }, { '5', "....." },
		{ '6', "/...." }, { '7', "//..." }, { '8', "///.." }, { '9', "////." }, { '0', "/////" }
					}

	for (int j = 0; j < 36; i++) //search through array linearly , letters + numbers
	{
		if (key[i].code == code) letter = key[i].letter;
	}
*/
	return letter;

}
int main(void)
{
	hardware_init(); //need to enable light sens
    LED1_EN;


	PRINTF("Light Sensor");




	unsigned short cal_v = 0;
	unsigned char light_val = 0;

		hardware_init(); // Do clock setup stuff.
		// Clock Gating
		SIM_SCGC5 |= (1<<13); // Enable Light Sensor I/O Port
		SIM_SCGC5 |= (1<<12);
		SIM_SCGC6 |= (1<<27); // Enable ADC Module

		// Setup Analog Input - Default is analog (PTE22), No need to do anything.

		// Setup LED Pin for GPIO
		PORTD_PCR5 &= ~0x700; // Clear First
		PORTD_PCR5 |= 0x700 & (1 << 8); // Set MUX bits

		// Setup Pin 5 as output
		GPIOD_PDDR |= (1 << 5);

		// Setup ADC Clock ( < 4 MHz)
		ADC0_CFG1 = 0;  // Default everything.

		// Analog Calibrate
		ADC0_SC3 = 0x07; // Enable Maximum Hardware Averaging
		ADC0_SC3 |= 0x80; // Start Calibration

		// Wait for Calibration to Complete (either COCO or CALF)
		while(!(ADC0_SC1A & 0x80)){	}


		// Calibration Complete, write calibration registers.
		cal_v = ADC0_CLP0 + ADC0_CLP1 + ADC0_CLP2 + ADC0_CLP3 + ADC0_CLP4 + ADC0_CLPS;
		cal_v = cal_v >> 1 | 0x8000;
		ADC0_PG = cal_v;

		cal_v = 0;
		cal_v = ADC0_CLM0 + ADC0_CLM1 + ADC0_CLM2 + ADC0_CLM3 + ADC0_CLM4 + ADC0_CLMS;
		cal_v = cal_v >> 1 | 0x8000;
		ADC0_MG = cal_v;


		ADC0_SC3 = 0; // Turn off Hardware Averaging
	    /* Never leave main */


		while(1) {
			ADC0_SC1A = 0x03; // Set Channel, starts conversion.
			while(!(ADC0_SC1A & 0x80)){	}
			//delay(1000);
			light_val = ADC0_RA; // Resets COCO
			if(light_val < 250) {
				GPIOD_PDOR |= (1<<5);
			}
			else {
				GPIOD_PDOR &= ~(1<<5);
			}
		}











































	/*
	char* message = "ABC.";
	int length=strlen(message);

	displayMorse(message, length);

	*/

	//need to code a way to concatinate a . or / onto a char* based on time a light is on/off










    /* This for loop should be replaced. By default this loop allows a single stepping. */
    //for (;;) {
    //    i++;
    //}
    /* Never leave main */
    return 0;

}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
