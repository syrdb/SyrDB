/*
    SyrDB/Dictionary - Dictionary type
    [dictionary.cpp] - Main file
    Made with ❤ for you
    Distributed under the BSL license (see LICENSE file)
*/

#include <iostream>
#include <string>
#include <map>
#include "../utils/stringutils.h"
#include "dictionary.h"

namespace TheStngularity::SyrDB {
    Dictionary::Dictionary() {
        this->data = {};
    }

    Dictionary::Dictionary(std::map<std::string, std::any> data) {
        this->data = data;
    }

    // Get any value from data by key
    template<class T>
    T Dictionary::get(std::string key) {
        return (T) this->get<std::string>(key).c_str();
    }

    // Set any value of key
    template<class T>
    void Dictionary::set(std::string key, T value) {
        std::cout << key << ": " << value << std::endl;
    }

    // Convert this type to map
    std::map<std::string, std::any> Dictionary::asMap() {
        return this->data;
    }
}