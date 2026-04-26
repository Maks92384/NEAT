#pragma once

//Files
#include "../Population/Population.hpp"

// Libraries
#include <vector>

using namespace std;

class Simulation {
    vector<Population> population;
    bool running;

public:
    Simulation();

    void setPopulationSize(size_t size);

    size_t getPopulationSize();
};