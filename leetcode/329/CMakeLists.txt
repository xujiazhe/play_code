cmake_minimum_required(VERSION 3.3)
PROJECT (play_code)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(. longestIncreasingPath)
ADD_EXECUTABLE(hello ${longestIncreasingPath} Solution.cpp)
