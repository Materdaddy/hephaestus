#ifndef __READ_FROM_EEPROM_SETTINGS_H__
#define __READ_FROM_EEPROM_SETTINGS_H__

#include "DIYCSettings.h"

class ReadFromEepromSettings : public DIYCSettings
{
public:
  ReadFromEepromSettings(DIYCVars *vars);
  ~ReadFromEepromSettings() { }

  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
};

class EditReadFromEepromSettings : public DIYCSettings
{
public:
  EditReadFromEepromSettings(DIYCVars *vars);
  ~EditReadFromEepromSettings();

  DIYCSettings *leftAction();
  DIYCSettings *selectAction();
};

#endif // __READ_FROM_EEPROM_SETTINGS_H__
