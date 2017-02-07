# LoRaWAN-for-Arduino-RN2483
LoRaWAN Micrchip RN2483 libraries for Arduino

## What is this?

This is a library for the Microchip RN2493 LoRaWAN for Arduino.

- All coments, suggestions, bug reports are welcome

## Installation

Just include the files provided in your project (I personally use Atmel studio). A basic example is provided (in p2p mode).

- In order to enable debug messages change the value of the DEBUG_UART directive in arduinoUART.h

## Connection

- The examples use **Serial** to debug and **Serial 1** to connect to the LoRaWAN module. In order to modify the Serial used, go to arduinoUART.cpp and change the value of **UART**.

- I use a Xbee explorer to connect the Xbee compatible module to the Arduino
- GND - GND
- 3.3V - 3.3V
- DOUT - RX1
- DIN - TX1

## Acknowledgement

This code is a modified version of the one provided by Libelium. [Link](http://www.cooking-hacks.com/media/cooking/images/documentation/tutorial_kit_lorawan/LoRaWAN_library_arduino_v1_3.zip) 
The one provided by Libelium is only meant to work with the multiprotocol shield provided by them. 

### Modifications:

- Removed code related to the multiprotocol shield
- Added sleep operation (sys sleep <valuems>)

## License
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 of the License, or
(at your option) any later version.
   
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
  
You should have received a copy of the GNU Lesser General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
