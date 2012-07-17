#include "RenardIn.h"

#include <Adafruit_RGBLCDShield.h>
#include "RenardOut.h"

RenardIn::RenardIn(DIYCVars *vars) : DIYCTester(vars)
{
  mVars->getLcd()->clear();
  mVars->getLcd()->setCursor(0,0);
  mVars->getLcd()->print("Renard In");
}

DIYCTester *RenardIn::mDownAction()
{
  return new RenardOut(this->mVars);
}
