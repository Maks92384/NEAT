// Files
#include "Organism.hpp"

// Libraries
#include <iostream>

using std::max;
using std::cout;
using std::fixed;

Organism::Organism(uint16_t inputNodeCount, uint16_t outputNodeCount, const uint32_t &globalInnovationNumber) :
    globalInnovationNumber(globalInnovationNumber),
    genotype(inputNodeCount, outputNodeCount, globalInnovationNumber),
    phenotype(genotype) {
}

float Organism::getFitness() const {
    return fitness;
}

void Organism::setFitness(float fitness) {
    this->fitness = max(0.0f, fitness);
}

void Organism::changeFitness(float delta) {
    fitness = max(0.0f, fitness + delta);
}

Organism Organism::makeChild(const Organism& partner) {
    Organism child = Organism();

    return child;
}

Genome& Organism::getGenotype() {
    return genotype;
}

NeuralNetwork& Organism::getPhenotype() {
    return phenotype;
}

void Organism::display(size_t index) const {
    cout<<"( fitness: "<<fixed<<getFitness()<<" ) ";
    genotype.display(index);
}
