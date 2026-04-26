cmake_minimum_required(VERSION 3.28)
project(NEAT LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(test src/main.cpp
        src/configuration.hpp
        src/NEAT/NEAT.cpp
        src/NEAT/NEAT.hpp
)

target_compile_features(test PRIVATE cxx_std_17)

file(GLOB SRC_FILES src/NEAT/*.cpp)
add_library(NEAT STATIC ${SRC_FILES})
target_include_directories(NEAT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)