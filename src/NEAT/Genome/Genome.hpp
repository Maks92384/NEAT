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

    vector<NodeGene> nodes;
    vector<ConnectionGene> connections;

public:
    Genome(uint16_t inputNodeCount, uint16_t outputNodeCount);
};