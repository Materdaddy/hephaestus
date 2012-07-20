#include "MaxDimmingSettings.h"
#include "NumChannelsSettings.h"
#include "MinDimmingSettings.h"

MaxDimmingSettings::MaxDimmingSettings(DIYCVars *vars) : DIYCSettings(vars)
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Max Dimming ->");
}

DIYCSettings *MaxDimmingSettings::upAction()
{
  return new NumChannelsSettings(mVars);
}

DIYCSettings *MaxDimmingSettings::downAction()
{
  return new MinDimmingSettings(mVars);
}

DIYCSettings *MaxDimmingSettings::rightAction()
{
  return new EditMaxDimmingSettings(mVars);
}

DIYCSettings *MaxDimmingSettings::selectAction()
{
  return new EditMaxDimmingSettings(mVars);
}

/*
 * Edit output settings
 */

EditMaxDimmingSettings::EditMaxDimmingSettings(DIYCVars *vars) : DIYCSettings(vars), mMaxDimming(mVars->getMaxDimming())
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(mMaxDimming);
}

DIYCSettings *EditMaxDimmingSettings::downAction()
{
  if ( mMaxDimming > 0 )
    --mMaxDimming;

  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(mMaxDimming);

  return this;
}

DIYCSettings *EditMaxDimmingSettings::upAction()
{
  if ( mMaxDimming < 255 )
    ++mMaxDimming;

  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(mMaxDimming);

  return this;
}

DIYCSettings *EditMaxDimmingSettings::leftAction()
{
  return new MaxDimmingSettings(mVars);
}

DIYCSettings *EditMaxDimmingSettings::selectAction()
{
  mVars->setMaxDimming(mMaxDimming);
  return new MaxDimmingSettings(mVars);
}

EditMaxDimmingSettings::~EditMaxDimmingSettings() { }
