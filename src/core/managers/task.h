/*
    SyrDB/TaskManager - Manager of tasks (For example, database:create and database:drop)
    [task.h] - Task class (Annotation)
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#ifndef TASK_H_
#define TASK_H_

#include <iostream>
#include <map>
#include "../types/dictionary.h"

namespace TheStngularity::SyrDB {
    /**
     * @brief Task types
     */
    enum class TaskType : char {
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