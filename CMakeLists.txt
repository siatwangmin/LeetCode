cmake_minimum_required(VERSION 3.5)
project(leetcode)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_executable(leetcode main.cpp)
target_link_libraries(leetcode ${GTEST_LIBRARIES} pthread)