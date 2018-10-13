#include "pattern/Val.h"
#include "pattern/Utils.h"

Val::Val(const std::string& s) : s(s)
{

}

Strings Val::apply(const Strings& strs)
{
	Strings retStrs;
	for (auto str: strs)
	{
		if (hasPrefix(str, this->s))
		{
			retStrs.push_back(str.substr(this->s.size()));
		}
	}

	return retStrs;
}


