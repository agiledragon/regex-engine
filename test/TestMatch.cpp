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
	ASSERT_EQ("", match(alt(val("abc"), val("def")), "abde"));
}

TEST(match, eol)
{
	ASSERT_EQ("abc", match(seq(val("abc"), eol()), "abc"));
	ASSERT_EQ("", match(seq(val("abc"), eol()), "abcdefg"));
	ASSERT_EQ("a", match(seq(oneof("abc"), eol()), "a"));
	ASSERT_EQ("", match(seq(oneof("abc"), eol()), "ae"));
	ASSERT_EQ("e", match(seq(dot(), eol()), "e"));
	ASSERT_EQ("", match(seq(dot(), eol()), "ef"));
}

TEST(match, star)
{
	ASSERT_EQ("ab", match(seq(star(val("a")), val("ab")), "ab"));
	ASSERT_EQ("aab", match(seq(star(val("a")), val("ab")), "aab"));
	ASSERT_EQ("aaaaaaab", match(seq(star(val("a")), val("ab")), "aaaaaaab"));
	ASSERT_EQ("cd", match(seq(star(val("ab")), val("cd")), "cde"));
	ASSERT_EQ("abcd", match(seq(star(val("ab")), val("cd")), "abcde"));
	ASSERT_EQ("ababababcd", match(seq(star(val("ab")), val("cd")), "ababababcde"));
	ASSERT_EQ("abcd", match(seq(star(val("ab")), val("abcd")), "abcde"));
	ASSERT_EQ("ababcd", match(seq(star(val("ab")), val("abcd")), "ababcde"));
	ASSERT_EQ("ababababcd", match(seq(star(val("ab")), val("abcd")), "ababababcde"));
	ASSERT_EQ("a", match(star(val("a")), "abc"));
	ASSERT_EQ("b", match(seq(star(val("a")), val("b")), "bc"));
	ASSERT_EQ("ab", match(star(seq(star(val("a")), star(val("b")))), "ab"));
	ASSERT_EQ("aaabaabbbabbabc", match(seq(star(seq(star(val("a")), star(val("b")))), val("abc")), "aaabaabbbabbabcd"));
	ASSERT_EQ("aaabaabbbabbabc", match(seq(star(seq(star(val("a")), star(val("b")))), val("c")), "aaabaabbbabbabcd"));
}

TEST(match, plus)
{
	ASSERT_EQ("", match(seq(plus(val("a")), val("ab")), "ab"));
	ASSERT_EQ("aab", match(seq(plus(val("a")), val("ab")), "aab"));
	ASSERT_EQ("aaaaaaab", match(seq(plus(val("a")), val("ab")), "aaaaaaab"));
	ASSERT_EQ("", match(seq(plus(val("ab")), val("cd")), "cde"));
	ASSERT_EQ("abcd", match(seq(plus(val("ab")), val("cd")), "abcde"));
	ASSERT_EQ("ababababcd", match(seq(plus(val("ab")), val("cd")), "ababababcde"));
	ASSERT_EQ("", match(seq(plus(val("ab")), val("abcd")), "abcde"));
	ASSERT_EQ("ababcd", match(seq(plus(val("ab")), val("abcd")), "ababcde"));
	ASSERT_EQ("ababababcd", match(seq(plus(val("ab")), val("abcd")), "ababababcde"));
	ASSERT_EQ("aaabaabbbabbabc", match(seq(plus(seq(plus(val("a")), plus(val("b")))), val("abc")), "aaabaabbbabbabcd"));
	ASSERT_EQ("aaabaabbbabbabc", match(seq(plus(seq(plus(val("a")), plus(val("b")))), val("c")), "aaabaabbbabbabcd"));
}

TEST(match, opt)
{
	ASSERT_EQ("ab", match(seq(opt(val("a")), val("ab")), "ab"));
	ASSERT_EQ("aab", match(seq(opt(val("a")), val("ab")), "aab"));
	ASSERT_EQ("", match(seq(opt(val("a")), val("ab")), "aaaaaaab"));
	ASSERT_EQ("cd", match(seq(opt(val("ab")), val("cd")), "cde"));
	ASSERT_EQ("abcd", match(seq(opt(val("ab")), val("cd")), "abcde"));
	ASSERT_EQ("", match(seq(opt(val("ab")), val("cd")), "ababababcde"));
	ASSERT_EQ("abcd", match(seq(opt(val("ab")), val("abcd")), "abcde"));
	ASSERT_EQ("ababcd", match(seq(opt(val("ab")), val("abcd")), "ababcde"));
	ASSERT_EQ("", match(seq(opt(val("ab")), val("abcd")), "ababababcde"));
	ASSERT_EQ("a", match(opt(val("a")), "abc"));
	ASSERT_EQ("b", match(seq(opt(val("a")), val("b")), "bc"));
	ASSERT_EQ("ab", match(star(seq(opt(val("a")), opt(val("b")))), "ab"));
	ASSERT_EQ("", match(seq(opt(seq(opt(val("a")), opt(val("b")))), val("abc")), "aaabaabbbabbabcd"));
	ASSERT_EQ("", match(seq(opt(seq(opt(val("a")), opt(val("b")))), val("c")), "aaabaabbbabbabcd"));
}

