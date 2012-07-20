#ifndef __OUTPUT_SETTINGS_H__
#define __OUTPUT_SETTINGS_H__

#include "DIYCSettings.h"

class OutputSettings : public DIYCSettings
{
public:
  OutputSettings(DIYCVars *vars);
  ~OutputSettings() { }

  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
  DIYCSettings *downAction();
};

class EditOutputSettings : public DIYCSettings
{
public:
  EditOutputSettings(DIYCVars *vars);
  ~EditOutputSettings() { }

  const char *outputTypeToString();

  DIYCSettings *leftAction();
  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *selectAction();

private:
  uint8_t mOutputType;
};

#endif // __OUTPUT_SETTINGS_H__
