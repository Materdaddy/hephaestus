#ifndef __DIYC_VARS_H__
#define __DIYC_VARS_H__

#include <Adafruit_RGBLCDShield.h>

// These #defines make it easy to set the backlight color
#define OFF 0x0
#define RED 0x1
#define GREEN 0x2
#define YELLOW 0x3
#define BLUE 0x4
#define VIOLET 0x5
#define TEAL 0x6
#define WHITE 0x7

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
	uint8_t baudRateRenard;
	uint8_t maxDimming;
	uint8_t minDimming;
	uint8_t tail;
	long delay;
} packed_t;

#define MAX_TAIL 6
#define MAX_DELAY 10000

class DIYCVars
{
public:
	DIYCVars();
	~DIYCVars();

	void printSettings();
	void readFromEeprom();
	void saveToEeprom();

	uint16_t maxChannelsThisBaud();

	// getters
	uint8_t getProtocol() { return mProtocol; }
	uint8_t getOutputType() { return mOutputType; }
	uint16_t getNumChannels() { return mNumChannels; }
	uint16_t getChannel() { return mChannel; }
	uint8_t getBaudRate() { return mBaudRate; }
	uint8_t getMaxDimming() { return mMaxDimming; }
	uint8_t getMinDimming() { return mMinDimming; }
	uint8_t getTail() { return mTail; }
	long getDelay() { return mDelay; }
	Adafruit_RGBLCDShield *getLcd() { return mLcd; }

	// setters
	uint8_t setProtocol(uint8_t protocol);
	uint8_t setOutputType(uint8_t output);
	uint16_t setNumChannels(uint16_t channels);
	uint16_t setChannel(uint16_t channel);
	uint8_t setBaudRate(uint8_t baud);
	uint8_t setMaxDimming(uint8_t dimming);
	uint8_t setMinDimming(uint8_t dimming);
	void setBaudRateDMX() { setBaudRate(DMX_250); }
	void setBaudRateRenard();
	uint8_t setTail(uint8_t tail);
	long setDelay(long delay);

	void sendData();

private:
	// Variables saved in EEPROM
	uint8_t mProtocol;
	uint8_t mOutputType;
	uint16_t mNumChannels;
	uint16_t mChannel;
	uint8_t mBaudRate;
	uint8_t mBaudRateRenard;
	uint8_t mMaxDimming;
	uint8_t mMinDimming;
	uint8_t mTail;
	long mDelay;

	// Variables not saved in EEPROM
	long mLast;
	uint16_t mCurrentChaseChannel;

	// The shield uses the I2C SCL and SDA pins. On classic Arduinos
	// this is Analog 4 and 5 so you can't use those for analogRead() anymore
	// However, you can connect other I2C sensors to the I2C bus and share
	// the I2C bus.
	Adafruit_RGBLCDShield *mLcd;
};

#endif // __DIYC_VARS_H__
