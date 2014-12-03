/*
  MeggyJr_Blink.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
int heading = 0; // possible values are 0, 1, 2, 3
int xApple = random(8);
int yApple = random(8);

struct Point{
  int xPlayer; // coordinates of player dot
  int yPlayer;
};

Point p1 = {3, 4};

int snakeArray[64] = {p1};

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  Serial.begin(9600);
}


void loop()                     // run over and over again
{
  /*
  Draw Player
  Display Slate
  Check Buttons
  Update direction if a button is pressed
  Update player based on direction
  Correct for wrap
  */
  drawThings();
  directions();
  Serial.print("X is");
  Serial.println(xPlayer);
  Serial.println(yPlayer);
  Serial.println();
}

void drawThings()
{
  DrawPx(xPlayer, yPlayer, 1);
  DisplaySlate();
  delay(500);
}

void directions()
{
  CheckButtonsPress();
  if(Button_Left)
  {
    heading = 4;
  }
  if(Button_Right)
  {
    heading = 1;
  }
  if(Button_Down)
  {
    heading = 2;
  }
  if(Button_Up)
  {
    heading = 0;
  }

  if(heading == 0)
  {
    if(yPlayer < 7)
    {
    yPlayer = yPlayer + 1;
    }
    else
    yPlayer = 0;
  }
  if(heading == 1)
  {
    if(xPlayer < 7)
    {
    xPlayer = xPlayer + 1;
    }
    else
    xPlayer = 0;
  }
  if(heading == 2)
  {
    if(yPlayer > 0)
    {
    yPlayer = yPlayer - 1;
    }
    else
    yPlayer = 7;
  } 
  if(heading == 3)
  {
    if(xPlayer > 0)
    {
    xPlayer = xPlayer - 1;
    }
    else
    xPlayer = 7;
  } 
}

void checkApple()
{
  
}
