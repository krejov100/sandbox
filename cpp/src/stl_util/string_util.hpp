// Copyright 2018 Philip Krejov
#pragma once
#include <string>

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