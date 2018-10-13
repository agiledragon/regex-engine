#ifndef HADCDD2E0_3A9D_4138_A7A6_420A4198A8D7
#define HADCDD2E0_3A9D_4138_A7A6_420A4198A8D7


#include "pattern/Pattern.h"

struct Val : Pattern
{
	Val(const String& s);

	virtual Strings apply(const Strings& strs) override;

private:
	String s;
};


#endif
