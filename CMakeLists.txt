cmake_minimum_required(VERSION 3.15)
project(interview-records)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(interview_accumulate
        functions.cpp
        functions.h
        main.cpp)
