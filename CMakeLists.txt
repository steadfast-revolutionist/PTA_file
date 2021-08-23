cmake_minimum_required(VERSION 3.0)

project(PAT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE DEBUG)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(a.out src/PAT_34.cpp)
