add_library(SyrDB-Dictionary dictionary.cpp)
target_link_libraries(SyrDB-Dictionary PRIVATE SyrDB-Utils)