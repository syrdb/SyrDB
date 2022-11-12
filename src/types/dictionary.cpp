/*
    SyrDB/Dictionary - Dictionary type
    [dictionary.cpp] - Main file
    Made with ❤ for you
    Distributed under the BSL license (see LICENSE file)
*/

#include <iostream>
#include <vector>
#include <variant>
#include <string>
#include <map>
#include <type_traits>
#include "../utils/stringutils.h"
#include "dictionary.h"

namespace TheStngularity::SyrDB {
    Dictionary::Dictionary() {
        this->data = {};
    }

    Dictionary::Dictionary(stringMap data) {
        this->data = data;
    }

    Dictionary Dictionary::parseDictionary(std::string string) {
        stringMap map;

        std::string value = TheStngularity::SyrDB::StrU::split(string, ':')[1];
        for(std::string kv : TheStngularity::SyrDB::StrU::split(value, ';')) {
            std::vector<std::string> keyAndValue = TheStngularity::SyrDB::StrU::split(kv, '=');
            map.insert(std::make_pair(keyAndValue[0], keyAndValue[1]));
        }
        
        return Dictionary(map);
    }

    // Get any value from data by key
    template<typename T>
    T Dictionary::get(std::string key) {
        if(std::is_same<T, std::string>::value) {
            std::variant<std::string, stringMap> value = this->data;
            for(std::string k : TheStngularity::SyrDB::StrU::split(key, '.')) {
                value = std::get<stringMap>(value)[k];

                if(TheStngularity::SyrDB::StrU::split(std::get<std::string>(value), ':')[0] == "$dictionary")
                    value = this->parseDictionary(std::get<std::string>(value));
            }

            return std::get<std::string>(value);
        } else if(std::is_same<T, bool>::value) {
            return this->get<std::string>(key) == "1";
        } else if(std::is_same<T, Dictionary>::value) {
            std::variant<std::string, stringMap> value = this->data;
            for(std::string k : TheStngularity::SyrDB::StrU::split(key, '.'))
                value = std::get<stringMap>(value)[k];

            return this->parseDictionary(std::get<std::string>(value));
        }
        
        return (T) this->get<std::string>(key).c_str();
    }

    // Set any value of key
    template<typename T>
    void Dictionary::set(std::string key, T value) {
        if(std::is_same<T, std::string>::value) {
            this->data.insert(std::make_pair(key, value));
        } else if(std::is_same<T, bool>::value) {
            this->set<std::string>(key, std::to_string(value));
        } else if(std::is_same<T, Dictionary>::value) {
            std::string* result = new std::string("$dictionary:");
            stringMap map = value.asMap();

            int index = 0;
            for(stringMap::iterator iter = map.begin(); iter != map.end(); ++iter) {
                *result += iter->first + "=" + iter->second;
                if(index < map.size() - 1) *result += ";";
                index++;
            }

            delete &map; delete &index;
            this->set<std::string>(key, *result);
            delete result;
        } else {
            this->set<std::string>(key, std::to_string(value));
        }
    }

    // Convert this type to map
    stringMap Dictionary::asMap() {
        return this->data;
    }
}