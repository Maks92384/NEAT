#pragma once

// Files
#include "NodeGene.hpp"
#include "ConnectionGene.hpp"

// Libraries
#include <vector>


class Genome {
    const uint32_t& globalInnovationNumber;

    std::vector<NodeGene> nodes;
    std::vector<ConnectionGene> connections;

public:
    Genome(uint16_t inputNodeCount, uint16_t outputNodeCount, const uint32_t& globalInnovationNumber);
    Genome(uint16_t inputNodeCount, uint16_t outputNodeCount, uint32_t&&) = delete;

    void mutate(float weightMutationRate, float newWeightRate, float newNodeRate, float newConnectionRate);

    void display(size_t index) const;
};