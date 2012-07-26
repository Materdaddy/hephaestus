#ifndef __CHASE_TAIL_SETTINGS_H__
#define __CHASE_TAIL_SETTINGS_H__

#include "DIYCSettings.h"

class ChaseTailSettings : public DIYCSettings
{
public:
	ChaseTailSettings(DIYCVars *vars);
	~ChaseTailSettings() { }

	DIYCSettings *upAction();
	DIYCSettings *rightAction();
	DIYCSettings *downAction();
	DIYCSettings *selectAction();
};

class EditChaseTailSettings : public DIYCSettings
{
public:
	EditChaseTailSettings(DIYCVars *vars);
	~EditChaseTailSettings() { }

	DIYCSettings *upAction();
	DIYCSettings *downAction();
	DIYCSettings *selectAction();

private:
	uint8_t mTail;
};

#endif // __CHASE_TAIL_SETTINGS_H__
