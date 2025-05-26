cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Iterator)

add_library(Iterator STATIC ConcreteAggregate.cpp ConcreteIterator.cpp main.cpp)

target_include_directories(Iterator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
