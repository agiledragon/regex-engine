#include "pattern/Dot.h"

Strings Dot::apply(const Strings& strs)
{
	Strings retStrs;
	for (auto str: strs)
	{
		if (str.size() >= 1)
		{
			retStrs.push_back(str.substr(1));
		}
	}

	return retStrs;
}
