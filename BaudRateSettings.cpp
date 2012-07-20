#include "BaudRateSettings.h"
#include "ProtocolSettings.h"
#include "ReadFromEepromSettings.h"

BaudRateSettings::BaudRateSettings(DIYCVars *vars) : DIYCSettings(vars)
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Baud Rate ->");
}

DIYCSettings *BaudRateSettings::upAction()
{
  return new ProtocolSettings(mVars);
}

DIYCSettings *BaudRateSettings::downAction()
{
  return new ReadFromEepromSettings(mVars);
}

DIYCSettings *BaudRateSettings::rightAction()
{
  return new EditBaudRateSettings(mVars);
}

DIYCSettings *BaudRateSettings::selectAction()
{
  return new EditBaudRateSettings(mVars);
}

/*
 * Edit output settings
 */

const char *EditBaudRateSettings::baudRateToString()
{
  switch (mBaudRate)
  {
    case ( REN_19200 ):
    	return "19200";
    case ( REN_38400 ):
    	return "38400";
    case ( REN_57600 ):
    	return "57600";
    case ( REN_115200 ):
    	return "115200";
    case ( DMX_250 ):
    	return "250k";
	default:
		return "ERROR!";
  }
}

EditBaudRateSettings::EditBaudRateSettings(DIYCVars *vars) : DIYCSettings(vars), mBaudRate(mVars->getBaudRate())
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(baudRateToString());
}

DIYCSettings *EditBaudRateSettings::downAction()
{
  if ( mBaudRate > 0 && mVars->getProtocol() != DMX )
    --mBaudRate;

  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(baudRateToString());

  return this;
}

DIYCSettings *EditBaudRateSettings::upAction()
{
  // NOTE this max check with "+2" is because we don't want to allow DMX baud here
  if ( mBaudRate+2 < MAX_BAUD_RATES && mVars->getProtocol() != DMX )
    ++mBaudRate;

  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(baudRateToString());

  return this;
}

DIYCSettings *EditBaudRateSettings::leftAction()
{
  return new BaudRateSettings(mVars);
}

DIYCSettings *EditBaudRateSettings::selectAction()
{
  mVars->setBaudRate(mBaudRate);
  return new BaudRateSettings(mVars);
}

EditBaudRateSettings::~EditBaudRateSettings() { }
