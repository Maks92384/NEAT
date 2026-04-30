// Files
#include "Simulation.hpp"
#include "SimConfiguration.h"

// Libraries
#include <iostream>

using namespace std;

const size_t Simulation::SIZE_ONE = 1;

Simulation::Simulation(size_t inputNodeCount, size_t outputNodeCount, size_t populationSize) :
    population(
        max(SIZE_ONE, inputNodeCount),
        max(SIZE_ONE, outputNodeCount),
        populationSize
    ),
    inputNodeCount(max(SIZE_ONE, inputNodeCount)),
    outputNodeCount(max(SIZE_ONE, outputNodeCount)),
    generation(0) {

    population.generateNewPopulation();
}

Simulation::Simulation(size_t inputNodeCount, size_t outputNodeCount) :
    Simulation(inputNodeCount, outputNodeCount, simConf::defaultPopulationSize) {}

void Simulation::nextGeneration() {
    generation++;
    population.evolve();
}

size_t Simulation::getPopulationSize() const {
    return population.getSize();
}

unsigned int Simulation::getGeneration() const {
    return generation;
}

size_t Simulation::getInputCount() const {
    return inputNodeCount;
}

size_t Simulation::getOutputCount() const {
    return outputNodeCount;
}

void Simulation::resetSimulation(size_t inputNodeCount, size_t outputNodeCount, size_t populationSize) {
    generation = 0;
    population.generateNewPopulation(
        max(SIZE_ONE, inputNodeCount),
        max(SIZE_ONE, outputNodeCount),
        populationSize
    );

    this->inputNodeCount = max(SIZE_ONE, inputNodeCount);
    this->outputNodeCount = max(SIZE_ONE, outputNodeCount);
}

void Simulation::resetSimulation(size_t inputNodeCount, size_t outputNodeCount) {
    resetSimulation(inputNodeCount, outputNodeCount, population.getSize());
}

void Simulation::resetSimulation(size_t populationSize) {
    resetSimulation(inputNodeCount, outputNodeCount, populationSize);
}


void Simulation::resetSimulation() {
    resetSimulation(population.getSize());
}
