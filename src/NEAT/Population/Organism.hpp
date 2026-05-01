#pragma once

// Files
#include "../Genome/Genome.hpp"
#include "../Network/NeuralNetwork.hpp"

class Organism {
    const uint32_t& globalInnovationNumber;

    Genome genotype;
    NeuralNetwork phenotype;

public:

    Organism(uint16_t inputNodeCount, uint16_t outputNodeCount, const uint32_t& globalInnovationNumber);
    Organism(uint16_t inputNodeCount, uint16_t outputNodeCount, uint32_t&&) = delete;

    void display(size_t index) const;
};
