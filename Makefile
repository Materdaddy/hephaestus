BOARD_TAG     = uno
ARDUINO_PORT  = /dev/ttyACM0
ARDUINO_LIBS  = EEPROM Serial Adafruit_RGBLCDShield Wire Wire/utility
ARDUINO_DIR   = /home/mmrosko/Dropbox/AVR/arduino-1.0.1-64
ARDMK_DIR     = /home/mmrosko/Projects/Arduino-Makefile

AVRDUDE       = avrdude
AVRDUDE_CONF  = /etc/avrdude.conf
AVR_TOOLS_DIR = /usr

include $(ARDMK_DIR)/arduino-mk/Arduino.mk
