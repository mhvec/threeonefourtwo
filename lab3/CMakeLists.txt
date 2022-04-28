cmake_minimum_required(VERSION 3.22)
project(lab3test)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3test main.cpp student.h instructor.h term.h course.h section.h college.h io.cpp io.h agg.cpp college.cpp)
