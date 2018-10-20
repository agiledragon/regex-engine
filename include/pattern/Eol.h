#ifndef HBD8D2995_A74B_4226_AD1B_56AC25188053
#define HBD8D2995_A74B_4226_AD1B_56AC25188053


#include "pattern/Pattern.h"

struct Eol : Pattern
{
	Eol() = default;

	virtual Strings apply(const Strings& strs) override;
};



#endif
