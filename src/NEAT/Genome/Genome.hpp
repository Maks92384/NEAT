#pragma once

// Files
#include "NodeGene.hpp"
#include "ConnectionGene.hpp"

// Libraries
#include <random>
#include <vector>

using namespace std;

class Genome {
    inline static mt19937 random {
        random_device{}()
    };

    const uint32_t& globalInnovationNumber;

    float fitness;

    vector<NodeGene> nodes;
    vector<ConnectionGene> connections;

public:
    Genome(uint16_t inputNodeCount, uint16_t outputNodeCount, const uint32_t& globalInnovationNumber);
    Genome(uint16_t inputNodeCount, uint16_t outputNodeCount, uint32_t&&) = delete;

    float getFitness() const;
    void setFitness(float fitness);

    void display(size_t index) const;
};