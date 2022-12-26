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

#ifndef TASK_H_
#define TASK_H_

#include <iostream>
#include <vector>

namespace SyrDB::TaskManager {
    /**
     * @brief Enumeration of task types
     */
    enum TaskType {
        NONE = 0xff,

        AUTHORIZATION = 0x00,
        SERVER_INFORMATION = 0x01,
        UPDATE_SERVER = 0x02,

        DATABASES_LIST = 0x03,
        CREATE_DATABASE = 0x04,
        DROP_DATABASE = 0x05,
        UPDATE_DATABASE = 0x06,

        COLLECTIONS_LIST = 0x07,
        CREATE_COLLECTION = 0x08,
        DROP_COLLECTION = 0x09,
        UPDATE_COLLECTION = 0x0A,

        INSERT_ITEM = 0x0B,
        UPDATE_ITEM = 0x0C,
        UPDATE_MANY_ITEMS = 0x0D,
        DROP_ITEM = 0x0E,
        DROP_MANY_ITEMS = 0x0F,
        FIND_ITEM = 0x10,
        FIND_MANY_ITEMS = 0x11,

        NEW_USER = 0x12,
        UPDATE_USER = 0x13,
        DELETE_USER = 0x14
    };

    class ITask {
        private:
            TaskType type;
        
        public:
            /**
             * @brief Get type of this task
             * @return TaskType
             */
            TaskType getType();

            /**
             * @brief Get fields of this task
             * @return std::vector<std::string> 
             */
            std::vector<std::string> getFields();
    };
}

#endif