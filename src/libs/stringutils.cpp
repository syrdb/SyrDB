/*
    SyrDB/StringUtils - Library for working with string
    [stringutils.cpp] - Main file
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#include <iostream>
#include <string>
#include <vector>
#include "stringutils.h"

namespace TheSngularity::SyrDB::StrU {
    // Normolize text size
    std::string normalizeText(std::string content, short size=2, char replace='0') {
        for(int i = 0; i < size-content.length(); i++) content.insert(0, replace);
        return content;
    }

    std::string normalizeText(int content, short size=2, char replace='0') {
        std::string str = std::to_string(content);
        for(int i = 0; i < size-std::to_string(content).length(); i++) str.insert(0, replace);
        return str;
    }

    // Split any string
    std::vector<std::string> split(std::string str, char sep) {
        std::vector<std::string> splited;
        unsigned short si = 0;
        for(unsigned short i = 0; i <= str.length(); i++) {
            if(str[i] == sep || i == str.length()) {
                std::string substr = "";
                substr.append(str, si, i-si);
                splited.push_back(substr);
                si = i+1;
            };
        }
        return splited;
    }
}