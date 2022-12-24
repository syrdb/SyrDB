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

#include "dictionary.h"
#include "../utils/stringutils.h"
#include <iostream>
#include <map>
#include <any>

namespace TheStngularity::SyrDB {
    Dictionary::Dictionary(std::map<std::string, std::any> d): data(d) {}
    Dictionary::Dictionary(Dictionary& old): data(old.asMap()) {}
    Dictionary::Dictionary(): data({}) {}
    Dictionary::~Dictionary() {delete &this->data;}

    template<typename T>
    T Dictionary::get(std::string key) {
        std::any output = this->data;
        std::vector<std::string> keys = TheStngularity::SyrDB::StrU::split(key, '.');
        std::string current = keys.at(0)
        while(current != keys.at(keys.size()-1)) {
            if(!output.type().name() == "N14TheStngularity5SyrDB10DictionaryE")  // TheStngularity::SyrDB::Dictionary
                break;

            
        }
    }
}