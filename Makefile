BOARD_TAG            ?= uno
ARDUINO_PORT         ?= /dev/ttyACM0
ARDUINO_LIBS         ?= EEPROM Serial Adafruit_RGBLCDShield Wire Wire/utility
ARDUINO_DIR          ?= /usr/share/arduino
ARDMK_DIR            ?= Arduino-Makefile

AVRDUDE              ?= avrdude
AVRDUDE_CONF         ?= /etc/avrdude.conf
AVR_TOOLS_DIR        ?= /usr
AVRDUDE_ARD_BAUDRATE ?= 115200

include $(ARDMK_DIR)/arduino-mk/Arduino.mk
