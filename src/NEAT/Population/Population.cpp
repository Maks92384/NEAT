// // Files
#include "Population.hpp"
#include "../NeatConfiguration.h"

// Libraries
#include <iostream>

using namespace std;

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
    remainDisabledRate(neatConf::defaultRemainDisabledRate) {

    resetPopulation(inputNodeCount, outputNodeCount, populationSize);
}

Population::Population(uint16_t inputNodeCount, uint16_t outputNodeCount) :
    Population(inputNodeCount, outputNodeCount, neatConf::defaultPopulationSize) {}

void Population::nextGeneration() {
    generation++;

    // vector<Organism> matingPool;
    // vector<Organism> representatives;
    //
    // for (Species& singleSpecies : species) {
    //     for (size_t i = 0; i < singleSpecies.getSize(); i++)
    //         matingPool.push_back(singleSpecies.getOrganismAt(i));
    //
    //     representatives.push_back(singleSpecies.getRepresentative());
    //     singleSpecies.clear();
    // }

    //genomes.removeTheWorstOnes();
}

void Population::resetPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize) {
    generation = 0;

    this->inputNodeCount = max(UINT16_ONE, inputNodeCount);
    this->outputNodeCount = max(UINT16_ONE, outputNodeCount);

    organisms.clear();

    species.clear();
    species.emplace_back();

    for (int i = 0; i < populationSize; i++) {
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


void Population::setExcessCoefficient(float newExcessCoefficient) {
    excessCoefficient = newExcessCoefficient;
}

void Population::setDisjointCoefficient(float newDisjointCoefficient) {
    disjointCoefficient = newDisjointCoefficient;
}

void Population::setWeightsCoefficient(float newWeightsCoefficient) {
    weightsCoefficient = newWeightsCoefficient;
}

void Population::setCompatibilityThreshold(float newCompatibilityThreshold) {
    compatibilityThreshold = newCompatibilityThreshold;
}

void Population::setCrossoverRate(float newCrossoverRate) {
    crossoverRate = newCrossoverRate;
}

void Population::setWeightMutationRate(float newWeightMutationRate) {
    weightMutationRate = newWeightMutationRate;
}

void Population::setNewWeightRate(float newNewWeightRate) {
    newWeightRate = newNewWeightRate;
}

void Population::setNewNodeRate(float newNewNodeRate) {
    newNodeRate = newNewNodeRate;
}

void Population::setNewConnectionRate(float newNewConnectionRate) {
    newConnectionRate = newNewConnectionRate;
}

void Population::setInterspeciesMatingRate(float newInterspeciesMatingRate) {
    interspeciesMatingRate = newInterspeciesMatingRate;
}

void Population::setRemainDisabledRate(float newRemainDisabledRate) {
    remainDisabledRate = newRemainDisabledRate;
}