// Files
#include "NEAT.hpp"
#include "Genome/Genome.hpp"

using namespace std;

vector<unique_ptr<Population>> NEAT::populations;

Population& NEAT::createPopulation(size_t inputNodeCount, size_t outputNodeCount, size_t populationSize) {
    populations.emplace_back(new Population(inputNodeCount, outputNodeCount, populationSize));
    return *populations.back();
}

Population& NEAT::createPopulation(size_t inputNodeCount, size_t outputNodeCount) {
    populations.emplace_back(new Population(inputNodeCount, outputNodeCount));
    return *populations.back();
}

Population& NEAT::getPopulationAt(size_t index) {
    return *populations.at(index);
}

size_t NEAT::getPopulationCount() {
    return populations.size();
}