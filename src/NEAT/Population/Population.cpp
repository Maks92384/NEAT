// Files
#include "Population.hpp"

// Libraries
#include <stdexcept>

Population::Population(size_t inputNodeCount, size_t outputNodeCount, size_t size) :
    species(1),
    phenotypes(size),
    inputNodeCount(inputNodeCount),
    outputNodeCount(outputNodeCount) {

    generateNewPopulation();
}

Population::Population(size_t inputNodeCount, size_t outputNodeCount) :
    Population(inputNodeCount, outputNodeCount, 1) {}

void Population::generateNewPopulation(size_t inputNodeCount, size_t outputNodeCount, size_t size) {
    species = vector<Species>(1);
    phenotypes = vector<NeuralNetwork>(size);

}

void Population::generateNewPopulation(size_t inputNodeCount, size_t outputNodeCount) {
    generateNewPopulation(inputNodeCount, outputNodeCount, getSize());
}

void Population::generateNewPopulation() {
    generateNewPopulation(inputNodeCount, outputNodeCount);
}

void Population::evolve() {

}

size_t Population::getSize() const {
    return phenotypes.size();

    size_t size = 0;

    for (Species singleSpecies : species)
        size += singleSpecies.getSize();

    if (size != phenotypes.size())
        throw length_error("population size does not match phenotypes size");

    return size;
}
