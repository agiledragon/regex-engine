#include "pattern/Eol.h"

Strings Eol::apply(const Strings& strs)
{
	Strings retStrs;
	for (auto str: strs)
	{
		if (str.size() == 0)
		{
			retStrs.push_back("");
		}
	}

	return retStrs;
}
