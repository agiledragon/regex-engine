#ifndef H193C3BCA_EF2C_462E_99ED_2D92F8EE8D17
#define H193C3BCA_EF2C_462E_99ED_2D92F8EE8D17

#include <vector>
#include <string>

typedef std::string String;
typedef std::vector<std::string> Strings;

struct Pattern
{
	virtual ~Pattern() = default;

	virtual Strings apply(const Strings& strs) = 0;
};


#endif
