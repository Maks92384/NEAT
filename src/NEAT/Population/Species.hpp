#pragma once

// Files
#include "../Genome/Genome.hpp"
#include "Organism.hpp"

// Libraries
#include <memory>
#include <vector>

using namespace std;

class Species {
    inline static mt19937 random {
        random_device{}()
    };

    vector<Organism*> organisms;

public:
    Species();

    void add(Organism* organism);
    void clear();

    Organism* getRepresentative();

    size_t getSize() const;
    Organism* getOrganismAt(size_t index);
};