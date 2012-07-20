#include "DIYCVars.h"
#include "EEPROM.h"

DIYCVars::DIYCVars()
{
  mLcd = new Adafruit_RGBLCDShield;
  mLcd->begin(16,2);
  mLcd->print("Hello diyc.com!");

//  packed_t settings;
//  for ( int bytes = 0; bytes < sizeof(packed_t); ++bytes )
//    *((char *)&settings + bytes) = EEPROM.read(bytes);

  packed_t settings = { RENARD, MANUAL, 24, 1, REN_57600, 255, 0 };

  mProtocol = settings.protocol;
  mOutputType = settings.outputType;
  mNumChannels = settings.numChannels;
  mChannel = settings.channel;
  mBaudRate = settings.baudRate;
  mMaxDimming = settings.maxDimming;
  mMinDimming = settings.minDimming;
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

void DIYCVars::saveToEeprom()
{
  packed_t settings;

  settings.protocol = mProtocol;
  settings.outputType = mOutputType;
  settings.numChannels = mNumChannels;
  settings.channel = mChannel;
  settings.baudRate = mBaudRate;
  settings.maxDimming = mMaxDimming;
  settings.minDimming = mMinDimming;

  EEPROM.write(0, sizeof(packed_t));
}

uint8_t DIYCVars::setProtocol(uint8_t protocol)
{
  if ( protocol < 0 || protocol > MAX_PROTOCOLS )
    return -1;
  else
    mProtocol = protocol;
    
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
		case (DMX_250):
			mBaudRate = baud;
			break;
		default:
			mBaudRate = REN_57600;
  }
  
  return mBaudRate;
}

uint8_t DIYCVars::setMaxDimming(uint8_t dimming)
{
	mMaxDimming = dimming;
}

uint8_t DIYCVars::setMinDimming(uint8_t dimming)
{
	mMinDimming = dimming;
}
