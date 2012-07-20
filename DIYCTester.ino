//TODO: Debouncing
//TODO: Store values in EEPROM
//TODO: Design custom shield

// include the library code:
//#include <Wire.h>
//#include <EEPROM.h>
//#include <Adafruit_MCP23017.h>
//#include <Adafruit_RGBLCDShield.h>

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
  // set up the LCD's number of rows and columns: 
  Serial.begin(57600);
  Serial.print("Hello diyc.com!");

  settings = new OutputSettings(new DIYCVars());
}

void loop() {
  uint8_t buttons = settings->getVars()->getLcd()->readButtons();
  DIYCSettings *new_settings = settings;

  // TODO: Fancy debouncing of the buttons.
  delay(150);

  if (buttons) {
    if (buttons & BUTTON_UP) {
      Serial.println("UP");
      new_settings = settings->upAction();
    }
    if (buttons & BUTTON_DOWN) {
      Serial.println("DOWN");
      new_settings = settings->downAction();
    }
    if (buttons & BUTTON_LEFT) {
      Serial.println("LEFT");
      new_settings = settings->leftAction();
    }
    if (buttons & BUTTON_RIGHT) {
      Serial.println("RIGHT");
      new_settings = settings->rightAction();
    }
    if (buttons & BUTTON_SELECT) {
      Serial.println("SELECT");
      new_settings = settings->selectAction();
    }
  }
  
  if ( new_settings != settings )
  {
    delete settings;
    settings = new_settings;
  }
}
