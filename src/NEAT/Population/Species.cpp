#include "Species.hpp"

Species::Species(size_t size) : genotypes(size) {}

Species::Species() : Species(0) {}

size_t Species::getSize() const {
    return genotypes.size();
}
