cmake_minimum_required(VERSION 3.30)
project(visualSLAM)

set(CMAKE_CXX_STANDARD 20)

add_library(visualSLAM SHARED library.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
