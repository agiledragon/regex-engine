cmake_minimum_required(VERSION 2.8)

project(regex-engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(
"${CMAKE_CURRENT_SOURCE_DIR}/include"
"$ENV{GTEST_HOME}/include"
)

file(GLOB_RECURSE all_files
    test/*.cpp)

link_directories("$ENV{GTEST_HOME}/lib")
add_executable(regex-engine-test ${all_files})
target_link_libraries(regex-engine-test gtest pthread)
