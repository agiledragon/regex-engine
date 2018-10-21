#ifndef H2A33F37F_84FE_406B_8F9C_7F9F98CF4D40
#define H2A33F37F_84FE_406B_8F9C_7F9F98CF4D40


#include "pattern/Pattern.h"

struct Opt: Pattern
{
	Opt(const std::shared_ptr<Pattern> p);

	virtual Strings apply(const Strings& strs) override;

private:
	std::shared_ptr<Pattern> p;
};




#endif
