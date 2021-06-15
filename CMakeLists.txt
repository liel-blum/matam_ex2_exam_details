cmake_minimum_required(VERSION 3.0)
project(matam_ex2_exam_details)

set(CMAKE_CXX_STANDARD 11)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})


#add_executable(examDetails examDetails.cpp part_a_test.cpp)


add_executable(Character part_b/Character.h part_b/Character.cpp part_b/gameTest.cpp part_b/Soldier.h part_b/Soldier.cpp
        part_b/Medic.h
        part_b/Medic.cpp part_b/Sniper.cpp part_b/Sniper.h part_b/Game.cpp part_b/Game.h part_b/Auxiliaries.cpp
        part_b/Auxiliaries.h part_b/Exceptions.h part_b/Exceptions.cpp)