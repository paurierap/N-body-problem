# CMAKE version
cmake_minimum_required(VERSION 3.10)

# Project name
project(N-body-problem)

# Create Static Library for Vector2D
add_library(Vector2D_lib 
    STATIC 
        src/Vector2D.cpp
)   
target_include_directories(Vector2D_lib 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# Set SOURCES variable
set(SOURCES
    src/System.cpp
    src/Body.cpp
    src/main.cpp
)
# Also: file(GLOB SOURCES "*.cpp")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add SOURCES to build target nbody
add_executable(nbody ${SOURCES})

# Include directories using -I compilation flag
target_include_directories(nbody
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
target_compile_options(nbody 
    PRIVATE 
        -Wall -Wextra -pedantic
)
target_link_libraries(nbody
    PRIVATE
        Vector2D_lib    
)

# Copy input "bodies.txt" into the build directory
configure_file(${CMAKE_SOURCE_DIR}/bodies.txt 
    ${CMAKE_BINARY_DIR}/bodies.txt 
    COPYONLY
)
