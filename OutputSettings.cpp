#include "OutputSettings.h"
#include "ChannelSettings.h"
#include "ChaseSpeedSettings.h"
#include "NumChannelsSettings.h"

OutputSettings::OutputSettings(DIYCVars *vars) : DIYCSettings(vars)
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Output Type ->");
}

DIYCSettings *OutputSettings::downAction()
{
	switch (mVars->getOutputType())
	{
		case (MANUAL):
			return new ChannelSettings(mVars);
		case (CHASE):
			return new ChaseSpeedSettings(mVars);
//		case (PATTERN):
//			return new OutputPatternSettings(mVars);
		case (ALL_ON):
		case (ALL_OFF):
			return new NumChannelsSettings(mVars);
	}

	return this;
}

DIYCSettings *OutputSettings::rightAction()
{
	return new EditOutputSettings(mVars);
}

DIYCSettings *OutputSettings::selectAction()
{
	return new EditOutputSettings(mVars);
}

const char *EditOutputSettings::outputTypeToString()
{
	switch (mOutputType)
	{
		case MANUAL:
			return "Manual";
		case CHASE:
			return "Chase";
		case PATTERN:
			return "Pattern";
		case ALL_ON:
			return "All On";
		case ALL_OFF:
			return "All Off";
		default:
			return "ERROR!";
	}
}

EditOutputSettings::EditOutputSettings(DIYCVars *vars) : DIYCSettings(vars), mOutputType(mVars->getOutputType())
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(outputTypeToString());
}

DIYCSettings *EditOutputSettings::downAction()
{
	if ( mOutputType > 0 )
		--mOutputType;

	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(outputTypeToString());

	return this;
}

DIYCSettings *EditOutputSettings::upAction()
{
	if ( mOutputType+1 < MAX_OUTPUT_TYPES )
		++mOutputType;

	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(outputTypeToString());

	return this;
}

DIYCSettings *EditOutputSettings::leftAction()
{
	return new OutputSettings(mVars);
}

DIYCSettings *EditOutputSettings::selectAction()
{
	mVars->setOutputType(mOutputType);
	return new OutputSettings(mVars);
}

EditOutputSettings::~EditOutputSettings() { }
