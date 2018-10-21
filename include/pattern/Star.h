#ifndef H08BCE493_5BAF_4AB8_BBA8_C8D944B03D92
#define H08BCE493_5BAF_4AB8_BBA8_C8D944B03D92


#include "pattern/Pattern.h"

struct Star: Pattern
{
	Star(const std::shared_ptr<Pattern> p);

	virtual Strings apply(const Strings& strs) override;

private:
	std::shared_ptr<Pattern> p;
};


#endif
