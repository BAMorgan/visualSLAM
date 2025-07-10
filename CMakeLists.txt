cmake_minimum_required(VERSION 3.15)
project(visualSLAM)

set(CMAKE_CXX_STANDARD 20)

# Include header directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/eigen)

# Shared library target
add_library(visualSLAMlib SHARED
        library.cpp
        eigen/eigen_test.cpp
)

# Executable target
add_executable(visualSLAM
        main.cpp
)

# Link the library to the executable
target_link_libraries(visualSLAM PRIVATE visualSLAMlib)
