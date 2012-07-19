#ifndef __DIYC_TESTER_H__
#define __DIYC_TESTER_H__

#include <Adafruit_RGBLCDShield.h>
#include "../EEPROM/EEPROM.h"

enum protocols {
  RENARD,
  DMX,
  MAX_PROTOCOLS
};

typedef struct packed_s
{
  uint8_t protocol;
  uint8_t numChannels;
  uint8_t channel;
  uint8_t baudRate;
  uint8_t eventPeriod;
} packed_t;

class DIYCVars
{
public:
  DIYCVars()
  {
    mLcd = new Adafruit_RGBLCDShield;
    mLcd->begin(16,2);
    mLcd->print("Hello diyc.com!");

//    packed_t settings;
//    for ( int bytes = 0; bytes < sizeof(packed_t); ++bytes )
//    {
//      uint8_t *ptr = (uint8_t *)&settings + bytes;
//      *ptr = EEPROM.read(bytes);
//    }

    packed_t settings = { RENARD, 8, 1, 57600, 50 };

    mProtocol = settings.protocol;
    mNumChannels = settings.numChannels;
    mChannel = settings.channel;
    mBaudRate = settings.baudRate;
    mEventPeriod = settings.eventPeriod;
  }
  ~DIYCVars() { }

  void printSettings()
  {
    mLcd->clear();
    mLcd->print("R@");//TODO
    mLcd->print("56k");//TODO
    mLcd->print(" C:");
    mLcd->print(mChannel);
    mLcd->print("/");
    mLcd->print(mNumChannels);
  }

  int saveToEeprom()
  {
    packed_t settings;

    settings.protocol = mProtocol;
    settings.numChannels = mNumChannels;
    settings.channel = mChannel;
    settings.baudRate = mBaudRate;
    settings.eventPeriod = mEventPeriod;
    
    EEPROM.write(0, sizeof(packed_t));
  }

  // getters
  uint8_t getProtocol() { return mProtocol; }
  uint8_t getNumChannels() { return mNumChannels; }
  uint8_t getChannel() { return mChannel; }
  uint8_t getBaud() { return mBaudRate; }
  uint8_t getEventPeriod() { return mEventPeriod; }
  Adafruit_RGBLCDShield *getLcd() { return mLcd; }

  // setters
  uint8_t setProtocol(uint8_t protocol);
  uint8_t setNumChannels(uint8_t channels);
  uint8_t setChannel(uint8_t channel);
  uint8_t setBaudRate(uint8_t baud);
  uint8_t setEventPeriod(uint8_t eperiod);

private:
  uint8_t mProtocol;
  uint8_t mNumChannels;
  uint8_t mChannel;
  uint8_t mBaudRate;
  uint8_t mEventPeriod;

  // The shield uses the I2C SCL and SDA pins. On classic Arduinos
  // this is Analog 4 and 5 so you can't use those for analogRead() anymore
  // However, you can connect other I2C sensors to the I2C bus and share
  // the I2C bus.
  Adafruit_RGBLCDShield *mLcd;
};

class DIYCSettings
{
public:
  DIYCSettings(DIYCVars *vars) : mVars(vars) { };
  virtual ~DIYCSettings() = 0;

  DIYCVars *getVars() { return mVars; }

  virtual DIYCSettings *leftAction() { return this; }
  virtual DIYCSettings *rightAction() { return this; }
  virtual DIYCSettings *upAction() { return this; }
  virtual DIYCSettings *downAction() { return this; }
  virtual DIYCSettings *selectAction() { return this; }

protected:
  DIYCVars *mVars;
};

class ChannelSettings : public DIYCSettings
{
public:
  ChannelSettings(DIYCVars *vars);
  ~ChannelSettings() { }

  DIYCSettings *rightAction();
  DIYCSettings *selectAction();
};

class EditChannelSettings : public DIYCSettings
{
public:
  EditChannelSettings(DIYCVars *vars);
  ~EditChannelSettings() { }

  DIYCSettings *upAction();
  DIYCSettings *downAction();
  DIYCSettings *selectAction();
  
private:
  uint8_t mChannel;
};

#endif // __DIYC_TESTER_H__
