// Files
#include "Population.hpp"

Population::Population(size_t size) : genomes(size) {}

void Population::setSize(size_t size) {
    genomes.resize(size);
}

size_t Population::getSize() {
    return genomes.size();
}
