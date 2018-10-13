#ifndef H52EC16E0_C082_43C9_B87B_F01C28A044B2
#define H52EC16E0_C082_43C9_B87B_F01C28A044B2

#include <string>

struct Pattern;

std::unique_ptr<Pattern> val(const std::string& str);
std::unique_ptr<Pattern> oneof(const std::string& str);


#endif
