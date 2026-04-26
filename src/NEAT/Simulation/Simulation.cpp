// Files
#include "Simulation.hpp"
#include "SimConfiguration.h"

// Libraries
#include <iostream>

using namespace std;

Simulation::Simulation() : population(simConf::defaultPopulationSize), generation(0) {}

size_t Simulation::getPopulationSize() {
    return population.getSize();
}

void Simulation::setPopulationSize(size_t size) {
    population.setSize(size);
}
