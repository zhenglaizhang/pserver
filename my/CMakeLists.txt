cmake_minimum_required(VERSION 3.3)

project(my)

add_definitions(-std=c++11)

set(HEADER_FILES
        conf.h str_algo.h search.hpp util.hpp List.hpp)

set(SOURCE_FILES
        Sort.hpp SortQuiz.cpp)

add_library(my STATIC ${SOURCE_FILES} ${HEADER_FILES})