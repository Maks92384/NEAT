#pragma once

// Libraries
#include <cstdint>


class ConnectionGene {
    const float weight;

    const uint32_t innovation;

    const uint16_t inNode;
    const uint16_t outNode;

    bool enabled;

public:
    ConnectionGene(uint16_t inNode, uint16_t outNode, float weight, uint32_t innovation);
    ConnectionGene(uint16_t inNode, uint16_t outNode, float weight, uint32_t innovation, bool enabled);
    void display() const;
};
