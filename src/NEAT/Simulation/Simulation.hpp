#pragma once

//Files
#include "../Population/Population.hpp"

// Libraries
#include <vector>

using namespace std;

class Simulation {
    Population population;

    unsigned int generation;

public:
    Simulation();

    size_t getPopulationSize();
    void setPopulationSize(size_t size);
};