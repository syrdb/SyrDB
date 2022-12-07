/*
    This file is part of SyrDB.

    SyrDB is free software: you can redistribute it and/or modify it under the terms
    of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version.

    SyrDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License along with SyrDB.
    If not, see <https://www.gnu.org/licenses/>.    
*/

#include <string>
#include <vector>
#include "stringutils.h"

namespace TheStngularity::SyrDB::StrU {
    // Normalize text size
    std::string normalizeText(std::string content) {
        for(int i = 0; i < 2-content.length(); i++) content.insert(0, std::to_string('0'));
        return content;
    }

    std::string normalizeText(std::string content, short size) {
        for(int i = 0; i < size-content.length(); i++) content.insert(0, std::to_string('0'));
        return content;
    }

    std::string normalizeText(std::string content, short size, char replace) {
        for(int i = 0; i < size-content.length(); i++) content.insert(0, std::to_string(replace));
        return content;
    }

    std::string normalizeText(int content) {
        std::string str = std::to_string(content);
        for(int i = 0; i < 2-std::to_string(content).length(); i++) str.insert(0, std::to_string('0'));
        return str;
    }

    std::string normalizeText(int content, short size) {
        std::string str = std::to_string(content);
        for(int i = 0; i < size-std::to_string(content).length(); i++) str.insert(0, std::to_string('0'));
        return str;
    }

    std::string normalizeText(int content, short size, char replace) {
        std::string str = std::to_string(content);
        for(int i = 0; i < size-std::to_string(content).length(); i++) str.insert(0, std::to_string(replace));
        return str;
    }

    // Split any string
    std::vector<std::string> split(std::string str, char sep) {
        std::vector<std::string> result;
        unsigned short si = 0;
        for(unsigned short i = 0; i <= (unsigned short) str.length(); i++) {
            if(str[i] == sep || i == str.length()) {
                std::string substr;
                substr.append(str, si, i-si);
                result.push_back(substr);
                si = i+1;
            }
        } return result;
    }

    // Replace any chars to another string
    std::string replace(std::string str, std::string old, std::string _new) {
        size_t start_pos = str.find(old);
        if(start_pos == std::string::npos)
            return str;
        return str.replace(start_pos, old.length(), _new);
    }
}