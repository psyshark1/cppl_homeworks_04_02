cmake_minimum_required (VERSION 3.8)

project (02)

add_executable (02 02.cpp Lists.cpp Lists.h)

add_subdirectory(catch2)

add_executable (02test 02test.cpp Lists.cpp Lists.h)

target_link_libraries(02test PRIVATE Catch2::Catch2)