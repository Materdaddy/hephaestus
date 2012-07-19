#include "DIYCTester.h"
#include <Adafruit_RGBLCDShield.h>

uint8_t DIYCVars::setProtocol(uint8_t protocol)
{
  if ( protocol < 0 || protocol > MAX_PROTOCOLS)
    return -1;
  else
    mProtocol = protocol;
    
  return mProtocol;
}

uint8_t DIYCVars::setNumChannels(uint8_t channels)
{
  // TODO: Determine update period/channels max count based on protocol for bounds checking
  if ( channels > 1 )
    mNumChannels = channels;

  return mNumChannels;
}

uint8_t DIYCVars::setChannel(uint8_t channel)
{
  if ( channel >= 1 && channel <= mNumChannels )
    mChannel = channel;
  
  return mChannel;
}

uint8_t DIYCVars::setBaudRate(uint8_t baud)
{
  // TODO: Some form of checking
  mBaudRate = baud;
  
  return mBaudRate;
}

uint8_t DIYCVars::setEventPeriod(uint8_t eperiod)
{
  // TODO: Some form of checking
  mEventPeriod = eperiod;
  
  return mEventPeriod;
}

DIYCSettings::~DIYCSettings() { }

ChannelSettings::ChannelSettings(DIYCVars *vars) : DIYCSettings(vars)
{
  mVars->printSettings();
  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("Edit Channel ->");
}

/*
DIYCSettings *ChannelSettings::downAction()
{
  return new OutputTypeSettings;
}
*/

DIYCSettings *ChannelSettings::rightAction()
{
  return new EditChannelSettings(mVars);
}

DIYCSettings *ChannelSettings::selectAction()
{
  return new EditChannelSettings(mVars);
}

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
