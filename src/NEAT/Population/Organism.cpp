// Files
#include "Organism.hpp"

// Libraries
#include <iostream>

Organism::Organism(uint16_t inputNodeCount, uint16_t outputNodeCount, const uint32_t &globalInnovationNumber) :
    globalInnovationNumber(globalInnovationNumber),
    genotype(inputNodeCount, outputNodeCount, globalInnovationNumber),
    phenotype(genotype) {
}

void Organism::display(size_t index) const {
    genotype.display(index);
}
