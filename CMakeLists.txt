cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

project(btt2 CXX)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(btt2 ${SRC_FILES})

set(CMAKE_CXX_STANDARD 17)

