#pragma once

//Files
#include "Species.hpp"
#include "../Network/NeuralNetwork.hpp"

// Libraries
#include <vector>

using namespace std;

class Population {
    vector<Species> species;
    vector<NeuralNetwork> phenotypes;

    size_t inputNodeCount;
    size_t outputNodeCount;

public:
    Population(size_t inputNodeCount, size_t outputNodeCount, size_t size);
    Population(size_t inputNodeCount, size_t outputNodeCount);

    void generateNewPopulation(size_t inputNodeCount, size_t outputNodeCount, size_t size);
    void generateNewPopulation(size_t inputNodeCount, size_t outputNodeCount);
    void generateNewPopulation();

    void generatePhenotypes();

    void evolve();

    size_t getSize() const;
};