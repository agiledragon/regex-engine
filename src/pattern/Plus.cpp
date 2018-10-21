#include "pattern/Plus.h"

Plus::Plus(const std::shared_ptr<Pattern> p) : p(p)
{

}

Strings Plus::apply(const Strings& strs)
{
	Strings retStrs;
	Strings tempStrs = strs;
	do
	{
		tempStrs = p->apply(tempStrs);
		for (auto str: tempStrs)
		{
			retStrs.push_back(str);
		}
	} while (tempStrs.size() > 0);
	return retStrs;
}
