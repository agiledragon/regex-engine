#include "pattern/Alt.h"

Alt::Alt(const std::shared_ptr<Pattern> lp, const std::shared_ptr<Pattern> rp) : lp(std::move(lp)), rp(std::move(rp))
{

}

Strings Alt::apply(const Strings& strs)
{
	Strings tempStrs = lp->apply(strs);
	if (tempStrs.size() > 0)
	{
		return tempStrs;
	}
	return rp->apply(strs);
}
