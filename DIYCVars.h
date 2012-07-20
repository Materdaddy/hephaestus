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
  uint16_t numChannels;
  uint16_t channel;
  uint8_t baudRate;
  uint8_t maxDimming;
  uint8_t minDimming;
} packed_t;

class DIYCVars
{
public:
  DIYCVars();
  ~DIYCVars();

  void printSettings();
  void saveToEeprom();

  uint16_t maxChannelsThisBaud();

  // getters
  uint8_t getProtocol() { return mProtocol; }
  uint8_t getOutputType() { return mOutputType; }
  uint16_t getNumChannels() { return mNumChannels; }
  uint16_t getChannel() { return mChannel; }
  uint8_t getBaud() { return mBaudRate; }
  uint8_t getMaxDimming() { return mMaxDimming; }
  uint8_t getMinDimming() { return mMinDimming; }
  Adafruit_RGBLCDShield *getLcd() { return mLcd; }

  // setters
  uint8_t setProtocol(uint8_t protocol);
  uint8_t setOutputType(uint8_t output);
  uint16_t setNumChannels(uint16_t channels);
  uint16_t setChannel(uint16_t channel);
  uint8_t setBaudRate(uint8_t baud);
  uint8_t setMaxDimming(uint8_t dimming);
  uint8_t setMinDimming(uint8_t dimming);

private:
  uint8_t mProtocol;
  uint8_t mOutputType;
  uint16_t mNumChannels;
  uint16_t mChannel;
  uint8_t mBaudRate;
  uint8_t mMaxDimming;
  uint8_t mMinDimming;

  // The shield uses the I2C SCL and SDA pins. On classic Arduinos
  // this is Analog 4 and 5 so you can't use those for analogRead() anymore
  // However, you can connect other I2C sensors to the I2C bus and share
  // the I2C bus.
  Adafruit_RGBLCDShield *mLcd;
};

#endif // __DIYC_VARS_H__
