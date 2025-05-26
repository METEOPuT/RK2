cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

enable_testing()

project(RK2)

set(Sources Iterator/ConcreteIterator.cpp Iterator/ConcreteAggregate.cpp
    Iterator/main.cpp)
set(Headers Iterator/ConcreteIterator.h Iterator/ConcreteAggregate.h
    Iterator/IIterator.h Iterator/IAggregate.h)

add_library(Iterator STATIC ${Sources} ${Headers})
target_include_directories(Iterator PUBLIC Iterator)

if(BUILD_TESTS)
    enable_testing()

    add_subdirectory(third-party/gtest)

    target_compile_options(gtest PUBLIC "-Wno-error=maybe-uninitialized")
    target_compile_options(gmock PUBLIC "-Wno-error=maybe-uninitialized")

    add_executable(my_test tests/tests.cpp)
    target_link_libraries(my_test gtest_main gmock_main Iterator)

    add_test(NAME my_test COMMAND my_test)
endif()
