cmake_minimum_required(VERSION 3.3)

project(my_tests)

add_definitions(-std=c++11)

set(HEADER_FILES
        )

set(SOURCE_FILES
        thread_pool_tests.cpp thread_pool_tests.h)

add_library(my_tests STATIC ${SOURCE_FILES} ${HEADER_FILES})