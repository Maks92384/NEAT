#pragma once

//Files
#include "../Population/Population.hpp"

// Libraries
#include <vector>

using namespace std;

class NEAT;

class Simulation {
    friend class NEAT;

    Population population;

    size_t inputNodeCount;
    size_t outputNodeCount;

    unsigned int generation;

    Simulation(size_t inputNodeCount, size_t outputNodeCount);
    Simulation(size_t inputNodeCount, size_t outputNodeCount, size_t populationSize);

public:

    void nextGeneration();

    void resetSimulation();
    void resetSimulation(size_t populationSize);
    void resetSimulation(size_t inputNodeCount, size_t outputNodeCount);
    void resetSimulation(size_t inputNodeCount, size_t outputNodeCount, size_t populationSize);

    size_t getPopulationSize() const;
    unsigned int getGeneration() const;
    size_t getInputCount() const;
    size_t getOutputCount() const;
};