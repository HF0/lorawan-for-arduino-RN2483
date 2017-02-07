/*
 *  ERTIS - University of Malaga
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 2.1 of the License, or
 *  (at your option) any later version.
   
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
  
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Current version:         Version modified by UMA from the Libelium original version
 *	Original version: http://www.cooking-hacks.com/media/cooking/images/documentation/tutorial_kit_lorawan/LoRaWAN_library_arduino_v1_3.zip
 */ 

#include "arduinoUART.h"
#include "arduinoLoRaWAN.h"

const int error_led =  13;

// define radio settings
//////////////////////////////////////////////
uint8_t power = 15;
uint32_t frequency = 868100000;
char spreading_factor[] = "sf12";
char coding_rate[] = "4/5";
uint16_t bandwidth = 125;
char crc_mode[] = "on";
//////////////////////////////////////////////
uint8_t error;


void setup() 
{
  pinMode(error_led, OUTPUT);
  digitalWrite(error_led, LOW);

  error = radioModuleSetup();
  if (error == 0)
  {
    digitalWrite(error_led, LOW);
  }
  else 
  {
    digitalWrite(error_led, HIGH);
  }  

  Serial.println();
  Serial.println(F("Lorawan receive test 1"));
  Serial.println();
}


void loop() 
{
  
  error = LoRaWAN.receiveRadio(10000);
  if (error == 0)
  {
	Serial.print(F("Packet received. Size "));
	Serial.print(LoRaWAN._length);
	Serial.print( F("( real bytes "));
	Serial.print(LoRaWAN._length / 2);
	Serial.println( F(")"));

    //packet in LoRaWAN._buffer
    //length in LoRaWAN._length

    digitalWrite(error_led, LOW);
    LoRaWAN.getRadioSNR();
    //SNR in LoRaWAN._radioSNR
  }
  else 
  {
    //Error waiting for packets. error 
    // error code
    //  1: error
    //  2: no incoming packet
    digitalWrite(error_led, HIGH);
  }  
  
}


uint8_t radioModuleSetup()
{

	uint8_t status = 0;
	uint8_t e = 0;
	Serial.begin(115200);

	e = LoRaWAN.ON();
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan radio OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan radio not initilized"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.macPause();
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan p2p OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan p2p error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.setRadioPower(power);
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan radio power OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan radio power error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.getRadioPower();
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan get radio power OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan get radio power error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.setRadioFreq(frequency);
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan set radio frequency OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan set radio frequency error"));
		digitalWrite(error_led, LOW);
		status = 1;
	}


	e = LoRaWAN.getRadioFreq();
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan get radio frequency OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan get radio frequency error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.setRadioSF(spreading_factor);
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan set radio sf OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan set radio sf error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.getRadioSF();
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan get radio sf OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan get radio sf error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.setRadioCR(coding_rate);
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan set radio cr OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan set radio cr error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.getRadioCR();
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan get radio cr OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan get radio cr error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.setRadioBW(bandwidth);
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan set radio bw OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan set radio bw error"));
		digitalWrite(error_led, HIGH);
	}

	e = LoRaWAN.getRadioBW();
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan get radio bw OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan get radio bw error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.setRadioCRC(crc_mode);
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan set radio crc OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan set radio crc error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	e = LoRaWAN.getRadioCRC();
	if (e == LORAWAN_ANSWER_OK)
	{
		Serial.println(F("Lorawan get radio crc OK"));
		digitalWrite(error_led, LOW);
	}
	else
	{
		Serial.println(F("Lorawan get radio crc error"));
		digitalWrite(error_led, HIGH);
		status = 1;
	}

	return status;
}
