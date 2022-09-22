/*
    SyrDB/Dictionary - Dictionary type
    [dictionary.cpp] - Main file
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#include <iostream>
#include <vector>
#include <variant>
#include <string>
#include <map>
#include "../utils/stringutils.h"
#include "dictionary.h"

namespace TheStngularity::SyrDB {
    Dictionary::Dictionary() {
        this->data = {};
    }

    Dictionary::Dictionary(stringMap data) {
        this->data = data;
    }

    // Get string value from data by key
    std::string Dictionary::getString(std::string key) {
        std::string currentKey = "";
        std::variant<std::string, stringMap> value = this->data;
        
        for(std::string k : TheStngularity::SyrDB::StrU::split(key, '.')) {
            currentKey += currentKey.length() == 0 ? "." + k : k;
            if(TheStngularity::SyrDB::StrU::split(std::get<stringMap>(value)[k], ':')[0] == "$dictionary") {
                value = this->getDictionary(currentKey).asMap();
            } else {
                value = std::get<stringMap>(value)[k];
            }
        }

        delete &currentKey;
        return std::get<std::string>(value);
    }

    // Get short value from data by key
    short Dictionary::getShort(std::string key) {
        return (short) this->getString(key).c_str();
    }

    // Get integer value from data by key
    int Dictionary::getInt(std::string key) {
        return (int) this->getString(key).c_str();
    }

    // Get boolean value from data by key
    bool Dictionary::getBoolean(std::string key) {
        return this->getString(key) == "1";
    }

    // Get dictionary value from data by key
    Dictionary Dictionary::getDictionary(std::string key) {
        std::string currentKey = "";
        std::variant<std::string, stringMap> value = this->data;
        
        for(std::string k : TheStngularity::SyrDB::StrU::split(key, '.')) {
            currentKey += currentKey.length() == 0 ? "." + k : k;
            value = std::get<stringMap>(value)[k];
        }

        delete &currentKey;
        value = TheStngularity::SyrDB::StrU::split(std::get<std::string>(value), ':')[1];
        stringMap map;
        for(std::string kv : TheStngularity::SyrDB::StrU::split(std::get<std::string>(value), ';')) {
            std::vector<std::string> keyAndValue = TheStngularity::SyrDB::StrU::split(kv, '=');
            map.insert(std::make_pair(keyAndValue[0], keyAndValue[1]));
        }
        return Dictionary(map);
    }

    // Set string value of key
    void Dictionary::setString(std::string key, std::string value) {
        this->data.insert(std::make_pair(key, value));
    }

    // Set short value of key
    void Dictionary::setShort(std::string key, short value) {
        this->setString(key, std::to_string(value));
    }

    // Set integer value of key
    void Dictionary::setInt(std::string key, int value) {
        this->setString(key, std::to_string(value));
    }

    // Set boolean value of key
    void Dictionary::setBoolean(std::string key, bool value) {
        this->setString(key, value ? "1" : "0");
    }

    // Set dictionary value of key
    void Dictionary::setDictionary(std::string key, Dictionary value) {
        std::string result = "$dictionary:";
        stringMap map = value.asMap();

        int index = 0;
        for(stringMap::iterator iter = map.begin(); iter != map.end(); ++iter) {
            result += iter->first + "=" + iter->second;
            if(index < map.size() - 1) result += ";";
            index++;
        }

        delete &map;
        delete &index;
        this->setString(key, result);
        delete &result;
    }

    // Convert this type to map
    stringMap Dictionary::asMap() {
        return this->data;
    }
}