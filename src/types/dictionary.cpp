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