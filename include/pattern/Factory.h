#ifndef H52EC16E0_C082_43C9_B87B_F01C28A044B2
#define H52EC16E0_C082_43C9_B87B_F01C28A044B2

#include <string>

struct Pattern;

std::shared_ptr<Pattern> val(const std::string& str);
std::shared_ptr<Pattern> oneof(const std::string& str);
std::shared_ptr<Pattern> dot();
std::shared_ptr<Pattern> seq(const std::shared_ptr<Pattern> lp, const std::shared_ptr<Pattern> rp);
std::shared_ptr<Pattern> alt(const std::shared_ptr<Pattern> lp, const std::shared_ptr<Pattern> rp);
std::shared_ptr<Pattern> eol();
std::shared_ptr<Pattern> star(const std::shared_ptr<Pattern> p);

#endif
