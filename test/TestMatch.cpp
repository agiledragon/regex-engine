#include "gtest/gtest.h"
#include "Service.h"
#include "pattern/Factory.h"

TEST(match, val)
{
	ASSERT_EQ("a", match(val("a"), "abcdef"));
	ASSERT_EQ("abc", match(val("abc"), "abcdef"));
	ASSERT_EQ("", match(val("def"), "abcdef"));
	ASSERT_EQ("", match(val("g"), "abcdef"));
}
