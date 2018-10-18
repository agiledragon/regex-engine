#ifndef HA2AC961C_0FC1_4B26_9FB4_337E09A283E5
#define HA2AC961C_0FC1_4B26_9FB4_337E09A283E5

#include "pattern/Pattern.h"

struct Seq: Pattern
{
	Seq(const std::shared_ptr<Pattern> lp, const std::shared_ptr<Pattern> rp);

	virtual Strings apply(const Strings& strs) override;

private:
	std::shared_ptr<Pattern> lp;
	std::shared_ptr<Pattern> rp;
};


#endif
