// Files
#include "Population.hpp"

// Libraries
#include <iostream>
#include <stdexcept>

Population::Population(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t size) :
    inputNodeCount(inputNodeCount),
    outputNodeCount(outputNodeCount),
    globalInnovationNumber(inputNodeCount * outputNodeCount) {

    generateNewPopulation(size);
}

Population::Population(uint16_t inputNodeCount, uint16_t outputNodeCount) :
    Population(inputNodeCount, outputNodeCount, 1) {}

void Population::generateNewPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t size) {
    species = vector<Species>(1);
    phenotypes = vector<NeuralNetwork>();

    for (size_t i = 0; i < size; i++)
        species.at(0).add(Genome(inputNodeCount, outputNodeCount));

    generatePhenotypes();
}

void Population::generateNewPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount) {
    generateNewPopulation(inputNodeCount, outputNodeCount, getSize());
}

void Population::generateNewPopulation(size_t size) {
    generateNewPopulation(inputNodeCount, outputNodeCount, size);
}

void Population::generateNewPopulation() {
    generateNewPopulation(inputNodeCount, outputNodeCount);
}

void Population::generatePhenotypes() {
    for (Species& singleSpecies : species)
        for (size_t i = 0; i < singleSpecies.getSize(); i++)
            phenotypes.emplace_back(singleSpecies.getGenotypeAt(i));
}

void Population::evolve() {

}

size_t Population::getSize() const {
    size_t size = 0;

    for (Species singleSpecies : species)
        size += singleSpecies.getSize();

    if (size != phenotypes.size())
        throw length_error("population size does not match phenotypes size");

    return size;
}
