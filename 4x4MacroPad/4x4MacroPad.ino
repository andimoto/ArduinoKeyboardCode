//install HID-Project!
#include <HID-Project.h>
#include <HID-Settings.h>

//dont user Keyboard Lib. it is already included in HID-Project
//#include <Keyboard.h>


int SHIFT = 6;  // SHIFT
int UP = 9;     // Button for UP/NEXT
int DOWN = 8;   // Button for DOWN/PREV
int USER = 7;   // Free usable

void setup()
{
  pinMode(SHIFT, INPUT_PULLUP); // Set the button as an input
  pinMode(UP, INPUT_PULLUP);    // Set the button as an input
  pinMode(DOWN, INPUT_PULLUP);  // Set the button as an input
  pinMode(USER, INPUT_PULLUP);  // Set the button as an input

  Consumer.begin();           
}

void loop()
{
  if (digitalRead(SHIFT) == 0)  // if the button goes low
  {
    if(digitalRead(UP) == 0)
    {
      Consumer.press(MEDIA_NEXT);
      delay(200);  // delay 
    }
    
    if(digitalRead(DOWN) == 0)
    {
      Consumer.press(MEDIA_PREVIOUS);
      delay(200);  // delay 
    }   

    if(digitalRead(USER) == 0)
    {
      Consumer.press(MEDIA_PLAY_PAUSE);
      delay(200);  // delay 
    }
  }else{                          // SHift is not pressed here
    if(digitalRead(UP) == 0)
    {
      Consumer.press(MEDIA_VOLUME_UP);
      delay(150);  // delay 
    }
    
    if(digitalRead(DOWN) == 0)
    {
      Consumer.press(MEDIA_VOLUME_DOWN);
      delay(150);  // delay 
    }

    if(digitalRead(USER) == 0)
    {
      lockScreen();             //Button release is done in this function
      delay(150);  // delay 
    }
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
