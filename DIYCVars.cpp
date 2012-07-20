#include "DIYCVars.h"
#include "EEPROM.h"

#define CONFIG_START 32

DIYCVars::DIYCVars() : mProtocol(RENARD),
					   mOutputType(MANUAL),
					   mNumChannels(24),
					   mChannel(1),
					   mBaudRate(REN_57600),
					   mBaudRateRenard(REN_57600),
					   mMaxDimming(255),
					   mMinDimming(0)
{
  mLcd = new Adafruit_RGBLCDShield;
  mLcd->begin(16,2);
  mLcd->print("Hello diyc.com!");

  readFromEeprom();
}

DIYCVars::~DIYCVars() { }

void DIYCVars::printSettings()
{
  mLcd->clear();
  switch (mProtocol)
  {
    case ( RENARD ):
    {
      mLcd->print("R@");
      break;
    }
    case ( DMX ):
    {
      mLcd->print("D@");
      break;
    }
  }
  switch (mBaudRate)
  {
    case ( REN_19200 ):
    {
      mLcd->print("19k ");
      break;
    }
    case ( REN_38400 ):
    {
      mLcd->print("38k ");
      break;
    }
    case ( REN_57600 ):
    {
      mLcd->print("56k ");
      break;
    }
    case ( REN_115200 ):
    {
      mLcd->print("115k ");
      break;
    }
    case ( DMX_250 ):
    {
      mLcd->print("250k ");
      break;
    }
  }
  switch (mOutputType)
  {
    case ( MANUAL ):
    {
      mLcd->print("M:");
      mLcd->print(mChannel);
      mLcd->print("/");
      mLcd->print(mNumChannels);
      break;
    }
    case ( CHASE ):
    {
      mLcd->print("Chase");
      break;
    }
    case ( PATTERN ):
    {
      mLcd->print("Pattern");
      break;
    }
  }
}

void DIYCVars::readFromEeprom()
{
  packed_t settings;
  for ( uint8_t bytes = 0; bytes < sizeof(packed_t); ++bytes )
    *((char *)&settings + bytes) = EEPROM.read(CONFIG_START + bytes);

  setOutputType(settings.outputType);
  setNumChannels(settings.numChannels);
  setChannel(settings.channel);
  setBaudRate(settings.baudRateRenard);
  // NOTE: We set protocol after baud rate soas to
  // set the baud based on renard, and overwrite
  // with dmx if in that mode
  setProtocol(settings.protocol);
  setMaxDimming(settings.maxDimming);
  setMinDimming(settings.minDimming);
}

void DIYCVars::saveToEeprom()
{
  packed_t settings;

  settings.protocol = mProtocol;
  settings.outputType = mOutputType;
  settings.numChannels = mNumChannels;
  settings.channel = mChannel;
  settings.baudRate = mBaudRate;
  settings.baudRateRenard = mBaudRateRenard;
  settings.maxDimming = mMaxDimming;
  settings.minDimming = mMinDimming;

  for ( uint8_t bytes = 0; bytes < sizeof(packed_t); ++bytes )
    EEPROM.write(CONFIG_START + bytes, *((char*)&settings + bytes));
}

uint8_t DIYCVars::setProtocol(uint8_t protocol)
{
  if ( protocol > 0 && protocol < MAX_PROTOCOLS )
    mProtocol = protocol;

  if ( protocol == DMX )
    setBaudRateDMX();
    
  return mProtocol;
}

uint8_t DIYCVars::setOutputType(uint8_t output)
{
  if ( output >= 0 && output <= MAX_OUTPUT_TYPES )
    mOutputType = output;

  return mOutputType;
}

uint16_t DIYCVars::maxChannelsThisBaud()
{
	switch (mBaudRate)
	{
		case (REN_19200):
			return 190;
		case (REN_38400):
			return 382;
		case (REN_57600):
			return 574;
		case (REN_115200):
			return 1150;
		case (DMX_250):
			return 512;
	}
	return 0;
}

uint16_t DIYCVars::setNumChannels(uint16_t channels)
{
  if ( channels >= 1 && channels <= maxChannelsThisBaud() )
    mNumChannels = channels;

  if ( mChannel > mNumChannels )
	  mChannel = mNumChannels;

  return mNumChannels;
}

uint16_t DIYCVars::setChannel(uint16_t channel)
{
  if ( channel >= 1 && channel <= mNumChannels )
    mChannel = channel;
  
  return mChannel;
}

uint8_t DIYCVars::setBaudRate(uint8_t baud)
{
  switch (baud)
  {
		case (REN_19200):
		case (REN_38400):
		case (REN_57600):
		case (REN_115200):
		    mBaudRateRenard = baud;
		case (DMX_250):
			mBaudRate = baud;
			break;
		default:
			mBaudRate = REN_57600;
  }
  
  return mBaudRate;
}

void DIYCVars::setBaudRateRenard()
{
  setBaudRate(mBaudRateRenard);
}

uint8_t DIYCVars::setMaxDimming(uint8_t dimming)
{
	mMaxDimming = dimming;
}

uint8_t DIYCVars::setMinDimming(uint8_t dimming)
{
	mMinDimming = dimming;
}
