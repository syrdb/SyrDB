/*
    SyrDB/TaskManager - Manager of tasks (For example, database:create and database:drop)
    [task_manager.h] - Main file (Annotation)
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
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