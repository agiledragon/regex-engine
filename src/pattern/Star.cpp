#include "pattern/Star.h"
#include "pattern/Plus.h"

Star::Star(const std::shared_ptr<Pattern> p) : p(p)
{

}

Strings Star::apply(const Strings& strs)
{
	Strings retStrs;
	for (auto str: strs)
	{
		retStrs.push_back(str);
	}
	Strings tempStrs = strs;
	do
	{
		Strings inStrs = tempStrs;
		Strings outStrs = p->apply(inStrs);
		bool flag = false;
		tempStrs.clear();
		for (auto outStr: outStrs)
		{
			retStrs.push_back(outStr);

			flag = false;
			for (auto inStr: inStrs)
			{
				if (outStr == inStr)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				tempStrs.push_back(outStr);
			}

		}


	} while (tempStrs.size() > 0);


	return retStrs;
}
