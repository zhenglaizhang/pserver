cmake_minimum_required(VERSION 3.3)
project(cxx)

#[[ this is a
 block comment ]]
message(STATUS ${CMAKE_SYSTEM}) # comple system name
message(STATUS ${CMAKE_SYSTEM_NAME}) # short system name
# we are better to detect os type with the 2 variables

message(STATUS ${CMAKE_C_COMPILER})
message(STATUS ${CMAKE_CXX_COMPILER})
message(STATUS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
message(STATUS ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})

# detect os type
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MAC_OS_X TRUE)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINUX TRUE)  # or UNIX AND NOT APPLE?
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")


# Boost setup
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

if (WIN32)  # True on Windows system, including win64 and Cygwin
    message(STATUS "Cmaking on Windows")
    set(BOOST_ROOT "C:/boost159")
    #    set(Boost_INCLUDE_DIR "c:/boost159")
    #    set(BOOST_LIBRARY_DIR "c:/boost159/lib")
elseif (${MAC_OS_X})
    message(STATUS "Cmaking on Mac")
    set(BOOST_ROOT "/usr/local/Cellar/boost/1.58.0/")
    #    set(BOOST_INCLUDE_DIR "/usr/local/Cellar/boost/1.58.0/include")
    #    set(BOOST_LIBRARY_DIR "/usr/local/Cellar/boost/1.58.0/lib")
elseif (${LINUX}) # UNIX is set for True for UNIX and UNIX like OS.
    message(STATUS "Cmaking on Linux")
endif (WIN32)


# http://stackoverflow.com/questions/28887680/linking-boost-library-with-boost-use-static-lib-off-on-windows
# https://cmake.org/cmake/help/v2.8.8/cmake.html#module%3aFindBoost
if (WIN32)
    find_package(Boost 1.59.0)
elseif (${MAC_OS_X})
    find_package(Boost 1.58.0 REQUIRED COMPONENTS regex system log log_setup program_options)
endif (WIN32)

if (Boost_FOUND)
    message(STATUS "Boost found")
    message(STATUS "Boost_INCLUDE_DIRS: " ${Boost_INCLUDE_DIRS})
    message(STATUS "BOOST_LIBRARY_DIRS: " ${BOOST_LIBRARY_DIRS})
    message(STATUS "BOOST_LIBRARIES: " ${Boost_LIBRARIES})
    include_directories(${Boost_INCLUDE_DIR})
else ()
    message(FATAL "boost not found")
endif ()

if (${MAC_OS_X})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -stdlib=libstdc++")
endif ()

set(SOURCE_FILES main.cpp)
add_executable(pserver_run ${SOURCE_FILES})

include_directories(server)


add_subdirectory(my)
add_subdirectory(my_tests)
#add_subdirectory(server)
# also remove server from link_lib...
add_subdirectory(server_tests)


target_link_libraries(pserver_run ${Boost_LIBRARIES})

