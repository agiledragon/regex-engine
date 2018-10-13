#include "pattern/Val.h"

namespace
{
	bool hasPrefix(const String& str, const String& prefix)
	{
		for (int i = 0; i < prefix.size(); i++)
		{
			if (str[i] != prefix[i]) return false;
		}
		return true;
	}
}

Val::Val(const String& s) : s(s)
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


