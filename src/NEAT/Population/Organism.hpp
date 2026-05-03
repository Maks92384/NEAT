#pragma once

// Files
#include "../Genome/Genome.hpp"
#include "../Network/NeuralNetwork.hpp"

class Organism {
    const uint32_t& globalInnovationNumber;

    Genome genotype;
    NeuralNetwork phenotype;

    float fitness;

public:

    Organism(uint16_t inputNodeCount, uint16_t outputNodeCount, const uint32_t& globalInnovationNumber);
    Organism(uint16_t inputNodeCount, uint16_t outputNodeCount, uint32_t&&) = delete;

    float getFitness() const;
    void setFitness(float fitness);
    void changeFitness(float delta);

    Organism makeChild(const Organism& partner);

    Genome& getGenotype();
    NeuralNetwork& getPhenotype();

    void display(size_t index) const;
};
