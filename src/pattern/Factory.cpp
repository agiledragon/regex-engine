#include "pattern/Factory.h"
#include "pattern/Val.h"
#include "pattern/OneOf.h"
#include "pattern/Dot.h"
#include <memory>

std::unique_ptr<Pattern> val(const std::string& str)
{
	return std::unique_ptr<Pattern>(new Val(str));
}

std::unique_ptr<Pattern> oneof(const std::string& str)
{
	return std::unique_ptr<Pattern>(new OneOf(str));
}

std::unique_ptr<Pattern> dot()
{
	return std::unique_ptr<Pattern>(new Dot());
}
