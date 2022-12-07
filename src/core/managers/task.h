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
#include "../../types/dictionary.h"

namespace TheStngularity::SyrDB {
    /**
     * @brief Task types
     */
    enum class TaskType : unsigned char {
        NONE = 0xFF,

        // Information
        GET_INFO = 0x00,
        GET_STATUS = 0x01,

        // Databases
        DATABASE_LIST = 0x02,
        CREATE_DATABASE = 0x03,
        DROP_DATABASE = 0x04,
        EDIT_DATABASE = 0x05,

        // Collections
        COLLECTIONS_LIST = 0x06,
        CREATE_COLLECTION = 0x07,
        DROP_COLLECTION = 0x08,
        EDIT_COLLECTION = 0x09,

        // Objects (Items)
        INSERT_OBJECT = 0x0A,
        INSERT_MANY_OBJECTS = 0x0B,
        UPDATE_OBJECT = 0x0C,
        UPDATE_MANY_OBJECTS = 0x0D,
        REMOVE_OBJECT = 0x0F,
        REMOVE_MANY_OBJECTS = 0x10,

        // Server
        UPDATE_SERVER = 0x11
    };

    /**
     * @brief Task class
     */
    class Task {
        private:
            TaskType type;
            TheStngularity::SyrDB::Dictionary data;

        public:
            Task(TaskType type, TheStngularity::SyrDB::Dictionary data);

            /**
             * @brief Get type of this task
             * @return Get task type
             */
            TaskType getType();

            /**
             * @brief Get data of this task
             * @return Dictionary object
             */
            TheStngularity::SyrDB::Dictionary getData();
    };
}

#endif