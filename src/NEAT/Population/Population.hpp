#pragma once

//Files
#include "../Genome/Genome.hpp"

// Librarioes
#include <vector>

using namespace std;

class Population {
    vector<Genome> genomes;
public:
    Population(size_t size);

    void setSize(size_t size);
    size_t getSize();
};