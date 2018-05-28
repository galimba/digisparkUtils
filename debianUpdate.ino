//Digispark attiny85 code for generating a usb key
// that automatically runs ubuntu update && upgrade
// 2018 Personal project, trying some arduino stuff
// published under GPL v3.0
// Galimba

#include "DigiKeyboard.h"
void setup() {
  pinMode(1,OUTPUT); // Onboard LED
}

void loop() {

  //turn LED ON
  digitalWrite(1,HIGH);
  delay(1000);

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_ALT_LEFT|MOD_CONTROL_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("sudo apt-get update && sudo apt-get upgrade -y");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);
  DigiKeyboard.print("yourPasswordHERE");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //turn LED OFF
  digitalWrite(1,LOW);
  delay(1000);
  for (;;) {
 /*empty*/
}
}
