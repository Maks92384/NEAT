// Files
#include "Simulation.hpp"
#include "SimConfiguration.h"

// Libraries
#include <iostream>

using namespace std;

Simulation::Simulation() : running(false), population(simConf::defaultPopulationSize) {}

size_t Simulation::getPopulationSize() {
    return population.size();
}

void Simulation::setPopulationSize(size_t size) {
    if (running)
        throw runtime_error("Cannot resize population: Simulation is running.");
    population = vector<Population>(size);
}
