#pragma once

// Files
#include "NodeGene.hpp"
#include "ConnectionGene.hpp"

// Libraries
#include <vector>

using namespace std;

class Genome {
    vector<NodeGene> nodes;
    vector<ConnectionGene> connections;

public:
    Genome();
};