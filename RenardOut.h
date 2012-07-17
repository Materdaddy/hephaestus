#ifndef __RENARD_OUT_H__
#define __RENARD_OUT_H__

#include "DIYCTester.h"

class RenardOut : public DIYCTester
{
public:
  RenardOut(DIYCVars *vars);
  ~RenardOut() { };
  DIYCTester *mUpAction();
  DIYCTester *mRightAction();
};

class RenardOutByChannel : public DIYCTester
{
public:
  RenardOutByChannel(DIYCVars *vars);
  ~RenardOutByChannel() { };
  DIYCTester *mUpAction();
  DIYCTester *mDownAction();
  DIYCTester *mLeftAction();
  DIYCTester *mLoop
private:
  int mChannel;
};

#endif // __RENARD_OUT_H__
