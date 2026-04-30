#pragma once

//Files
#include "../Population/Population.hpp"

using namespace std;

class NEAT;

class Simulation {
    friend class NEAT;

    static const uint16_t UINT16_ONE;

    Population population;

    uint32_t generation;

    uint16_t inputNodeCount;
    uint16_t outputNodeCount;


    Simulation(uint16_t inputNodeCount, uint16_t outputNodeCount);
    Simulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize);

public:

    void nextGeneration();

    void resetSimulation();
    void resetSimulation(size_t populationSize);
    void resetSimulation(uint16_t inputNodeCount, uint16_t outputNodeCount);
    void resetSimulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize);

    size_t getPopulationSize() const;
    uint32_t getGeneration() const;
    uint16_t getInputCount() const;
    uint16_t getOutputCount() const;
};