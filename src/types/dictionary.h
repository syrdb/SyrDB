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
#include <map>
#include <any>

namespace TheStngularity::SyrDB {
    /**
     * @brief Dicitonary class
     */
    class Dictionary {
        private:
            std::map<std::string, std::any> data;

        public:
            /**
             * @brief Construct a new Dictionary object by data
             * @param d Data map
             */
            Dictionary(std::map<std::string, std::any> d);

            /**
             * @brief Construct a new Dictionary object by other Dictionary object
             * @param old Old Dictionary object
             */
            Dictionary(Dictionary& old);

            /**
             * @brief Construct a new Dictionary object
             */
            Dictionary();

            /**
             * @brief Destroy the Dictionary object
             */
            ~Dictionary();

            /**
             * @brief Get value by key
             * @tparam T Type of value
             * @param key String key (e.g. key1.key2)
             * @return Value or null if value not found
             */
            template<typename T>
            T get(std::string key);

            /**
             * @brief Set value of key
             * @tparam T Type of value
             * @param key String key (e.g. key1.key2)
             * @param value Value for key
             */
            template<typename T>
            void set(std::string key, T value);

            /**
             * @brief Remove value of key from this dictionary
             * @param key String key (e.g. key1.key2)
             */
            void remove(std::string key);

            /**
             * @brief Clear this dictionary
             */
            void clear();

            /**
             * @brief Get size of this dictionary
             * @return This dictionary size 
             */
            int size();

            /**
             * @brief Copy this dictionary
             * @return New Dictionary object
             */
            Dictionary copy();

            /**
             * @brief Convert this dictionary to map
             * @return Map object
             */
            std::map<std::string, std::any> asMap();
    };
}

#endif