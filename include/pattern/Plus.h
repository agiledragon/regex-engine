#ifndef HBD6ABC90_C4FA_4A7F_B177_58D433A66A53
#define HBD6ABC90_C4FA_4A7F_B177_58D433A66A53


#include "pattern/Pattern.h"

struct Plus: Pattern
{
	Plus(const std::shared_ptr<Pattern> p);

	virtual Strings apply(const Strings& strs) override;

private:
	std::shared_ptr<Pattern> p;
};




#endif
