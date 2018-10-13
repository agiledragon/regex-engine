#include "gtest/gtest.h"
#include "Service.h"
#include "pattern/Factory.h"
#include "pattern/Pattern.h"

TEST(match, val)
{
	ASSERT_EQ("a", match(val("a"), "abcdef"));
	ASSERT_EQ("abc", match(val("abc"), "abcdef"));
	ASSERT_EQ("", match(val("def"), "abcdef"));
	ASSERT_EQ("", match(val("g"), "abcdef"));
}

TEST(match, oneof)
{
	ASSERT_EQ("a", match(oneof("abc"), "abcdef"));
	ASSERT_EQ("b", match(oneof("abc"), "bcdef"));
	ASSERT_EQ("c", match(oneof("abc"), "cdef"));
	ASSERT_EQ("", match(oneof("abc"), "def"));
}
