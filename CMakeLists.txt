cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(GIT_HASH "92ea0dd")
set(VERSION2P "a1.dev-${GIT_HASH}")
set(BUILD "Alpha development build")

project(syrdb
		VERSION 0.0.1
		DESCRIPTION "A DB using BDSF (or BSON) as data storage and written on C++"
		HOMEPAGE_URL "https://github.com/TheStngularity/SyrDB")
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)