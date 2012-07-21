//TODO: Debouncing
//TODO: Design custom shield

#include "DIYCVars.h"
#include "DIYCSettings.h"
#include "OutputSettings.h"

// These #defines make it easy to set the backlight color
#define RED 0x1
#define GREEN 0x2
#define YELLOW 0x3
#define BLUE 0x4
#define VIOLET 0x5
#define TEAL 0x6
#define WHITE 0x7

DIYCSettings *settings;

void setup() {
  settings = new OutputSettings(new DIYCVars());
}

void loop() {
  uint8_t buttons = settings->getVars()->getLcd()->readButtons();
  DIYCSettings *new_settings = settings;

  if (buttons) {
    if (buttons & BUTTON_UP)
      new_settings = settings->upAction();
    if (buttons & BUTTON_DOWN)
      new_settings = settings->downAction();
    if (buttons & BUTTON_LEFT)
      new_settings = settings->leftAction();
    if (buttons & BUTTON_RIGHT)
      new_settings = settings->rightAction();
    if (buttons & BUTTON_SELECT)
      new_settings = settings->selectAction();
  }
  
  if ( new_settings != settings )
    delete settings;
  settings = new_settings;

  settings->getVars()->sendData();
  delay(100);
}
