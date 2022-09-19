/*
    SyrDB/TaskManager - Manager of tasks (For example, database:create and database:delete)
    [task.h] - Task types enum (Annotation)
    Made with ❤ for you
    Distributed under the MIT license (see LICENSE file)
*/

#ifndef TASK_H_
#define TASK_H_

namespace TheStngularity::SyrDB {
    /**
     * @brief Task types enum
     */
    enum class Task {
        GET_INFO = 0;
        // TODO: other tasks
    }
}

#endif