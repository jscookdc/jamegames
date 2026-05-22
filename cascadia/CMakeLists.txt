cmake_minimum_required(VERSION 3.16)
project(cascadia VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(cascadia ${SOURCES})

target_include_directories(cascadia PRIVATE src)

target_compile_options(cascadia PRIVATE -Wall -Wextra -pedantic)

# glog
find_package(glog REQUIRED)
target_link_libraries(cascadia glog::glog)