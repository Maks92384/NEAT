#pragma once

// Files
#include "Simulation/Simulation.hpp"

// Libraries
#include <memory>
#include <vector>

using namespace std;

class NEAT {
    static vector<unique_ptr<Simulation>> simulations;

public:
    NEAT() = delete;

    static Simulation& createSimulation(size_t inputNodeCount, size_t outputNodeCount);
    static Simulation& createSimulation(size_t inputNodeCount, size_t outputNodeCount, size_t populationSize);
    static Simulation& getSimulationAt(size_t index);
    static size_t getSimulationCount();
};