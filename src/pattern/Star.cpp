#include "pattern/Star.h"

Star::Star(const std::shared_ptr<Pattern> p) : p(p)
{

}

Strings Star::apply(const Strings& strs)
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
