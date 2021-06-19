cmake_minimum_required(VERSION 3.0)
project(matam_ex2_exam_details)

set(CMAKE_CXX_STANDARD 11)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})


#add_executable(sortedList.h main.cpp testClass.h examDetails.h examDetails.cpp)
add_executable(a partA/sortedList.h part_a_test.cpp partA/examDetails.cpp partA/examDetails.h)

#
#add_executable(Character partB/Character.h partB/Character.cpp gameTest.cpp partB/Soldier.h partB/Soldier.cpp
#        partB/Medic.h
#        partB/Medic.cpp partB/Sniper.cpp partB/Sniper.h partB/Game.cpp partB/Game.h Auxiliaries.cpp
#        Auxiliaries.h partB/Exceptions.h partB/Exceptions.cpp)