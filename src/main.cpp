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
#include "core/managers/task_manager/task.h"
#include "core/managers/task_manager/manager.h"

int main() {
    SyrDB::Logger logger(SyrDB::LoggerLevel::DEBUG, SyrDB::LoggerLevel::DEBUG,
        "./logs", "[dd.mm.yyyy].log", true, true);

    logger.info("Welcome to SyrDB v" + std::string(VERSION));

    #if IS_DEBUG == 1
    logger.info("test");
    logger.warn("test");
    logger.error("test");
    logger.debug("test");
    #endif

    return 0;
}