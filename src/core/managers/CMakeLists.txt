add_library(SyrDB-TaskManager
            task.cpp
            task_manager.cpp)
target_link_libraries(SyrDB-TaskManager SyrDB-Dictionary)