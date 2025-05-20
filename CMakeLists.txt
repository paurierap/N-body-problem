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
    src/Simulation.cpp
    src/Body.cpp
    src/main.cpp
    src/Recorder.cpp
)
# Also: file(GLOB SOURCES "*.cpp")

# Add SOURCES to build target nbody
add_executable(nbody ${SOURCES})

# Compile features and flags:
target_compile_features(nbody PRIVATE cxx_std_20)
target_compile_features(Vector2D_lib PRIVATE cxx_std_20)
target_compile_options(nbody 
    PRIVATE 
        -Wall -Wextra -pedantic
)

# Include directories using -I compilation flag
target_include_directories(nbody
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/Integrator
)
target_link_libraries(nbody
    PRIVATE
        Vector2D_lib    
)

# Copy input "bodies.txt" into the build directory
configure_file(${CMAKE_SOURCE_DIR}/initial-conditions.csv 
    ${CMAKE_BINARY_DIR}/initial-conditions.csv  
    COPYONLY
)
