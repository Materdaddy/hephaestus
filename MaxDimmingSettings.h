#ifndef __MAX_DIMMING_SETTINGS_H__
#define __MAX_DIMMING_SETTINGS_H__

#include "DIYCSettings.h"

class MaxDimmingSettings : public DIYCSettings
{
public:
	MaxDimmingSettings(DIYCVars *vars);
	~MaxDimmingSettings() { }

	DIYCSettings *upAction();
	DIYCSettings *downAction();
	DIYCSettings *rightAction();
	DIYCSettings *selectAction();
};

class EditMaxDimmingSettings : public DIYCSettings
{
public:
	EditMaxDimmingSettings(DIYCVars *vars);
	~EditMaxDimmingSettings();

	DIYCSettings *leftAction();
	DIYCSettings *upAction();
	DIYCSettings *downAction();
	DIYCSettings *selectAction();

private:
	uint8_t mMaxDimming;
};

#endif // __MAX_DIMMING_SETTINGS_H__
