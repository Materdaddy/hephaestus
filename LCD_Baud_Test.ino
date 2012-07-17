// include the library code:
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

#include "DIYCTester.h"
#include "RenardIn.h"
#include "RenardOut.h"

// These #defines make it easy to set the backlight color
#define RED 0x1
#define GREEN 0x2
#define YELLOW 0x3
#define BLUE 0x4
#define VIOLET 0x5
#define TEAL 0x6
#define WHITE 0x7

DIYCTester *diyc = NULL;

void setup() {
  // set up the LCD's number of rows and columns: 
  Serial.begin(57600);

  DIYCVars *vars = new DIYCVars;
  delay(500);
  diyc = new RenardIn(vars);
}

void loop() {
  uint8_t buttons = diyc->getVars()->getLcd()->readButtons();
  DIYCTester *new_diyc = diyc;

  if (buttons) {
    delay(100);
    if (buttons & BUTTON_UP) {
      new_diyc = diyc->mUpAction();
      Serial.println("UP");
    }
    if (buttons & BUTTON_DOWN) {
      new_diyc = diyc->mDownAction();
      Serial.println("DOWN");
    }
    if (buttons & BUTTON_LEFT) {
      new_diyc = diyc->mLeftAction();
      Serial.println("LEFT");
    }
    if (buttons & BUTTON_RIGHT) {
      new_diyc = diyc->mRightAction();
      Serial.println("RIGHT");
    }
    if (buttons & BUTTON_SELECT) {
      new_diyc = diyc->mSelectAction();
      Serial.println("SELECT");
    }
  }

  if ( new_diyc != diyc )
  {
    delete diyc;
    diyc = new_diyc;
    new_diyc = NULL;
  }
  
  new_diyc = diyc->mLoop();

  if ( new_diyc != diyc )
  {
    delete diyc;
    diyc = new_diyc;
    new_diyc = NULL;
  }
}
