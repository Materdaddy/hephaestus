#include "NumChannelsSettings.h"
#include "ChannelSettings.h"
#include "MaxDimmingSettings.h"

NumChannelsSettings::NumChannelsSettings(DIYCVars *vars) : DIYCSettings(vars)
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("# Of Channels ->");
}

DIYCSettings *NumChannelsSettings::upAction()
{
	switch (mVars->getOutputType())
	{
		case (MANUAL):
			return new ChannelSettings(mVars);
//		case (CHASE):
//			return new ChaseSettings(mVars);
//		case (PATTERN):
//			return new OutputPatternSettings(mVars);
	}

	return this;
}

DIYCSettings *NumChannelsSettings::downAction()
{
	return new MaxDimmingSettings(mVars);
}

DIYCSettings *NumChannelsSettings::rightAction()
{
	return new EditNumChannelsSettings(mVars);
}

DIYCSettings *NumChannelsSettings::selectAction()
{
	return new EditNumChannelsSettings(mVars);
}

EditNumChannelsSettings::EditNumChannelsSettings(DIYCVars *vars) : DIYCSettings(vars), mNumChannels(mVars->getNumChannels())
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(mNumChannels);
}

DIYCSettings *EditNumChannelsSettings::downAction()
{
	if ( mNumChannels > 1 )
		--mNumChannels;

	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(mNumChannels);

	return this;
}

DIYCSettings *EditNumChannelsSettings::upAction()
{
	if ( mNumChannels < mVars->maxChannelsThisBaud() )
		++mNumChannels;

	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(mNumChannels);

	return this;
}

DIYCSettings *EditNumChannelsSettings::leftAction()
{
	return new NumChannelsSettings(mVars);
}

DIYCSettings *EditNumChannelsSettings::selectAction()
{
	mVars->setNumChannels(mNumChannels);
	return new NumChannelsSettings(mVars);
}

EditNumChannelsSettings::~EditNumChannelsSettings() { }
