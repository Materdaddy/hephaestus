#include "ReadFromEepromSettings.h"
#include "BaudRateSettings.h"
#include "ProtocolSettings.h"
#include "SaveToEepromSettings.h"

ReadFromEepromSettings::ReadFromEepromSettings(DIYCVars *vars) : DIYCSettings(vars)
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Restore ->");
}

DIYCSettings *ReadFromEepromSettings::upAction()
{
  if ( mVars->getProtocol() != DMX )
	return new BaudRateSettings(mVars);
  else
	return new ProtocolSettings(mVars);
}

DIYCSettings *ReadFromEepromSettings::downAction()
{
  return new SaveToEepromSettings(mVars);
}

DIYCSettings *ReadFromEepromSettings::rightAction()
{
  return new EditReadFromEepromSettings(mVars);
}

DIYCSettings *ReadFromEepromSettings::selectAction()
{
  return new EditReadFromEepromSettings(mVars);
}

/*
 * Edit output settings
 */

EditReadFromEepromSettings::EditReadFromEepromSettings(DIYCVars *vars) : DIYCSettings(vars)
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Confirm?");
}

DIYCSettings *EditReadFromEepromSettings::leftAction()
{
  return new ReadFromEepromSettings(mVars);
}

DIYCSettings *EditReadFromEepromSettings::selectAction()
{
  mVars->readFromEeprom();

  return new ReadFromEepromSettings(mVars);
}

EditReadFromEepromSettings::~EditReadFromEepromSettings() { }
