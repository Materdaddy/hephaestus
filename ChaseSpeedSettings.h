#ifndef __CHASE_SPEED_SETTINGS_H__
#define __CHASE_SPEED_SETTINGS_H__

#include "DIYCSettings.h"

class ChaseSpeedSettings : public DIYCSettings
{
public:
	ChaseSpeedSettings(DIYCVars *vars);
	~ChaseSpeedSettings() { }

	DIYCSettings *upAction();
	DIYCSettings *rightAction();
	DIYCSettings *downAction();
	DIYCSettings *selectAction();
};

class EditChaseSpeedSettings : public DIYCSettings
{
public:
	EditChaseSpeedSettings(DIYCVars *vars);
	~EditChaseSpeedSettings() { }

	DIYCSettings *upAction();
	DIYCSettings *downAction();
	DIYCSettings *selectAction();

private:
	long mDelay;
};

#endif // __CHASE_SPEED_SETTINGS_H__
