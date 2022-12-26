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

#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include <iostream>
#include <queue>
#include "task.h"

namespace SyrDB::TaskManager {
    /**
     * @brief Manager of tasks
     */
    class Manager {
        private:
            std::queue<ITask> taskQueue;
            
        public:
            Manager();
            Manager(std::queue<ITask> queue);
            ~Manager();

            /**
             * @brief Get next task and remove current from queue
             * @return ITask
             */
            ITask next();

            /**
             * @brief Add any task to queue
             * @param task New task
             */
            void add(ITask task);

            /**
             * @brief Clear the task queue
             */
            void clear();

            /**
             * @brief Get size of queue (task count)
             * @return std::size_t
             */
            std::size_t size();

            /**
             * @brief Get task queue
             * @return std::queue<ITask>
             */
            std::queue<ITask> getQueue();

            /**
             * @brief Get last object of TaskManager class
             * @return TaskManager
             */
            static Manager* getInstance();
    };
}

#endif