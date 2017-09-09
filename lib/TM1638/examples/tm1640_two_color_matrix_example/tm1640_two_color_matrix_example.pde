/*
Library examples for TM1640.

Modified to Support JY-MCU 8x8RG Modules by D/PLAY-ZONE (info@play-zone.ch).

Original Library Copyright (C) 2011 Ricardo Batista <rjbatista at gmail dot com>

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <TM1638.h> // required because the way arduino deals with libraries
#include <TM1640.h>

// define a module on data pin 3, clock pin 2
TM1640 module(3, 2);

void draw(boolean flip);

int speed = 1000;

void setup()
{
  // nothing to do here
}

void loop()
{
  draw(true);
  delay(speed);
  draw(false);
  delay(speed);
}

void draw(boolean flip = false)
{
  byte color1 = 1;
  byte color2 = 2;
  
   if (flip) {
       color1 = 2;
       color2 = 1;
   }
  
  module.clearDisplay(); 
  module.setRow(color1,0,0b11111111);           
  module.setRow(color1,1,0b10000001);
  module.setRow(color1,2,0b10111101);
  module.setRow(color1,3,0b10100101);
  module.setRow(color1,4,0b10100101);
  module.setRow(color1,5,0b10111101);
  module.setRow(color1,6,0b10000001);
  module.setRow(color1,7,0b11111111);

  module.setRow(color2,0,0b00000000);
  module.setRow(color2,1,0b01111110);
  module.setRow(color2,2,0b01000010);
  module.setRow(color2,3,0b01011010);
  module.setRow(color2,4,0b01011010);
  module.setRow(color2,5,0b01000010);
  module.setRow(color2,6,0b01111110);
  module.setRow(color2,7,0b00000000);
  
}