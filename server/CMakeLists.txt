cmake_minimum_required(VERSION 3.3)

project(server)

add_definitions(-std=c++11)

set(HEADER_FILES
        time_server.h http_server.h https_server.h message_server.h response.cpp response.h RequestHandler.h)

set(SOURCE_FILES
        time_server.cpp http_server.cpp https_server.cpp message_server.cpp request.cpp request.h lib/http/HttpMessage.cpp lib/http/HttpMessage.h)

add_library(server STATIC ${SOURCE_FILES} ${HEADER_FILES})