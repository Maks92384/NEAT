#pragma once

// Files
#include "Organism.hpp"

// Libraries
#include <memory>
#include <vector>

class Species {
    std::vector<Organism*> organisms;

public:
    Species();

    void add(Organism* organism);
    void clear();
    void cull(float cullingThreshold);

    std::vector<std::unique_ptr<Organism>> crossover(size_t offspringCount, float crossoverRate) const;

    Organism getRepresentative() const;
    double getAverageFitness() const;
    size_t getSize() const;
    Organism* getOrganismAt(size_t index);

};