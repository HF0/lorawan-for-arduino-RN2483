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

#include <Wire.h>

#include "arduinoUART.h"
#include "arduinoLoRaWAN.h"


const int error_led =  13;

// define radio settings
//////////////////////////////////////////////
int8_t power = 15;
uint32_t frequency = 868100000;
char spreading_factor[] = "sf12";
char coding_rate[] = "4/5";
uint16_t bandwidth = 125;
char crc_mode[] = "on";
//////////////////////////////////////////////


char data[] = "00010203040506070809000102030405060708090001020304050607080900010203040506070809000102030405060708090001020304050607080900010203040506070809";
uint8_t error;


void setup() 
{
  pinMode(error_led, OUTPUT);
  digitalWrite(error_led, LOW);
  
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);

  error = radioModuleSetup();
  if (error == 0)
  {
	Serial.println(F("Radio module OK"));
    digitalWrite(error_led, LOW);
  }
  else 
  {
	Serial.println(F("Radio module error"));
    digitalWrite(error_led, HIGH);
  }  

  Serial.println();
  Serial.println(F("Lorawan send test 1"));
  Serial.println();

}


void blinkPin(int num){
	for(int i=0; i < num; i++){
		digitalWrite(3, HIGH);
		delay(10);
		digitalWrite(3, LOW);
		delay(10);
	}
}

void loop() 
{
	
  Serial.println(F("Before sleep"));
  
  blinkPin(1);
  error = LoRaWAN.sleep(4000l);
  if( error == LORAWAN_ANSWER_OK ){
	Serial.println(F("Sleep ok"));
  }else{
	Serial.println(F("Sleep error"));
  }

  Serial.println(F("Sending packet"));

  blinkPin(2);

  error = LoRaWAN.sendRadio(data);
  // Check status
  if (error == 0)
  {
	  Serial.println(F("Packet sent"));
	  digitalWrite(error_led, LOW);
  }
  else
  {
	  Serial.print(F("Error sending packet "));
	  Serial.println(error);
	  digitalWrite(error_led, LOW);
  }

  blinkPin(3);
  delay(3000);

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
