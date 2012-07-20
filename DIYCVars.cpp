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

  packed_t settings = { RENARD, MANUAL, 8, 1, 57600, 50 };

  mProtocol = settings.protocol;
  mOutputType = settings.outputType;
  mNumChannels = settings.numChannels;
  mChannel = settings.channel;
  mBaudRate = settings.baudRate;
  mEventPeriod = settings.eventPeriod;
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

int DIYCVars::saveToEeprom()
{
  packed_t settings;

  settings.protocol = mProtocol;
  settings.outputType = mOutputType;
  settings.numChannels = mNumChannels;
  settings.channel = mChannel;
  settings.baudRate = mBaudRate;
  settings.eventPeriod = mEventPeriod;

  EEPROM.write(0, sizeof(packed_t));
}

uint8_t DIYCVars::setProtocol(uint8_t protocol)
{
  if ( protocol < 0 || protocol > MAX_PROTOCOLS)
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
