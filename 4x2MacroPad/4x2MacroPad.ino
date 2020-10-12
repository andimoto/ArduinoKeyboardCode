//install HID-Project!
#include <HID-Project.h>
#include <HID-Settings.h>

//dont user Keyboard Lib. it is already included in HID-Project
//#include <Keyboard.h>


int VOL_DOWN =  10;     // Button for Volume DOWN
int VOL_UP = 16;       // Button for  Volume UP
int MEDIAPREV = 14;    // Button for PREV
int MEDIANEXT = 15;    // Button for NEXT
int MUTE = 9;        // Button for MUTE
int PLAY = 8;        // Button for PLAY / PAUSE


int LOCK = 7;        // Linux Lock Screen Shortcut
int CALC = 6;       // call calculator app

void setup()
{
  pinMode(VOL_DOWN, INPUT_PULLUP);    // Set the button as an input with Pull-up
  pinMode(VOL_UP, INPUT_PULLUP);      // Set the button as an input with Pull-up
  pinMode(MEDIAPREV, INPUT_PULLUP);   // Set the button as an input with Pull-up
  pinMode(MEDIANEXT, INPUT_PULLUP);   // Set the button as an input with Pull-up
  pinMode(PLAY, INPUT_PULLUP);        // Set the button as an input with Pull-up
  pinMode(MUTE, INPUT_PULLUP);        // Set the button as an input with Pull-up
  pinMode(LOCK, INPUT_PULLUP);        // Set the button as an input with Pull-up
  pinMode(CALC, INPUT_PULLUP);        // Set the button as an input with Pull-up
  
  Consumer.begin();           
}

void loop()
{
  if(digitalRead(MEDIANEXT) == 0)
  {
    Consumer.press(MEDIA_NEXT);
    delay(200);  // delay 
  }
    
  if(digitalRead(MEDIAPREV) == 0)
  {
    Consumer.press(MEDIA_PREVIOUS);
    delay(200);  // delay 
  }   

  if(digitalRead(PLAY) == 0)
  {
    Consumer.press(MEDIA_PLAY_PAUSE);
    delay(200);  // delay 
  }

  if(digitalRead(MUTE) == 0)
  {
    Consumer.press(MEDIA_VOLUME_MUTE);
    delay(200);  // delay 
  }

  if(digitalRead(CALC) == 0)
  {
    Consumer.press(CONSUMER_CALCULATOR);
    delay(200);  // delay 
  }



  if(digitalRead(VOL_UP) == 0)
  {
    Consumer.press(MEDIA_VOLUME_UP);
    delay(150);  // delay 
  }
  
  if(digitalRead(VOL_DOWN) == 0)
  {
    Consumer.press(MEDIA_VOLUME_DOWN);
    delay(150);  // delay 
  }



  if(digitalRead(LOCK) == 0)
  {
    lockScreen();             //Button release is done in this function
    delay(150);  // delay 
  }

  Consumer.releaseAll();
}

void lockScreen(void)
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('l');
    Keyboard.releaseAll();
}



void startLinuxTerminal(void)
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('t');
    Keyboard.releaseAll();
}


void startGVim()
{
  startLinuxTerminal();
  delay(1000);
  Keyboard.println("gvim");
  Keyboard.releaseAll();
  delay(300);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F10);
  Keyboard.releaseAll();
}
