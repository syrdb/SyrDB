# SyrDB Core
Main component of database. All main operations happening here.

## Components
- **Logger** (`logger.h`, `logger.cpp`)
  > Logger needed for informate database users of current state and display warnings, errors or debug information.
- **Task Manager** (`managers/task_manager/*`)
  > In order not to lose data when writing or not to give out-of-date data after reading, all tasks are performed in turn. To implement this queue, this manager is needed.