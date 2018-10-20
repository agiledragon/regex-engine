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

TEST(match, seq)
{
	ASSERT_EQ("abcdef", match(seq(val("abc"), val("def")), "abcdefg"));
	ASSERT_EQ("ae", match(seq(oneof("abc"), oneof("def")), "aed"));
	ASSERT_EQ("ef", match(seq(dot(), dot()), "efg"));
	ASSERT_EQ("abcf", match(seq(val("abc"), oneof("def")), "abcfg"));
	ASSERT_EQ("ab", match(seq(oneof("abc"), dot()), "abcde"));
	ASSERT_EQ("eabc", match(seq(dot(), val("abc")), "eabc"));
	ASSERT_EQ("de", match(seq(dot(), oneof("def")), "def"));
	ASSERT_EQ("", match(seq(val("abc"), val("def")), "abcde"));
}

TEST(match, alt)
{
	ASSERT_EQ("abc", match(alt(val("abc"), val("def")), "abcdefg"));
	ASSERT_EQ("def", match(alt(val("abc"), val("def")), "defg"));
	ASSERT_EQ("a", match(alt(oneof("abc"), oneof("def")), "aed"));
	ASSERT_EQ("e", match(alt(oneof("abc"), oneof("def")), "ed"));
	ASSERT_EQ("e", match(alt(dot(), dot()), "ef"));
	ASSERT_EQ("abc", match(alt(val("abc"), oneof("def")), "abcfg"));
	ASSERT_EQ("f", match(alt(val("abc"), oneof("def")), "fg"));
	ASSERT_EQ("a", match(alt(oneof("abc"), dot()), "abcde"));
	ASSERT_EQ("d", match(alt(oneof("abc"), dot()), "de"));
	ASSERT_EQ("", match(seq(val("abc"), val("def")), "abde"));

}

