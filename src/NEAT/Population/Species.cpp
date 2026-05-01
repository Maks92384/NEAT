// Files
#include "Species.hpp"

Species::Species() {}

void Species::add(Organism* organism) {
    organisms.push_back(organism);
}

Organism* Species::getRepresentative() {
    uniform_int_distribution<size_t> organismDistribution(0, organisms.size() - 1);

    return organisms.at(organismDistribution(random));
}

void Species::clear() {
    organisms.clear();
}

size_t Species::getSize() const {
    return organisms.size();
}

Organism* Species::getOrganismAt(size_t index) {
    return organisms.at(index);
}
