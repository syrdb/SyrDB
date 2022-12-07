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
#include <vector>
#include "task.h"

namespace TheStngularity::SyrDB {
    /**
     * @brief Task manager class
     */
    class TaskManager {
        private:
            std::vector<Task> tasks;

        public:
            TaskManager();

            /**
             * @brief Get size of tasks queue
             * @return Size
             */
            inline std::size_t size();

            /**
             * @brief Get current task
             * @return Current task or empty task
             */
            Task current();

            /**
             * @brief Add task to queue
             * @param task Task object
             */
            void addTask(Task task);

            /**
             * @brief Add task to queue
             * @param task Link to task object
             */
            void addTask(Task& task);

            /**
             * @brief Get next task and remove current task
             * @return Next task object or empty task if tasks queue is empty
             */
            Task next();

            /**
             * @brief Cancel any task
             * @param index Index of task
             */
            void cancelTask(int index);
    };
}

#endif