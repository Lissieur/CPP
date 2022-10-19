#jamais utilisé ce truc de mor
cmake_minimum_required(VERSION 3.0)

project(TPCPP)

add_executable(main main.cc)

add_library(sources SHARED main.cc vector.cc)

target_link_libraries(main sources)
