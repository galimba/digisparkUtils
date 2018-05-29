//Digispark attiny85 code for generating a usb key
// that automatically locks ubuntu screen every 30secs
//                    VERY ANNOYING!
// 2018 Personal project, trying some arduino stuff
// published under GPL v3.0
// Galimba

#include "DigiKeyboard.h"

void setup()
{
  pinMode(1,OUTPUT); // Onboard LED
  DigiKeyboard.sendKeyStroke(0); // official github says this should be here
}

void loop()
{ //Main loop
  delay(1500); //giving it a sec to load up the terminal, just in case :-)
  lockScreen(); // this will lock the screen
  delay(30000); // then lay dormant for half a minute, and loop
}

void lockScreen()
{
   DigiKeyboard.sendKeyStroke(KEY_L,MOD_ALT_LEFT|MOD_CONTROL_LEFT);
}
