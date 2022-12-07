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
#include "resources/verinfo.h"
#include "core/logger.h"
#include "types/dictionary.h"

int main() {
    TheStngularity::SyrDB::Logger logger = TheStngularity::SyrDB::Logger(
        TheStngularity::SyrDB::LoggerLevel::DEBUG, "", "none", true);
    
    logger.info("SyrDB v" + std::string(VERSION));
    logger.info("Project URL: " + std::string(URL) + "\n");

    #if IS_DEBUG == 1
    logger.info("test");
    logger.warn("test");
    logger.error("test");
    logger.debug("test");

    TheStngularity::SyrDB::Dictionary dict = TheStngularity::SyrDB::Dictionary();
    //dict.set<std::string>("text", "Hello, World");
    //dict.set<short>("short", 5);
    //dict.set<bool>("bool", true);
    //dict.set<TheStngularity::SyrDB::Dictionary>("dict", dict);
    //dict.get<std::string>("text");
    //logger.info(dict.get<std::string>("text"));
    //logger.info(std::to_string(dict.get<short>("short")));
    //logger.info(dict.get<bool>("bool") ? "true" : "false");
    //std::cout << dict.get<TheStngularity::SyrDB::Dictionary>("dict").asMap().empty() << std::endl;
    #endif

    return 0;
}