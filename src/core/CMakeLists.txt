add_subdirectory(managers)

# Logger
add_library(SyrDB-Logger logger.cpp)
target_link_libraries(SyrDB-Logger PRIVATE SyrDB-Utils)