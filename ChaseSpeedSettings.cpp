#include "ChaseSpeedSettings.h"
#include "OutputSettings.h"
#include "ChaseTailSettings.h"

ChaseSpeedSettings::ChaseSpeedSettings(DIYCVars *vars) : DIYCSettings(vars)
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Chase Speed ->");
}

DIYCSettings *ChaseSpeedSettings::upAction()
{
	return new OutputSettings(mVars);
}

DIYCSettings *ChaseSpeedSettings::rightAction()
{
	return new EditChaseSpeedSettings(mVars);
}

DIYCSettings *ChaseSpeedSettings::downAction()
{
	return new ChaseTailSettings(mVars);
}

DIYCSettings *ChaseSpeedSettings::selectAction()
{
	return new EditChaseSpeedSettings(mVars);
}

EditChaseSpeedSettings::EditChaseSpeedSettings(DIYCVars *vars) : DIYCSettings(vars), mDelay(mVars->getDelay())
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Speed: ");
	mVars->getLcd()->print(mDelay);
}

DIYCSettings *EditChaseSpeedSettings::downAction()
{
	if ( mDelay > 1000 && mDelay <= MAX_DELAY )
		mDelay -= 1000;
	else if ( mDelay > 500 && mDelay <= 1000 )
		mDelay -= 100;
	else if ( mDelay > 100 && mDelay <= 500 )
		mDelay -= 50;
	else if ( mDelay-20 >= 0 && mDelay <= 100 )
		mDelay -= 20;

	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Speed: ");
	mVars->getLcd()->print(mDelay);

	return this;
}

DIYCSettings *EditChaseSpeedSettings::upAction()
{
	if ( mDelay >= 0 && mDelay + 20 <= 100 )
		mDelay += 20;
	else if ( mDelay >= 100 && mDelay + 50 <= 500 )
		mDelay += 50;
	else if ( mDelay >= 500 && mDelay + 100 <= 1000 )
		mDelay += 100;
	else if ( mDelay >= 1000 && mDelay + 1000 <= MAX_DELAY )
		mDelay += 1000;

	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Speed: ");
	mVars->getLcd()->print(mDelay);

	return this;
}

DIYCSettings *EditChaseSpeedSettings::selectAction()
{
	mVars->setDelay(mDelay);
	return new ChaseSpeedSettings(mVars);
}
