#pragma once

// Files
#include "../Genome/Genome.hpp"

// Libraries
#include <vector>

using namespace std;

class Species {
    vector<Genome> genotypes;

public:
    Species(size_t size);
    Species();

    void add(const Genome& genotype);
    void clear();

    size_t getSize() const;
    Genome getGenotypeAt(size_t index) const;
};