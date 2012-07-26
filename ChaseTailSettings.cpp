#include "ChaseSpeedSettings.h"
#include "NumChannelsSettings.h"
#include "ChaseTailSettings.h"

ChaseTailSettings::ChaseTailSettings(DIYCVars *vars) : DIYCSettings(vars)
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Chase Tail ->");
}

DIYCSettings *ChaseTailSettings::upAction()
{
	return new ChaseSpeedSettings(mVars);
}

DIYCSettings *ChaseTailSettings::rightAction()
{
	return new EditChaseTailSettings(mVars);
}

DIYCSettings *ChaseTailSettings::downAction()
{
	return new NumChannelsSettings(mVars);
}

DIYCSettings *ChaseTailSettings::selectAction()
{
	return new EditChaseTailSettings(mVars);
}

EditChaseTailSettings::EditChaseTailSettings(DIYCVars *vars) : DIYCSettings(vars), mTail(mVars->getTail())
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Tail: ");
	mVars->getLcd()->print(mTail);
}

DIYCSettings *EditChaseTailSettings::downAction()
{
	if ( mTail > 0 )
		--mTail;
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Tail: ");
	mVars->getLcd()->print(mTail);

	return this;
}

DIYCSettings *EditChaseTailSettings::upAction()
{
	if ( mTail < MAX_TAIL )
		++mTail;
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Tail: ");
	mVars->getLcd()->print(mTail);

	return this;
}

DIYCSettings *EditChaseTailSettings::selectAction()
{
	mVars->setTail(mTail);
	return new ChaseTailSettings(mVars);
}
