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
#include <time.h>

static int i = 0;


struct keyarr
{
	char letter;
	char* code;
};


	char codesearch(char* code) //give concatinated string to search for
	{
		char letter;
		struct keyarr key[37] =
		{ //huge array to compare things to
			{ 'A', "./" }, { 'B', "/..." }, { 'C', "/./." }, { 'D', "/.." }, { 'E', "." }, { 'F', "../." }, { 'G', "//." },

			{ 'H', "...." }, { 'I', ".." }, { 'J', ".///" }, { 'K', "/./" }, { 'L', "./.." }, { 'M', "//" }, { 'N', "/." }, { 'O', "///" },

			{ 'P', ".//." }, { 'Q', "//./" }, { 'R', "./." }, { 'S', "..." }, { 'T', "/" }, { 'U', "../" }, { 'V', ".../" }, { 'W', ".//" },

			{ 'X', "/../" }, { 'Y', "/.//" }, { 'Z', "//.." },

			{ '1', ".////" }, { '2', "..///" }, { '3', "...//" }, { '4', "..../" }, { '5', "....." },
			{ '6', "/...." }, { '7', "//..." }, { '8', "///.." }, { '9', "////." }, { '0', "/////" }
		};

		for (int j = 0; j < 37; j++) //search through array, letters + numbers
		{
			if (key[j].code == code) letter = key[j].letter;
		}

		return letter;

	}



int main(void)
{
	hardware_init(); //need to enable light sens
    LED1_EN;


	PRINTF("\rLight Sensor\n");


	unsigned short calibration = 0;
	unsigned char lights = 0;

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
		calibration = ADC0_CLP0 + ADC0_CLP1 + ADC0_CLP2 + ADC0_CLP3 + ADC0_CLP4 + ADC0_CLPS;
		calibration = calibration >> 1 | 0x8000;
		ADC0_PG = calibration;

		calibration = 0;
		calibration = ADC0_CLM0 + ADC0_CLM1 + ADC0_CLM2 + ADC0_CLM3 + ADC0_CLM4 + ADC0_CLMS;
		calibration = calibration >> 1 | 0x8000;
		ADC0_MG = calibration;


		ADC0_SC3 = 0; // Turn off Hardware Averaging






		int fsm1 = 0; //if previous state was on
		int fsm2 = 1; //if previous state was off
		int timebool=0;
		int time = 0;
		int offtime = 0;
		char *code="";
		char letter;
		while(1) {
			ADC0_SC1A = 0x03; // Set Channel, starts conversion.
			while(!(ADC0_SC1A & 0x80)){	}
			//delay(1000);
			lights = ADC0_RA; // Resets COCO


			PRINTF("\rLight Sensor Value: %d",lights);



			//read in light values
			if(lights <= 252) { //if light is on
				GPIOD_PDOR &= ~(1<<5);//turns on
				time++;


				if(fsm2 == 1) //if light was previously off
				{
					PRINTF(" toggled on, off time= %d\n", offtime);
					fsm1=1; //last state on
					fsm2=0;
					timebool=0;
					offtime = 0;
				}



			}
			else { //if light is off


				GPIOD_PDOR |= (1<<5); //turns off
				offtime++;
				if(fsm1==1) //if light was previously on
				{
					PRINTF(" TOGGLED off, on time = %d\n", time);
					fsm1=0;
					fsm2=1;
					timebool=1;
					time=0;
				}

			}


			if(timebool)
			{

				 if(140 < time&&time<160) //.
				            {
				                int code_length = strlen(code); //append dots
				                code[code_length]='.';
				                code[code_length+1]= '\0';
				            }
				            else if(440<time&&time<460) // /
				            {
				                int code_length = strlen(code); //append dashes
				                code[code_length]='/';
				                code[code_length + 1]= '\0';
				            }


				timebool = 0;
				time = 0;
			}

			if(offtime > 615)
				{
				PRINTF(" OFFTIME EXCEDDED, DUMPING\n");

				if(code[0]!='\0')
				{
							letter = codesearch(code);

				    		PRINTF(" %c\n",letter);
				    		code[0] = '\0';
				}
				    		offtime=0;
				}


		}



    return 0;

}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
