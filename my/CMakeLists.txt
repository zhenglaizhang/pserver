cmake_minimum_required(VERSION 3.3)

project(my)

add_definitions(-std=c++11)

set(HEADER_FILES
        conf.h str_algo.h thread_pool.h)

set(SOURCE_FILES
        thread_pool.cpp)

add_library(my STATIC ${SOURCE_FILES} ${HEADER_FILES})