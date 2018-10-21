#include "pattern/Seq.h"

Seq::Seq(const std::shared_ptr<Pattern> lp, const std::shared_ptr<Pattern> rp) : lp(lp), rp(rp)
{

}

Strings Seq::apply(const Strings& strs)
{
	Strings tempStrs = lp->apply(strs);
	return rp->apply(tempStrs);
}
