// Files
#include "NEAT.hpp"

// Libraries
#include <csignal>
#include <stdexcept>

using namespace std;

vector<Simulation> NEAT::simulations;

Simulation& NEAT::createSimulation() {
    simulations.emplace_back();
    return simulations.back();
}

Simulation& NEAT::getSimulationAt(size_t index) {
    if (index >= simulations.size())
        throw out_of_range("simulation index out of range");

    return simulations.at(index);
}

size_t NEAT::getSimulationCount() {
    return simulations.size();
}