#include "Species.hpp"

Species::Species(size_t size) {}

Species::Species() : Species(0) {}

void Species::add(Genome genotype) {
    genotypes.push_back(genotype);
}

void Species::clear() {
    genotypes.clear();
}

size_t Species::getSize() const {
    return genotypes.size();
}

Genome Species::getGenotypeAt(size_t index) const {
    return genotypes.at(index);
}
