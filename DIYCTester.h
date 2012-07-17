#ifndef __DIYC_TESTER_H__
#define __DIYC_TESTER_H__

#include <Adafruit_RGBLCDShield.h>

enum {
  RENARD,
  DMX,
  MAX_PROTOCOLS
} protocols;

class DIYCVars
{
public:
  DIYCVars() : mProtocol(RENARD), mNumChannels(256), mCurChannel(1)
  {
    mLcd = new Adafruit_RGBLCDShield;
    mLcd->begin(16,2);
    mLcd->print("Hello diyc.com!");
  }
  ~DIYCVars() { }
  
  Adafruit_RGBLCDShield *getLcd() { return mLcd; }

private:
  int mProtocol;
  int mNumChannels;
  int mCurChannel;

  // The shield uses the I2C SCL and SDA pins. On classic Arduinos
  // this is Analog 4 and 5 so you can't use those for analogRead() anymore
  // However, you can connect other I2C sensors to the I2C bus and share
  // the I2C bus.
  Adafruit_RGBLCDShield *mLcd;
};

#endif // __DIYC_TESTER_H__
