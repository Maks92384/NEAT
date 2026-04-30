#pragma once

//Files
#include "Species.hpp"
#include "../Network/NeuralNetwork.hpp"

// Libraries
#include <vector>

using namespace std;

class Population {
    uint32_t globalInnovationNumber;

    uint16_t inputNodeCount;
    uint16_t outputNodeCount;

    vector<Species> species;
    vector<NeuralNetwork> phenotypes;

public:
    Population(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t size);
    Population(uint16_t inputNodeCount, uint16_t outputNodeCount);

    void generateNewPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t size);
    void generateNewPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount);
    void generateNewPopulation(size_t size);
    void generateNewPopulation();

    void generatePhenotypes();

    void evolve();

    size_t getSize() const;
};