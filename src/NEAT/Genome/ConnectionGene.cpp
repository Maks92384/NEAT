// Files
#include "ConnectionGene.hpp"

// Libraries
#include <iostream>

ConnectionGene::ConnectionGene(uint16_t inNode, uint16_t outNode, float weight, uint32_t innovation, bool enabled) :
    inNode(inNode),
    outNode(outNode),
    weight(weight),
    enabled(enabled),
    innovation(innovation) {
    std::cout << "[Innov: " << innovation << "] "
          << inNode << " -> " << outNode
          << " | Waga: " << weight
          << " | Aktywny: " << (enabled ? "Tak" : "Nie")
          << std::endl;
}

ConnectionGene::ConnectionGene(uint16_t inNode, uint16_t outNode, float weight, uint32_t innovation) :
    ConnectionGene(inNode, outNode, weight, innovation, true) {}
