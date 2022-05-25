cmake_minimum_required(VERSION 3.21)
project(PRG_LABO_2 C)

set(CMAKE_C_STANDARD 17)
set(DCMAKE_C_FLAGS "-std=c17 -Wall -Wconversion -Wextra –Wsign-conversion -pedantic")

add_executable(PRG_LABO_2 main.c taxe.c vehicule.c)
