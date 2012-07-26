#include "SaveToEepromSettings.h"
#include "ReadFromEepromSettings.h"

SaveToEepromSettings::SaveToEepromSettings(DIYCVars *vars) : DIYCSettings(vars)
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Save ->");
}

DIYCSettings *SaveToEepromSettings::upAction()
{
	return new ReadFromEepromSettings(mVars);
}

DIYCSettings *SaveToEepromSettings::rightAction()
{
	return new EditSaveToEepromSettings(mVars);
}

DIYCSettings *SaveToEepromSettings::selectAction()
{
	return new EditSaveToEepromSettings(mVars);
}

EditSaveToEepromSettings::EditSaveToEepromSettings(DIYCVars *vars) : DIYCSettings(vars)
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Confirm?");
}

DIYCSettings *EditSaveToEepromSettings::leftAction()
{
	return new SaveToEepromSettings(mVars);
}

DIYCSettings *EditSaveToEepromSettings::selectAction()
{
	mVars->saveToEeprom();

	return new SaveToEepromSettings(mVars);
}

EditSaveToEepromSettings::~EditSaveToEepromSettings() { }
