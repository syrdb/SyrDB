/*
    SyrDB/Dictionary - Dictionary type
    [dictionary.h] - Main file (Annotation)
    Made with ❤ for you
    Distributed under the BSL license (see LICENSE file)
*/

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <map>

typedef std::map<std::string, std::string> stringMap;

namespace TheStngularity::SyrDB {
    /**
     * @brief Dictionary type
     */
    class Dictionary {
        private:
            stringMap data;

            Dictionary parseDictionary(std::string string);

        public:
            Dictionary();
            Dictionary(stringMap data);

            /**
             * @brief Get any value from data by key
             * @tparam T Type of get
             * @param key Key (key1.key2...)
             * @return Any type value
             */
            template<typename T>
            T get(std::string key);

            /**
             * @brief Set any value of key
             * @tparam T Type of set
             * @param key Key (key1.key2...)
             * @param value Value of set
             */
            template<typename T>
            void set(std::string key, T value);

            /**
             * @brief Convert this type to map
             * @return Map
             */
            stringMap asMap();
    };
}

#endif