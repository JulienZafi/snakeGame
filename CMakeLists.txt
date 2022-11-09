# set cmake required version
cmake_minimum_required(VERSION 3.22)

# set project name
project(snakeGame VERSION 1.0.1 LANGUAGES C CXX)

# add src and include dir
add_subdirectories(include)
add_subdirectories(src)
