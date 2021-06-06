cmake_minimum_required(VERSION 2.8.4)
project(matam_ex2_exam_details)

set(CMAKE_CXX_STANDARD 11)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})


add_executable(examDetails examDetails.cpp part_a_test.cpp)

