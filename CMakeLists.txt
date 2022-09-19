cmake_minimum_required(VERSION 3.12)

project(syrdb
		VERSION 0.0.1
		DESCRIPTION "A DB using BDSF (or BSON) as data storage and writed on C++"
		HOMEPAGE_URL "https://github.com/TheStngularity/SyrDB"
		LANGUAGES cxx)
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(src)