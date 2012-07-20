#include "OutputSettings.h"
#include "ChannelSettings.h"

OutputSettings::OutputSettings(DIYCVars *vars) : DIYCSettings(vars)
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Output Type ->");
}

DIYCSettings *OutputSettings::downAction()
{
  //TODO: switch/case based on output type
  return new ChannelSettings(mVars);
}

DIYCSettings *OutputSettings::rightAction()
{
  return new EditOutputSettings(mVars);
}

DIYCSettings *OutputSettings::selectAction()
{
  return new EditOutputSettings(mVars);
}

/*
 * Edit output settings
 */

const char *EditOutputSettings::outputTypeToString()
{
	switch (mVars->getOutputType())
	{
		case MANUAL:
		  return "Manual";
		case CHASE:
		  return "Chase";
		case PATTERN:
		  return "Pattern";
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
  if ( mOutputType >= 0 )
    --mOutputType;

  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(outputTypeToString());

  return this;
}

DIYCSettings *EditOutputSettings::upAction()
{
  if ( mOutputType < MAX_OUTPUT_TYPES )
    ++mOutputType;

  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print(outputTypeToString());

  return this;
}

DIYCSettings *EditOutputSettings::selectAction()
{
  mVars->setOutputType(mOutputType);
  return new OutputSettings(mVars);
}
