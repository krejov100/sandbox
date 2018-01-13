// Copyright 2018 Philip Krejov
#ifndef CPP_STRING_UTIL_HPP_
#define CPP_STRING_UTIL_HPP_

#include <string>

namespace pk {
    void strrep(
        const std::string &matchStr,
        const std::string &repStr,
        std::string * const str) {
        if (matchStr.empty())
            return;
        size_t idx = 0;
        while (true) {
            // locate substring
            index = str.find(matchStr, idx);
            if (index == std::string::npos) break;

            // replace substring
            str.replace(idx, matchStr.length(), repStr);
            idx += repStr.length();
        }
        return str;
    }

}  // namespace pk

#endif  // CPP_STRING_UTIL_HPP_
