// Copyright 2018 Philip Krejov
#ifndef CPP_STRING_UTIL_HPP_
#define CPP_STRING_UTIL_HPP_

#include <string>

namespace pk {
    std::string strrep(std::string str, const std::string &matchStr, const std::string &repStr) {
        if (matchStr.empty())
			return str;
        size_t idx = 0;
        while (true) {
            // locate substring
			idx = str.find(matchStr, idx);
            if (idx == std::string::npos) break;

            // replace substring
            str.replace(idx, matchStr.length(), repStr);
            idx += repStr.length();
        }
        return str;
    }

}  // namespace pk

#endif  // CPP_STRING_UTIL_HPP_
