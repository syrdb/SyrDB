/*
    SyrDB/Dictionary - Dictionary type
    [dictionary.h] - Main file (Annotation)
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
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

        public:
            Dictionary();
            Dictionary(stringMap data);

            /**
             * @brief Get string value from data by key
             * @param key Key (key1.key2...)
             * @return String value
             */
            std::string getString(std::string key);

            /**
             * @brief Get short value from data by key
             * @param key Key (key1.key2...)
             * @return Short value 
             */
            short getShort(std::string key);

            /**
             * @brief Get integer value from data by key
             * @param key Key (key1.key2...)
             * @return Integer value
             */
            int getInt(std::string key);

            /**
             * @brief Get boolean value from data by key
             * @param key Key (key1.key2...)
             * @return Boolean value
             */
            bool getBoolean(std::string key);

            /**
             * @brief Get dictionary value from data by key
             * @param key Key (key1.key2...)
             * @return Dictionary value
             */
            Dictionary getDictionary(std::string key);

            /**
             * @brief Set string value of key
             * @param key Key (key1.key2...)
             * @param value String value
             */
            void setString(std::string key, std::string value);

            /**
             * @brief Set short value of key
             * @param key Key (key1.key2...)
             * @param value Short value
             */
            void setShort(std::string key, short value);

            /**
             * @brief Set integer value of key
             * @param key Key (key1.key2...)
             * @param value Integer value
             */
            void setInt(std::string key, int value);

            /**
             * @brief Set boolean value of key
             * @param key Key (key1.key2...)
             * @param value Boolean value
             */
            void setBoolean(std::string key, bool value);

            /**
             * @brief Set dictionary value of key
             * @param key Key (key1.key2...)
             * @param value Dictionary value
             */
            void setDictionary(std::string key, Dictionary value);

            /**
             * @brief Convert this type to map
             * @return Map
             */
            stringMap asMap();
    };
}

#endif