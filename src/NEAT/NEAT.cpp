// Files
#include "NEAT.hpp"
#include "Genome/Genome.hpp"

// Libraries
#include <stdexcept>

using namespace std;


vector<unique_ptr<Simulation>> NEAT::simulations;

Simulation& NEAT::createSimulation(size_t inputNodeCount, size_t outputNodeCount, size_t populationSize) {
    simulations.emplace_back(new Simulation(inputNodeCount, outputNodeCount, populationSize));
    return *simulations.back();
}

Simulation& NEAT::createSimulation(size_t inputNodeCount, size_t outputNodeCount) {
    simulations.emplace_back(new Simulation(inputNodeCount, outputNodeCount));
    return *simulations.back();
}

Simulation& NEAT::getSimulationAt(size_t index) {
    if (index >= simulations.size())
        throw out_of_range("simulation index out of range");

    return *simulations[index];
}

size_t NEAT::getSimulationCount() {
    return simulations.size();
}