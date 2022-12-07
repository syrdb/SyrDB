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