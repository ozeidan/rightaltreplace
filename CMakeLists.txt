cmake_minimum_required(VERSION 3.0)

project(rightaltreplace)

add_executable(rightaltreplace rightaltreplace.c)
target_compile_options(rightaltreplace PRIVATE -Wall -Wextra)

install(TARGETS rightaltreplace RUNTIME DESTINATION bin)
