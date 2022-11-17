cmake_minimum_required(VERSION 3.0)

# set the C++ standard
# set(CMAKE_CXX_COMPILER=/usr/bin/g++)
# set(CMAKE_C_COMPILER=c=gcc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(cartesian_vector_variable)

# add the lib
#add_library(mysource SHARED vector.cc)

# add another
#add_library(mysource_2 SHARED sources_2.cpp)

# add the executable
add_executable(main main.cc vector.cc)

# do not forget to link
#target_link_libraries(main mysource)

#target_link_libraries(main mysource_2)

# Compilation optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")