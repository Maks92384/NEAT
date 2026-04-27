// Files
#include "Population.hpp"

Population::Population(size_t size) : genotypes(size), phenotypes(size) {}

Population::Population() : Population(0) {}

void Population::setSize(size_t size) {
    genotypes.resize(size);
    phenotypes.resize(size);
}

size_t Population::getSize() {
    return genotypes.size();
}
