
  Serial.print("SPIT OUT RENARD FOR CHANNEL: ");
  Serial.println(mChannel);
  
  return this;
}

#define MAX_CHANNELS 8
DIYCTester *RenardOutByChannel::mUpAction()
{
  if ( mChannel < MAX_CHANNELS )
    mChannel++;

  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("- Channel: ");
  mVars->getLcd()->print(mChannel);
  
  return this;
}

DIYCTester *RenardOutByChannel::mDownAction()
{
  if ( mChannel - 1 > 0 )
    mChannel--;

  mVars->getLcd()->setCursor(0,1);
  mVars->getLcd()->print("- Channel: ");
  mVars->getLcd()->print(mChannel);
  
  return this;
}

DIYCTester *RenardOutByChannel::mLeftAction()
{
  return new RenardOut(this->mVars);
}
