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

    size_t getSize() const;
};