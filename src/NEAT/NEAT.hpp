#pragma once

// Files
#include "Simulation/Simulation.hpp"

// Libraries
#include <vector>

using namespace std;

class NEAT {
    static vector<Simulation> simulations;

public:
    NEAT() = delete;

    static Simulation& createSimulation();
    static Simulation& getSimulationAt(size_t index);
    static size_t getSimulationCount();
};