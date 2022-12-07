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