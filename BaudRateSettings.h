#ifndef __BAUD_RATE_SETTINGS_H__
#define __BAUD_RATE_SETTINGS_H__

#include "DIYCSettings.h"

class BaudRateSettings : public DIYCSettings
{
public:
  BaudRateSettings(DIYCVars *vars);
  ~BaudRateSettings() { }

  DIYCSettings *upAction();
  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
};

class EditBaudRateSettings : public DIYCSettings
{
public:
  EditBaudRateSettings(DIYCVars *vars);
  ~EditBaudRateSettings();

  const char *baudRateToString();

  DIYCSettings *leftAction();
  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *selectAction();

private:
  uint8_t mBaudRate;
};

#endif // __BAUD_RATE_SETTINGS_H__
