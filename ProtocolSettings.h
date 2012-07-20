#ifndef __PROTOCOL_SETTINGS_H__
#define __PROTOCOL_SETTINGS_H__

#include "DIYCSettings.h"

class ProtocolSettings : public DIYCSettings
{
public:
  ProtocolSettings(DIYCVars *vars);
  ~ProtocolSettings() { }

  DIYCSettings *upAction();
  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
};

class EditProtocolSettings : public DIYCSettings
{
public:
  EditProtocolSettings(DIYCVars *vars);
  ~EditProtocolSettings();

  const char *protocolToString();

  DIYCSettings *leftAction();
  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *selectAction();

private:
  uint8_t mProtocol;
};

#endif // __PROTOCOL_SETTINGS_H__
