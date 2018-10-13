#include "pattern/Factory.h"
#include "pattern/Val.h"
#include <memory>

std::unique_ptr<Pattern> val(const String& str)
{
	return std::unique_ptr<Pattern>(new Val(str));
}

