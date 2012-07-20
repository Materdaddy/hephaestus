#ifndef __MIN_DIMMING_SETTINGS_H__
#define __MIN_DIMMING_SETTINGS_H__

#include "DIYCSettings.h"

class MinDimmingSettings : public DIYCSettings
{
public:
  MinDimmingSettings(DIYCVars *vars);
  ~MinDimmingSettings() { }

  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
};

class EditMinDimmingSettings : public DIYCSettings
{
public:
  EditMinDimmingSettings(DIYCVars *vars);
  ~EditMinDimmingSettings();

  DIYCSettings *leftAction();
  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *selectAction();

private:
  uint8_t mMinDimming;
};

#endif // __MIN_DIMMING_SETTINGS_H__
