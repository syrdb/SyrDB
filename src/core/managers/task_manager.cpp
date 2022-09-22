/*
    SyrDB/TaskManager - Manager of tasks (For example, database:create and database:drop)
    [task_manager.cpp] - Main file
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#include <iostream>
#include <vector>
#include "task.h"
#include "task_manager.h"

namespace TheStngularity::SyrDB {
    TaskManager::TaskManager() {
        this->tasks = {};
    }

    // Get size of tasks queue
    inline std::size_t TaskManager::size() {
        return this->tasks.size();
    }

    // Get current task
    Task TaskManager::current() {
        if(this->tasks.size() > 0) return this->tasks[0];
        return Task(TaskType::NONE, Dictionary());
    }

    // Add task to queue
    void TaskManager::addTask(Task task) {
        this->tasks.push_back(task);
    }

    void TaskManager::addTask(Task& task) {
        this->tasks.push_back(task);
    }

    // Get next task and remove current task
    Task TaskManager::next() {
        this->tasks.erase(this->tasks.begin());
        return this->current();
    }

    // Cancel any task
    void TaskManager::cancelTask(int index) {
        this->tasks.erase(this->tasks.begin() + index);
    }
}