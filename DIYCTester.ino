//TODO: Debouncing

#include "DIYCVars.h"
#include "DIYCSettings.h"
#include "OutputSettings.h"

DIYCSettings *settings;

void setup() {
	settings = new OutputSettings(new DIYCVars());
}

void loop() {
	uint8_t buttons = settings->getVars()->getLcd()->readButtons();
	DIYCSettings *new_settings = settings;

	if (buttons) {
		if (buttons & BUTTON_UP)
			new_settings = settings->upAction();
		if (buttons & BUTTON_DOWN)
			new_settings = settings->downAction();
		if (buttons & BUTTON_LEFT)
			new_settings = settings->leftAction();
		if (buttons & BUTTON_RIGHT)
			new_settings = settings->rightAction();
		if (buttons & BUTTON_SELECT)
			new_settings = settings->selectAction();
	}
	
	if ( new_settings != settings )
		delete settings;
	settings = new_settings;

	settings->getVars()->sendData();
	delay(100);
}
