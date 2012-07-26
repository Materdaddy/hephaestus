#ifndef __DIYC_SETTINGS_H__
#define __DIYC_SETTINGS_H__

#include "DIYCVars.h"

class DIYCSettings
{
public:
	DIYCSettings(DIYCVars *vars) : mVars(vars) { };
	virtual ~DIYCSettings() = 0;

	DIYCVars *getVars() { return mVars; }

	virtual DIYCSettings *leftAction() { return this; }
	virtual DIYCSettings *rightAction() { return this; }
	virtual DIYCSettings *upAction() { return this; }
	virtual DIYCSettings *downAction() { return this; }
	virtual DIYCSettings *selectAction() { return this; }

protected:
	DIYCVars *mVars;
};

#endif // __DIYC_SETTINGS_H__
