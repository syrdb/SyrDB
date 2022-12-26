# Components
add_subdirectory(utils)
add_subdirectory(core)

# Executable
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/verinfo.h.in ${CMAKE_CURRENT_SOURCE_DIR}/resources/verinfo.h)

if(APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE main.cpp)
else()
    add_executable(${PROJECT_NAME} main.cpp)
endif()

if(DEFINED OUTPUT_NAME)
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${OUTPUT_NAME})
endif()

# About
if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        BUNDLE True
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/resources/app.plist
    )
elseif(WIN32 AND MSVC)
    add_definitions(-DCHECKNEWVERSION)
    target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/resources/app.rc") 
endif()

# Link libraries
target_link_libraries(${PROJECT_NAME} SyrDB-Logger)
target_link_libraries(${PROJECT_NAME} SyrDB-TaskManager)
# TODO: target link libraries