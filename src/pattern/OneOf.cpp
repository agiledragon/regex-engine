#include "pattern/OneOf.h"

OneOf::OneOf(const std::string& s) : s(s)
{

}

Strings OneOf::apply(const Strings& strs)
{
	Strings retStrs;
	for (auto str: strs)
	{
		for (auto c: this->s)
		{
			if (str[0] == c)
			{
				retStrs.push_back(str.substr(1));
			}
		}

	}

	return retStrs;
}
