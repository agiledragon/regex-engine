#include "gtest/gtest.h"
#include "Service.h"
#include "pattern/Factory.h"
#include "pattern/Pattern.h"

TEST(search, val)
{
	ASSERT_EQ("a", search(val("a"), "helloabcdef"));
	ASSERT_EQ("abc", search(val("abc"), "worldabcdef"));
	ASSERT_EQ("abc", search(val("abc"), "abc"));
	ASSERT_EQ("def", search(val("def"), "abcdef"));
	ASSERT_EQ("", search(val("g"), "abcdef"));
	ASSERT_EQ("", search(val("g"), ""));
}

TEST(search, oneof)
{
	ASSERT_EQ("a", search(oneof("abc"), "888abcdef"));
	ASSERT_EQ("b", search(oneof("abc"), "6bcdef"));
	ASSERT_EQ("c", search(oneof("abc"), "cdef"));
	ASSERT_EQ("", search(oneof("abc"), "def"));
	ASSERT_EQ("a", search(oneof("abc"), "weeka"));
	ASSERT_EQ("", search(oneof("abc"), ""));
}

TEST(search, dot)
{
	ASSERT_EQ("a", search(dot(), "abc"));
	ASSERT_EQ("b", search(dot(), "bc"));
	ASSERT_EQ("c", search(dot(), "c"));
	ASSERT_EQ("", search(dot(), ""));
}

TEST(search, seq)
{
	ASSERT_EQ("abcdef", search(seq(val("abc"), val("def")), "helloabcdefg"));
	ASSERT_EQ("ae", search(seq(oneof("abc"), oneof("def")), "789aed"));
	ASSERT_EQ("ef", search(seq(dot(), dot()), "efg"));
	ASSERT_EQ("abcf", search(seq(val("abc"), oneof("def")), "mmabcfg"));
	ASSERT_EQ("ab", search(seq(oneof("abc"), dot()), "abcde"));
	ASSERT_EQ("eabc", search(seq(dot(), val("abc")), "eabc"));
	ASSERT_EQ("de", search(seq(dot(), oneof("def")), "def"));
	ASSERT_EQ("", search(seq(val("abc"), val("def")), "9dabcde"));
}

TEST(search, alt)
{
	std::string prefix = "";
	ASSERT_EQ("abc", search(alt(val("abc"), val("def")), "helloabcdefg"));
	ASSERT_EQ("def", search(alt(val("abc"), val("def")), "hellodefg"));
	ASSERT_EQ("a", search(alt(oneof("abc"), oneof("def")), "890aed"));
	ASSERT_EQ("e", search(alt(oneof("abc"), oneof("def")), "110ed"));
	ASSERT_EQ("e", search(alt(dot(), dot()), "ef"));
	ASSERT_EQ("abc", search(alt(val("abc"), oneof("def")), "mmabcfg"));
	ASSERT_EQ("f", search(alt(val("abc"), oneof("def")), "ggfg"));
	ASSERT_EQ("a", search(alt(oneof("abc"), dot()), "abcde"));
	ASSERT_EQ("d", search(alt(oneof("abc"), dot()), "de"));
	ASSERT_EQ("", search(alt(val("abc"), val("def")), "abde"));
}

TEST(search, eol)
{
	ASSERT_EQ("abc", search(seq(val("abc"), eol()), "abc"));
	ASSERT_EQ("", search(seq(val("abc"), eol()), "abcdefg"));
	ASSERT_EQ("a", search(seq(oneof("abc"), eol()), "a"));
	ASSERT_EQ("", search(seq(oneof("abc"), eol()), "ae"));
	ASSERT_EQ("e", search(seq(dot(), eol()), "e"));
	ASSERT_EQ("f", search(seq(dot(), eol()), "ef"));
}

TEST(search, star)
{
	ASSERT_EQ("ab", search(seq(star(val("a")), val("ab")), "helloab"));
	ASSERT_EQ("aab", search(seq(star(val("a")), val("ab")), "worldaab"));
	ASSERT_EQ("aaaaaaab", search(seq(star(val("a")), val("ab")), "helloaaaaaaab"));
	ASSERT_EQ("cd", search(seq(star(val("ab")), val("cd")), "worldcde"));
	ASSERT_EQ("abcd", search(seq(star(val("ab")), val("cd")), "helloabcde"));
	ASSERT_EQ("ababababcd", search(seq(star(val("ab")), val("cd")), "worldababababcde"));
	ASSERT_EQ("abcd", search(seq(star(val("ab")), val("abcd")), "helloabcde"));
	ASSERT_EQ("ababcd", search(seq(star(val("ab")), val("abcd")), "890ababcde"));
	ASSERT_EQ("ababababcd", search(seq(star(val("ab")), val("abcd")), "110ababababcde"));
	ASSERT_EQ("a", search(star(val("a")), "777abc"));
	ASSERT_EQ("b", search(seq(star(val("a")), val("b")), "cppbc"));
	ASSERT_EQ("ab", search(star(seq(star(val("a")), star(val("b")))), "leeab"));
	ASSERT_EQ("aaabaabbbabbabc", search(seq(star(seq(star(val("a")), star(val("b")))), val("abc")), "helloaaabaabbbabbabcd"));
	ASSERT_EQ("aaabaabbbabbabc", search(seq(star(seq(star(val("a")), star(val("b")))), val("c")), "worldaaabaabbbabbabcd"));
}

TEST(search, plus)
{
	ASSERT_EQ("", search(seq(plus(val("a")), val("ab")), "helloab"));
	ASSERT_EQ("aab", search(seq(plus(val("a")), val("ab")), "worldaab"));
	ASSERT_EQ("aaaaaaab", search(seq(plus(val("a")), val("ab")), "888aaaaaaab"));
	ASSERT_EQ("", search(seq(plus(val("ab")), val("cd")), "666cde"));
	ASSERT_EQ("abcd", search(seq(plus(val("ab")), val("cd")), "123abcde"));
	ASSERT_EQ("ababababcd", search(seq(plus(val("ab")), val("cd")), "090ababababcde"));
	ASSERT_EQ("", search(seq(plus(val("ab")), val("abcd")), "abcde"));
	ASSERT_EQ("ababcd", search(seq(plus(val("ab")), val("abcd")), "tttababcde"));
	ASSERT_EQ("ababababcd", search(seq(plus(val("ab")), val("abcd")), "mmababababcde"));
	ASSERT_EQ("aaabaabbbabbabc", search(seq(plus(seq(plus(val("a")), plus(val("b")))), val("abc")), "ggaaabaabbbabbabcd"));
	ASSERT_EQ("aaabaabbbabbabc", search(seq(plus(seq(plus(val("a")), plus(val("b")))), val("c")), "mmaaabaabbbabbabcd"));
}

TEST(search, opt)
{
	ASSERT_EQ("ab", search(seq(opt(val("a")), val("ab")), "ab"));
	ASSERT_EQ("aab", search(seq(opt(val("a")), val("ab")), "aab"));
	ASSERT_EQ("aab", search(seq(opt(val("a")), val("ab")), "aaaaaaab"));
	ASSERT_EQ("cd", search(seq(opt(val("ab")), val("cd")), "cde"));
	ASSERT_EQ("abcd", search(seq(opt(val("ab")), val("cd")), "abcde"));
	ASSERT_EQ("abcd", search(seq(opt(val("ab")), val("cd")), "ababababcde"));
	ASSERT_EQ("abcd", search(seq(opt(val("ab")), val("abcd")), "abcde"));
	ASSERT_EQ("ababcd", search(seq(opt(val("ab")), val("abcd")), "ababcde"));
	ASSERT_EQ("ababcd", search(seq(opt(val("ab")), val("abcd")), "ababababcde"));
	ASSERT_EQ("a", search(opt(val("a")), "abc"));
	ASSERT_EQ("b", search(seq(opt(val("a")), val("b")), "bc"));
	ASSERT_EQ("ab", search(star(seq(opt(val("a")), opt(val("b")))), "ab"));
	ASSERT_EQ("babc", search(seq(opt(seq(opt(val("a")), opt(val("b")))), val("abc")), "aaabaabbbabbabcd"));
	ASSERT_EQ("abc", search(seq(opt(seq(opt(val("a")), opt(val("b")))), val("c")), "aaabaabbbabbabcd"));
}

