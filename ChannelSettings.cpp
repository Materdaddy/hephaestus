#include "ChannelSettings.h"
#include "OutputSettings.h"
#include "NumChannelsSettings.h"

ChannelSettings::ChannelSettings(DIYCVars *vars) : DIYCSettings(vars)
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Edit Channel ->");
}

DIYCSettings *ChannelSettings::upAction()
{
  return new OutputSettings(mVars);
}

DIYCSettings *ChannelSettings::rightAction()
{
  return new EditChannelSettings(mVars);
}

DIYCSettings *ChannelSettings::downAction()
{
  return new NumChannelsSettings(mVars);
}

DIYCSettings *ChannelSettings::selectAction()
{
  return new EditChannelSettings(mVars);
}

/*
 * Edit channel settings
 */

EditChannelSettings::EditChannelSettings(DIYCVars *vars) : DIYCSettings(vars), mChannel(mVars->getChannel())
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Channel: ");
  mVars->getLcd()->print(mChannel);
}

DIYCSettings *EditChannelSettings::downAction()
{
  if ( mChannel > 1 )
    --mChannel;
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Channel: ");
  mVars->getLcd()->print(mChannel);

  return this;
}

DIYCSettings *EditChannelSettings::upAction()
{
  if ( mChannel < mVars->getNumChannels() )
    ++mChannel;
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Channel: ");
  mVars->getLcd()->print(mChannel);

  return this;
}

DIYCSettings *EditChannelSettings::selectAction()
{
  mVars->setChannel(mChannel);
  return new ChannelSettings(mVars);
}
