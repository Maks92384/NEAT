#pragma once

// Files
#include "Population/Population.hpp"

// Libraries
#include <memory>
#include <vector>

using namespace std;

class NEAT {
    static vector<unique_ptr<Population>> populations;

public:
    NEAT() = delete;

    static Population& createPopulation(size_t inputNodeCount, size_t outputNodeCount);
    static Population& createPopulation(size_t inputNodeCount, size_t outputNodeCount, size_t populationSize);
    static Population& getPopulationAt(size_t index);
    static size_t getPopulationCount();
};