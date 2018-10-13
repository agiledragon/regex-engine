#ifndef H24829943_A55F_4213_A2F2_447FA37151AF
#define H24829943_A55F_4213_A2F2_447FA37151AF

#include "pattern/Pattern.h"

struct OneOf : Pattern
{
	OneOf(const std::string& s);

	virtual Strings apply(const Strings& strs) override;

private:
	std::string s;
};



#endif
