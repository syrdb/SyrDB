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