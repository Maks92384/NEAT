// // Files
#include "Population.hpp"
#include "../NeatConfiguration.h"
#include "../RandomGenerator.hpp"

// Libraries
#include <algorithm>
#include <iostream>
#include <ranges>

using std::max;
using std::vector;
using std::cout;
using std::endl;
using std::uniform_int_distribution;
using std::unique_ptr;

const uint16_t Population::UINT16_ONE = 1;

Population::Population(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize) :
    inputNodeCount(max(UINT16_ONE, inputNodeCount)),
    outputNodeCount(max(UINT16_ONE, outputNodeCount)),
    globalInnovationNumber(inputNodeCount * outputNodeCount),
    generation(0),
    bestTotalFitness(0),

    // Initializing parameters

    excessCoefficient(neatConf::defaultExcessCoefficient),
    disjointCoefficient(neatConf::defaultDisjointCoefficient),
    weightsCoefficient(neatConf::defaultWeightsCoefficient),
    compatibilityThreshold(neatConf::defaultCompatibilityThreshold),
    crossoverRate(neatConf::defaultCrossoverRate),
    weightMutationRate(neatConf::defaultWeightMutationRate),
    newWeightRate(neatConf::defaultNewWeightRate),
    newNodeRate(neatConf::defaultNewNodeRate),
    newConnectionRate(neatConf::defaultNewConnectionRate),
    interspeciesMatingRate(neatConf::defaultInterspeciesMatingRate),
    remainDisabledRate(neatConf::defaultRemainDisabledRate),
    cullingThreshold(neatConf::defaultCullingThreshold) {

    resetPopulation(inputNodeCount, outputNodeCount, populationSize);
}

Population::Population(uint16_t inputNodeCount, uint16_t outputNodeCount) :
    Population(inputNodeCount, outputNodeCount, neatConf::defaultPopulationSize) {}

void Population::nextGeneration() {
    generation++;


    // Calculating average fitness for each species

    vector<double> speciesAverageFitnesses;
    double sumOfAveragefitnesses = 0;

    for (const auto& singleSpecies : species) {
        speciesAverageFitnesses.push_back(singleSpecies.getAverageFitness());
        sumOfAveragefitnesses += speciesAverageFitnesses.back();
    }

    for (size_t i = 0; i < species.size(); i++) {
        cout<<"Species: "<<i<<" , average: "<<speciesAverageFitnesses[i]<<endl;
    }

    cout<<"============================="<<endl;


    // Calculating potential offspring for each species

    vector<size_t> speciesOffspringCounts;
    size_t controlSum = 0;

    for (size_t i = 0; i < species.size(); i++) {
        if (sumOfAveragefitnesses * organisms.size() != 0)
            speciesOffspringCounts.push_back(llround(speciesAverageFitnesses.at(i) / sumOfAveragefitnesses * organisms.size()));
        else
            speciesOffspringCounts.push_back(0);

        controlSum += speciesOffspringCounts.at(i);
    }


    // Removing extinct species

    size_t speciesIndex = 0;

    erase_if(species, [&](const Species&) {
        return speciesOffspringCounts.at(speciesIndex++) == 0;
    });

    erase_if(speciesOffspringCounts, [](const size_t& offspringCount) {
        return offspringCount == 0;
    });


    // Adjusting the offspring count to match the population size

    uniform_int_distribution<size_t> speciesDistribution(0, species.size() - 1);

    int64_t offspringDifference = static_cast<int64_t>(organisms.size() - controlSum);
    int sign = offspringDifference > 0 ? 1 : -1;

    for (size_t i = 0; i < sign * offspringDifference; i++) {
        size_t& randomOffspringCount = speciesOffspringCounts.at(speciesDistribution(random));

        if (randomOffspringCount == 0 && sign == -1) {
            i--;
            continue;
        }

        randomOffspringCount += sign;
    }


    // Species culling

    for (auto& singleSpecies : species)
        singleSpecies.cull(cullingThreshold);


    // Getting species representatives

    vector<Organism> representatives;
    representatives.reserve(species.size());

    for (const auto& singleSpecies : species)
        representatives.push_back(singleSpecies.getRepresentative());


    // Crossover

    vector<unique_ptr<Organism>> newPopulation;
    newPopulation.reserve(organisms.size());

    for (size_t i = 0; i < species.size(); i++) {
        vector<unique_ptr<Organism>> children = species.at(i).crossover(
            speciesOffspringCounts.at(i),
            crossoverRate
        );

        newPopulation.insert(
            newPopulation.end(),
            make_move_iterator(children.begin()),
            make_move_iterator(children.end())
        );
    }

    for (auto& singleSpecies : species)
        singleSpecies.clear();

    organisms = std::move(newPopulation);


    // Mutation

    for (auto& organism : organisms)
        organism->getGenotype().mutate(
            weightMutationRate,
            newWeightRate,
            newNodeRate,
            newConnectionRate
        );


    // Assign organisms to species TODO

}

void Population::resetPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize) {
    generation = 0;

    this->inputNodeCount = max(UINT16_ONE, inputNodeCount);
    this->outputNodeCount = max(UINT16_ONE, outputNodeCount);

    organisms.clear();

    species.clear();

    for (size_t i = 0; i < populationSize; i++) {
        species.emplace_back();
        organisms.emplace_back(new Organism(inputNodeCount, outputNodeCount, globalInnovationNumber));
        species.at(0).add(organisms.at(i).get());
    }
}

void Population::resetPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount) {
    resetPopulation(inputNodeCount, outputNodeCount, getPopulationSize());
}

void Population::resetPopulation(size_t populationSize) {
    resetPopulation(inputNodeCount, outputNodeCount, populationSize);
}

void Population::resetPopulation() {
    resetPopulation(getPopulationSize());
}

size_t Population::getPopulationSize() const {
    return organisms.size();
}

uint32_t Population::getGeneration() const {
    return generation;
}

uint16_t Population::getInputCount() const {
    return inputNodeCount;
}

uint16_t Population::getOutputCount() const {
    return outputNodeCount;
}

const vector<unique_ptr<Organism>>& Population::getOrganisms() const {
    return organisms;
}


// Parameters getters and setters

float Population::getExcessCoefficient() const {
    return excessCoefficient;
}

float Population::getDisjointCoefficient() const {
    return disjointCoefficient;
}

float Population::getWeightsCoefficient() const {
    return weightsCoefficient;
}

float Population::getCompatibilityThreshold() const {
    return compatibilityThreshold;
}

float Population::getCrossoverRate() const {
    return crossoverRate;
}

float Population::getWeightMutationRate() const {
    return weightMutationRate;
}

float Population::getNewWeightRate() const {
    return newWeightRate;
}

float Population::getNewNodeRate() const {
    return newNodeRate;
}

float Population::getNewConnectionRate() const {
    return newConnectionRate;
}

float Population::getInterspeciesMatingRate() const {
    return interspeciesMatingRate;
}

float Population::getRemainDisabledRate() const {
    return remainDisabledRate;
}

float Population::getCullingThreshold() const {
    return cullingThreshold;
}


void Population::setExcessCoefficient(float excessCoefficient) {
    this->excessCoefficient = excessCoefficient;
}

void Population::setDisjointCoefficient(float disjointCoefficient) {
    this->disjointCoefficient = disjointCoefficient;
}

void Population::setWeightsCoefficient(float weightsCoefficient) {
    this->weightsCoefficient = weightsCoefficient;
}

void Population::setCompatibilityThreshold(float compatibilityThreshold) {
    this->compatibilityThreshold = compatibilityThreshold;
}

void Population::setCrossoverRate(float crossoverRate) {
    this->crossoverRate = crossoverRate;
}

void Population::setWeightMutationRate(float weightMutationRate) {
    this->weightMutationRate = weightMutationRate;
}

void Population::setNewWeightRate(float newWeightRate) {
    this->newWeightRate = newWeightRate;
}

void Population::setNewNodeRate(float newNodeRate) {
    this->newNodeRate = newNodeRate;
}

void Population::setNewConnectionRate(float newConnectionRate) {
    this->newConnectionRate = newConnectionRate;
}

void Population::setInterspeciesMatingRate(float interspeciesMatingRate) {
    this->interspeciesMatingRate = interspeciesMatingRate;
}

void Population::setRemainDisabledRate(float remainDisabledRate) {
    this->remainDisabledRate = remainDisabledRate;
}

void Population::setCullingThreshold(float cullingThreshold) {
    this->cullingThreshold = cullingThreshold;
}