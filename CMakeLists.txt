cmake_minimum_required(VERSION 2.8.4)
project(matam_ex2_exam_details)
set(CMAKE_CXX_STANDARD 11)

set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")
set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})
include_directories(.)

add_executable(exam_details exam_details.cpp)