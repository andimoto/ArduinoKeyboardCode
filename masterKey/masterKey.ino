#include <Keyboard.h>

int buttonPin = 3;  // Set a button to any pin

void setup()
{
  pinMode(buttonPin, INPUT);  // Set the button as an input
}

void loop()
{
  if (digitalRead(buttonPin) == 1)  // if the button goes low
  {
    lockScreen();
//    startLinuxTerminal();
//    startGVim();
    delay(300);  // delay so there aren't a kajillion z's
  }
}

void startLinuxTerminal(void)
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('t');
    Keyboard.releaseAll();
}

void lockScreen(void)
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('l');
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
