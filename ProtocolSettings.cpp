#include "ProtocolSettings.h"
#include "MinDimmingSettings.h"
#include "BaudRateSettings.h"
#include "ReadFromEepromSettings.h"

ProtocolSettings::ProtocolSettings(DIYCVars *vars) : DIYCSettings(vars)
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print("Protocol ->");
}

DIYCSettings *ProtocolSettings::upAction()
{
	return new MinDimmingSettings(mVars);
}

DIYCSettings *ProtocolSettings::downAction()
{
	if ( mVars->getProtocol() == DMX )
		return new ReadFromEepromSettings(mVars);

	return new BaudRateSettings(mVars);
}

DIYCSettings *ProtocolSettings::rightAction()
{
	return new EditProtocolSettings(mVars);
}

DIYCSettings *ProtocolSettings::selectAction()
{
	return new EditProtocolSettings(mVars);
}

const char *EditProtocolSettings::protocolToString()
{
	switch (mProtocol)
	{
		case(RENARD):
			return "Renard";
		case(DMX):
			return "DMX";
		default:
			return "ERROR!";
	}
}

EditProtocolSettings::EditProtocolSettings(DIYCVars *vars) : DIYCSettings(vars), mProtocol(mVars->getProtocol())
{
	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(protocolToString());
}

DIYCSettings *EditProtocolSettings::downAction()
{
	if ( mProtocol > 0 )
		--mProtocol;

	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(protocolToString());

	return this;
}

DIYCSettings *EditProtocolSettings::upAction()
{
	if ( mProtocol+1 < MAX_PROTOCOLS )
		++mProtocol;

	mVars->printSettings();
	mVars->getLcd()->setCursor(0,1);
	mVars->getLcd()->print(protocolToString());

	return this;
}

DIYCSettings *EditProtocolSettings::leftAction()
{
	return new ProtocolSettings(mVars);
}

DIYCSettings *EditProtocolSettings::selectAction()
{
	mVars->setProtocol(mProtocol);
	if ( mProtocol != DMX )
		mVars->setBaudRateRenard();

	return new ProtocolSettings(mVars);
}

EditProtocolSettings::~EditProtocolSettings() { }
