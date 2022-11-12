/*
    SyrDB/StringUtils - Library for working with string
    [stringutils.h] - Main file (Annotation)
    Made with ❤ for you
    Distributed under the BSL license (see LICENSE file)
*/

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <iostream>
#include <vector>

namespace TheStngularity::SyrDB::StrU {
    /**
     * @brief Normalize text size
     * @param content Content to normalize
     * @return Normalized text
     */
    std::string normalizeText(std::string content);

    /**
     * @brief Normalize text size
     * @param content Content to normalize
     * @param size Required minimal size
     * @return Normalized text
     */
    std::string normalizeText(std::string content, short size);

    /**
     * @brief Normalize text size
     * @param content Content to normalize
     * @param size Required minimal size
     * @param replace Chat to add 
     * @return Normalized text
     */
    std::string normalizeText(std::string content, short size, char replace);

    /**
     * @brief Normalize text size
     * @param content Content to normalize
     * @return Normalized text
     */
    std::string normalizeText(int content);

    /**
     * @brief Normalize text size
     * @param content Content to normalize
     * @param size Required minimal size
     * @return Normalized text
     */
    std::string normalizeText(int content, short size);

    /**
     * @brief Normalize text size
     * @param content Content to normalize
     * @param size Required minimal size
     * @param replace Chat to add 
     * @return Normalized text
     */
    std::string normalizeText(int content, short size, char replace);

    /**
     * @brief Split any string
     * @param str String to split
     * @param sep Separator
     * @return Array with splited text
     */
    std::vector<std::string> split(std::string str, char sep);

    /**
     * @brief Replace any chars to another string
     * @param str Source string
     * @param old Old chars
     * @param _new New chars
     * @return Updated string
     */
    std::string replace(std::string str, std::string old, std::string _new);
}

#endif