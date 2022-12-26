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
#include <queue>
#include "task.h"
#include "manager.h"

namespace SyrDB::TaskManager {
    static SyrDB::TaskManager::Manager* instance;

    Manager::Manager() {
        instance = this;
    };

    Manager::Manager(std::queue<ITask> queue) : taskQueue(queue) {
        instance = this;
    };

    Manager::~Manager() {
        instance = nullptr;
    };

    ITask Manager::next() {
        this->taskQueue.pop();
        return this->taskQueue.front();
    }

    void Manager::add(ITask task) {
        this->taskQueue.push(task);
    }

    void Manager::clear() {
        std::queue<ITask> empty;
        std::swap(this->taskQueue, empty);
        delete &empty;
    }

    std::size_t Manager::size() {
        return this->taskQueue.size();
    }

    std::queue<ITask> Manager::getQueue() {
        return this->taskQueue;
    }

    Manager* Manager::getInstance() {
        if(instance == nullptr)
            Manager();  // Init manager for create new instance
        return instance;
    }
}