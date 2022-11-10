/*
    SyrDB/TaskManager - Manager of tasks (For example, database:create and database:drop)
    [task.cpp] - Task class
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#include "../../types/dictionary.h"
#include "task.h"

namespace TheStngularity::SyrDB {
    Task::Task(TaskType type, TheStngularity::SyrDB::Dictionary data) {
        this->type = type;
        this->data = data;
    }

    // Get type of this task
    TaskType Task::getType() {
        return this->type;
    }

    // Get data of this task
    TheStngularity::SyrDB::Dictionary Task::getData() {
        return this->data;
    }
}