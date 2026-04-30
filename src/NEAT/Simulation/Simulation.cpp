// Files
#include "Simulation.hpp"
#include "SimConfiguration.h"

// Libraries
#include <iostream>

using namespace std;

const uint16_t Simulation::UINT16_ONE = 1;

Simulation::Simulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize) :
    population(
        max(UINT16_ONE, inputNodeCount),
        max(UINT16_ONE, outputNodeCount),
        populationSize
    ),
    inputNodeCount(max(UINT16_ONE, inputNodeCount)),
    outputNodeCount(max(UINT16_ONE, outputNodeCount)),
    generation(0) {
}

Simulation::Simulation(uint16_t inputNodeCount, uint16_t outputNodeCount) :
    Simulation(inputNodeCount, outputNodeCount, simConf::defaultPopulationSize) {}

void Simulation::nextGeneration() {
    generation++;
    population.evolve();
}

size_t Simulation::getPopulationSize() const {
    return population.getSize();
}

uint32_t Simulation::getGeneration() const {
    return generation;
}

uint16_t Simulation::getInputCount() const {
    return inputNodeCount;
}

uint16_t Simulation::getOutputCount() const {
    return outputNodeCount;
}

void Simulation::resetSimulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize) {
    generation = 0;
    population.generateNewPopulation(
        max(UINT16_ONE, inputNodeCount),
        max(UINT16_ONE, outputNodeCount),
        populationSize
    );

    this->inputNodeCount = max(UINT16_ONE, inputNodeCount);
    this->outputNodeCount = max(UINT16_ONE, outputNodeCount);
}

void Simulation::resetSimulation(uint16_t inputNodeCount, uint16_t outputNodeCount) {
    resetSimulation(inputNodeCount, outputNodeCount, population.getSize());
}

void Simulation::resetSimulation(size_t populationSize) {
    resetSimulation(inputNodeCount, outputNodeCount, populationSize);
}


void Simulation::resetSimulation() {
    resetSimulation(population.getSize());
}
