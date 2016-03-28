cmake_minimum_required(VERSION 3.3)

PROJECT (play_code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# 添加 math 子目录
#set(SOURCE_FILES main.cpp helloworld.cpp helloworld.h)
#MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
#MESSAGE(STATUS "This is SOURCE dir "${HELLO_SOURCE_DIR})

add_subdirectory(leetcode/329)



#add_executable(First_Test ${SOURCE_FILES} helloworld.cpp helloworld.h)