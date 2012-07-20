#ifndef __SAVE_TO_EEPROM_SETTINGS_H__
#define __SAVE_TO_EEPROM_SETTINGS_H__

#include "DIYCSettings.h"

class SaveToEepromSettings : public DIYCSettings
{
public:
  SaveToEepromSettings(DIYCVars *vars);
  ~SaveToEepromSettings() { }

  DIYCSettings *upAction();
  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
};

class EditSaveToEepromSettings : public DIYCSettings
{
public:
  EditSaveToEepromSettings(DIYCVars *vars);
  ~EditSaveToEepromSettings();

  DIYCSettings *leftAction();
  DIYCSettings *selectAction();
};

#endif // __SAVE_TO_EEPROM_SETTINGS_H__
