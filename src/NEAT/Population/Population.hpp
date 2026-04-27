#pragma once

//Files
#include "../Genome/Genome.hpp"
#include "../Network/NeuralNetwork.hpp"

// Librarioes
#include <vector>

using namespace std;

class Population {
    vector<Genome> genotypes;
    vector<NeuralNetwork> phenotypes;

public:
    Population(size_t size);
    Population();

    void setSize(size_t size);
    size_t getSize();
};