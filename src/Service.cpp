#include "Service.h"

std::string match(std::unique_ptr<Pattern> pattern, const String& str)
{
	Strings strs;
	strs.push_back(str);
	Strings retStrs = pattern->apply(strs);
	if (retStrs.size() == 0) return "";

	int min = 0;
	for (int i = 1; i < retStrs.size(); i++)
	{
		if (retStrs[i].size() < retStrs[min].size()) min = i;
	}
	return str.substr(0, str.size() - retStrs[min].size());
}
