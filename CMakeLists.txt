cmake_minimum_required(VERSION 3.28)
project(NEAT LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(test src/main.cpp
        src/Configuration.hpp
        src/NEAT/NEAT.cpp
        src/NEAT/NEAT.hpp
        src/NEAT/NeatConfiguration.h
        src/NEAT/Population/Population.cpp
        src/NEAT/Population/Population.hpp
        src/NEAT/Population/Species.cpp
        src/NEAT/Population/Species.hpp
        src/NEAT/Population/Organism.cpp
        src/NEAT/Population/Organism.hpp
        src/NEAT/Genome/Genome.cpp
        src/NEAT/Genome/Genome.hpp
        src/NEAT/Genome/ConnectionGene.cpp
        src/NEAT/Genome/ConnectionGene.hpp
        src/NEAT/Genome/NodeGene.cpp
        src/NEAT/Genome/NodeGene.hpp
        src/NEAT/Network/NeuralNetwork.cpp
        src/NEAT/Network/NeuralNetwork.hpp
)

target_compile_features(test PRIVATE cxx_std_17)

file(GLOB SRC_FILES src/NEAT/*.cpp)
add_library(NEAT STATIC ${SRC_FILES})
target_include_directories(NEAT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)