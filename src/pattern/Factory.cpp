#include "pattern/Factory.h"
#include "pattern/Val.h"
#include "pattern/OneOf.h"
#include "pattern/Dot.h"
#include "pattern/Seq.h"
#include <memory>

std::shared_ptr<Pattern> val(const std::string& str)
{
	return std::shared_ptr<Pattern>(new Val(str));
}

std::shared_ptr<Pattern> oneof(const std::string& str)
{
	return std::shared_ptr<Pattern>(new OneOf(str));
}

std::shared_ptr<Pattern> dot()
{
	return std::shared_ptr<Pattern>(new Dot());
}

std::shared_ptr<Pattern> seq(const std::shared_ptr<Pattern> lp, const std::shared_ptr<Pattern> rp)
{
	return std::shared_ptr<Pattern>(new Seq(lp, rp));
}

