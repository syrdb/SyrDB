/*
    SyrDB/StringUtils - Library for working with string
    [stringutils.h] - Main file (Annotation)
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <iostream>
#include <vector>

namespace TheSngularity::SyrDB::StrU {
    /**
     * @brief Normolize text size
     * @param content Content to normolize
     * @param size Required minimal size
     * @param replace Chat to add 
     * @return Normolized text
     */
    std::string normalizeText(std::string content, short size=2, char replace='0');

    /**
     * @brief Normolize text size
     * @param content Content to normolize
     * @param size Required minimal size
     * @param replace Chat to add 
     * @return Normolized text
     */
    std::string normalizeText(int content, short size=2, char replace='0');

    /**
     * @brief Split any string
     * @param str String to split
     * @param sep Separator
     * @return Array with splited text
     */
    std::vector<std::string> split(std::string str, char sep);
}

#endif