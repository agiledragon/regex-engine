#ifndef H8C40252D_66BE_4869_9CA5_661986EF7CE4
#define H8C40252D_66BE_4869_9CA5_661986EF7CE4


#include "pattern/Pattern.h"

struct Alt: Pattern
{
	Alt(const std::shared_ptr<Pattern> lp, const std::shared_ptr<Pattern> rp);

	virtual Strings apply(const Strings& strs) override;

private:
	std::shared_ptr<Pattern> lp;
	std::shared_ptr<Pattern> rp;
};


#endif
