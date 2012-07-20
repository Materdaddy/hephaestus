#ifndef __DIYC_VARS_H__
#define __DIYC_VARS_H__

#include <Adafruit_RGBLCDShield.h>

enum protocols {
  RENARD,
  DMX,
  MAX_PROTOCOLS
};

enum outputs {
  MANUAL,
  CHASE,
  PATTERN,
  MAX_OUTPUT_TYPES
};

enum bauds {
	REN_19200,
	REN_38400,
	REN_57600,
	REN_115200,
	DMX_250,
	MAX_BAUD_RATES
};

typedef struct packed_s
{
  uint8_t protocol;
  uint8_t outputType;
  uint8_t numChannels;
  uint8_t channel;
  uint8_t baudRate;
  uint8_t eventPeriod;
} packed_t;

class DIYCVars
{
public:
  DIYCVars();
  ~DIYCVars();

  void printSettings();
  int saveToEeprom();

  // getters
  uint8_t getProtocol() { return mProtocol; }
  uint8_t getOutputType() { return mOutputType; }
  uint8_t getNumChannels() { return mNumChannels; }
  uint8_t getChannel() { return mChannel; }
  uint8_t getBaud() { return mBaudRate; }
  uint8_t getEventPeriod() { return mEventPeriod; }
  Adafruit_RGBLCDShield *getLcd() { return mLcd; }

  // setters
  uint8_t setProtocol(uint8_t protocol);
  uint8_t setOutputType(uint8_t output);
  uint8_t setNumChannels(uint8_t channels);
  uint8_t setChannel(uint8_t channel);
  uint8_t setBaudRate(uint8_t baud);
  uint8_t setEventPeriod(uint8_t eperiod);

private:
  uint8_t mProtocol;
  uint8_t mOutputType;
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

#endif // __DIYC_VARS_H__
