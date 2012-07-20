#include "MinDimmingSettings.h"
#include "MaxDimmingSettings.h"
#include "ProtocolSettings.h"

MinDimmingSettings::MinDimmingSettings(DIYCVars *vars) : DIYCSettings(vars)
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Min Dimming ->");
}

DIYCSettings *MinDimmingSettings::upAction()
{
  return new MaxDimmingSettings(mVars);
}

DIYCSettings *MinDimmingSettings::downAction()
{
  return new ProtocolSettings(mVars);
}

DIYCSettings *MinDimmingSettings::rightAction()
{
  return new EditMinDimmingSettings(mVars);
}

DIYCSettings *MinDimmingSettings::selectAction()
{
  return new EditMinDimmingSettings(mVars);
}

/*
 * Edit output settings
 */

EditMinDimmingSettings::EditMinDimmingSettings(DIYCVars *vars) : DIYCSettings(vars), mMinDimming(mVars->getMinDimming())
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(mMinDimming);
}

DIYCSettings *EditMinDimmingSettings::downAction()
{
  if ( mMinDimming > 0 )
    --mMinDimming;

  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(mMinDimming);

  return this;
}

DIYCSettings *EditMinDimmingSettings::upAction()
{
  if ( mMinDimming < 255 )
    ++mMinDimming;

  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(mMinDimming);

  return this;
}

DIYCSettings *EditMinDimmingSettings::leftAction()
{
  return new MinDimmingSettings(mVars);
}

DIYCSettings *EditMinDimmingSettings::selectAction()
{
  mVars->setMinDimming(mMinDimming);
  return new MinDimmingSettings(mVars);
}

EditMinDimmingSettings::~EditMinDimmingSettings() { }
