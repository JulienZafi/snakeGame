# set cmake required version
cmake_minimum_required(VERSION 3.22)

# set project name
project(snakeGame VERSION 1.0.1 LANGUAGES C CXX)

# Set compiler options
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	# MP build for MSVC
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /EHsc")
endif()

# Project declaration
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.hpp")
add_executable(snakeGame ${SOURCES})
target_include_directories(snakeGame PUBLIC "include/")

# cpp17
target_compile_features(snakeGame PUBLIC cxx_std_17)
