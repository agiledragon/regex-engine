#include "pattern/Utils.h"

bool hasPrefix(const std::string& str, const std::string& prefix)
{
	for (int i = 0; i < prefix.size(); i++)
	{
		if (str[i] != prefix[i]) return false;
	}
	return true;
}
