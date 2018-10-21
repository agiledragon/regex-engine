#include "pattern/Opt.h"

Opt::Opt(const std::shared_ptr<Pattern> p) : p(p)
{

}

Strings Opt::apply(const Strings& strs)
{
	Strings retStrs;
	for (auto str: strs)
	{
		retStrs.push_back(str);
	}
	Strings tempStrs = p->apply(strs);
	for (auto tempStr: tempStrs)
	{
		retStrs.push_back(tempStr);
	}
	return retStrs;
}
