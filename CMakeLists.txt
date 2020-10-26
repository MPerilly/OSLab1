cmake_minimum_required(VERSION 2.8.4)
project(OSLab1C C)

set(CMAKE_C_STANDARD 11)
include_directories(/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include /usr/local/include /usr/include)
add_executable(OSLab1C main.c)
