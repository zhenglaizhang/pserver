cmake_minimum_required(VERSION 3.3)
project(cxx)

#[[ this is a
 block comment ]]
message(STATUS ${CMAKE_SYSTEM}) # comple system name
message(STATUS ${CMAKE_SYSTEM_NAME}) # short system name
# we are better to detect os type with the 2 variables


# detect os type
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MAC_OS_X TRUE)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINUX TRUE)  # or UNIX AND NOT APPLE?
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if (WIN32)  # True on Windows system, including win64 and Cygwin
    message(STATUS "Cmaking on Windows")
    set(BOOST_ROOT "C:/boost159")
    set(Boost_INCLUDE_DIR "c:/boost159")
elseif (${MAC_OS_X TRUE})
    message(STATUS "Cmaking on Mac")
elseif (${LINUX}) # UNIX is set for True for UNIX and UNIX like OS.
    message(STATUS "Cmaking on Linux")
endif (WIN32)

find_package(BOOST 1.59.0)

if (Boost_FOUND)
    message(STATUS "boost found")
    message(STATUS "Boost_INCLUDE_DIR: " ${Boost_INCLUDE_DIR})
    include_directories(${Boost_INCLUDE_DIR})
else ()
    message(FATAL "boost not found")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(pserver_run ${SOURCE_FILES})

include_directories(server)


add_subdirectory(server)
add_subdirectory(server_tests)

target_link_libraries(pserver_run server)

