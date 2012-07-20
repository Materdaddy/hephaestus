#ifndef __CHANNEL_SETTINGS_H__
#define __CHANNEL_SETTINGS_H__

#include "DIYCSettings.h"

class ChannelSettings : public DIYCSettings
{
public:
  ChannelSettings(DIYCVars *vars);
  ~ChannelSettings() { }

  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
};

class EditChannelSettings : public DIYCSettings
{
public:
  EditChannelSettings(DIYCVars *vars);
  ~EditChannelSettings() { }

  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *selectAction();

private:
  uint8_t mChannel;
};

#endif // __CHANNEL_SETTINGS_H__
