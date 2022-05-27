cmake_minimum_required(VERSION 3.2)

project(Complex_Vectors_homework)

set(Complex_Vectors_homework_src main.cpp Autotest.cpp CCVec.cpp CCVec0.cpp CCVec1.cpp)
set(Complex_Vectors_homework_hdr main.h Autotest.h CCVec.h CCVec0.h CCVec1.h Factory.h)

add_executable(${PROJECT_NAME} ${Complex_Vectors_homework_src} ${Complex_Vectors_homework_hdr})