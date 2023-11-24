#include "string_helper.h"
#include <string>
#include <sstream>
using std::string, std::stringstream;

string ToLowerCase(const string& str) {
    auto c_str = str.c_str();

    stringstream ss;
    for (int i = 0; i < str.size(); i++) {
        ss << (char)tolower(c_str[i]);
    }

    return ss.str();
}
