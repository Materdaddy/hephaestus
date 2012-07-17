#ifndef __RENARD_IN_H__
#define __RENARD_IN_H__

#include "DIYCTester.h"

class RenardIn : public DIYCTester
{
public:
  RenardIn(DIYCVars *vars);
  ~RenardIn() { };
  DIYCTester *mDownAction();
};

#endif // __RENARD_IN_H__
