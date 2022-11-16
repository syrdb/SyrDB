cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Check build type
if((CMAKE_BUILD_TYPE STREQUAL "Debug") OR (CMAKE_BUILD_TYPE STREQUAL ""))
	set(DEBUG_MODE 1)
else()
	set(DEBUG_MODE 0)
endif()

# Project info
project(syrdb
		VERSION 0.0.1
		DESCRIPTION "SyrDB Server"
		HOMEPAGE_URL "https://github.com/TheStngularity/SyrDB")

set(CMAKE_CXX_STANDARD 20)

# Version info
execute_process(COMMAND git describe --always --abbrev=8
				WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
				OUTPUT_VARIABLE GIT_HASH
				OUTPUT_STRIP_TRAILING_WHITESPACE)

set(VERSION "${PROJECT_VERSION}a1.dev1-${GIT_HASH}")

# Enable testing
enable_testing()

# Info
message("")
message("SyrDB Version: " ${VERSION})
message("Description:   " ${PROJECT_DESCRIPTION})
message("Project URL:   " ${PROJECT_HOMEPAGE_URL})
message("")

# Sources
add_subdirectory(src)

# Testing
add_subdirectory(tests)