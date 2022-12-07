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

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <any>
#include <map>

namespace TheStngularity::SyrDB {
    /**
     * @brief Dictionary type
     */
    class Dictionary {
        private:
            std::map<std::string, std::any> data;

        public:
            Dictionary();
            Dictionary(std::map<std::string, std::any> data);

            /**
             * @brief Get any value from data by key
             * @tparam T Type of get
             * @param key Key (key1.key2...)
             * @return Any type value
             */
            template<class T>
            T get(std::string key);

            /**
             * @brief Set any value of key
             * @tparam T Type of set
             * @param key Key (key1.key2...)
             * @param value Value of set
             */
            template<class T>
            void set(std::string key, T value);

            /**
             * @brief Convert this type to map
             * @return Map
             */
            std::map<std::string, std::any> asMap();
    };
}

#endif