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

//* Added to use arduino mills and delay functions*//
#include "Arduino.h" 
  
// strings and math
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

// interrupts and sleep
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <alloca.h>

#ifdef __cplusplus

#include "arduinoUART.h"

#endif
