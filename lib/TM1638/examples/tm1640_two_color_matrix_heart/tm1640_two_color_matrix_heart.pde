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

void drawbig();
void drawsmall();

int speed = 800;

void setup()
{
  // nothing to do here
}

void loop()
{
  drawbig();
  delay(speed);
  drawsmall();
  delay(speed);
}

void drawbig()
{
 
  
  module.clearDisplay(); 
  module.setRow(1,0,0b01100110);           
  module.setRow(1,1,0b11111111);
  module.setRow(1,2,0b11111111);
  module.setRow(1,3,0b11111111);
  module.setRow(1,4,0b01111110);
  module.setRow(1,5,0b00111100);
  module.setRow(1,6,0b00011000);
  module.setRow(1,7,0b00000000);
}

void drawsmall()
{
  module.clearDisplay(); 
  module.setRow(2,0,0b00000000);           
  module.setRow(2,1,0b00100100);
  module.setRow(2,2,0b01111110);
  module.setRow(2,3,0b01111110);
  module.setRow(2,4,0b00111100);
  module.setRow(2,5,0b00011000);
  module.setRow(2,6,0b00000000);
  module.setRow(2,7,0b00000000);
  
}