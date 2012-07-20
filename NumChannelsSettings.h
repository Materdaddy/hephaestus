#ifndef __NUM_CHANNEL_SETTINGS_H__
#define __NUM_CHANNEL_SETTINGS_H__

#include "DIYCSettings.h"

class NumChannelsSettings : public DIYCSettings
{
public:
  NumChannelsSettings(DIYCVars *vars);
  ~NumChannelsSettings() { }

  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
};

class EditNumChannelsSettings : public DIYCSettings
{
public:
  EditNumChannelsSettings(DIYCVars *vars);
  ~EditNumChannelsSettings();

  DIYCSettings *leftAction();
  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *selectAction();

private:
  uint8_t mNumChannels;
};

#endif // __NUM_CHANNEL_SETTINGS_H__
