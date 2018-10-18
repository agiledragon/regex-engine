#include "gtest/gtest.h"
#include "Service.h"
#include "pattern/Factory.h"
#include "pattern/Pattern.h"

TEST(match, val)
{
	ASSERT_EQ("a", match(val("a"), "abcdef"));
	ASSERT_EQ("abc", match(val("abc"), "abcdef"));
	ASSERT_EQ("abc", match(val("abc"), "abc"));
	ASSERT_EQ("", match(val("def"), "abcdef"));
	ASSERT_EQ("", match(val("g"), "abcdef"));
	ASSERT_EQ("", match(val("g"), ""));
}

TEST(match, oneof)
{
	ASSERT_EQ("a", match(oneof("abc"), "abcdef"));
	ASSERT_EQ("b", match(oneof("abc"), "bcdef"));
	ASSERT_EQ("c", match(oneof("abc"), "cdef"));
	ASSERT_EQ("", match(oneof("abc"), "def"));
	ASSERT_EQ("a", match(oneof("abc"), "a"));
	ASSERT_EQ("", match(oneof("abc"), ""));
}

TEST(match, dot)
{
	ASSERT_EQ("a", match(dot(), "abc"));
	ASSERT_EQ("b", match(dot(), "bc"));
	ASSERT_EQ("c", match(dot(), "c"));
	ASSERT_EQ("", match(dot(), ""));
}
