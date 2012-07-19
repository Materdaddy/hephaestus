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

 packed_t settings = { RENARD, 8, 1, 57600, 50 };

  mProtocol = settings.protocol;
  mNumChannels = settings.numChannels;
  mChannel = settings.channel;
  mBaudRate = settings.baudRate;
  mEventPeriod = settings.eventPeriod;
}

DIYCVars::~DIYCVars() { }

void DIYCVars::printSettings()
{
  mLcd->clear();
  mLcd->print("R@");//TODO
  mLcd->print("56k");//TODO
  mLcd->print(" C:");
  mLcd->print(mChannel);
  mLcd->print("/");
  mLcd->print(mNumChannels);
}

int DIYCVars::saveToEeprom()
{
  packed_t settings;

  settings.protocol = mProtocol;
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
