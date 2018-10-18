#ifndef HC16B3353_9518_4942_90A6_58557CA8520D
#define HC16B3353_9518_4942_90A6_58557CA8520D


#include "pattern/Pattern.h"

struct Dot : Pattern
{
	Dot() = default;

	virtual Strings apply(const Strings& strs) override;
};


#endif
