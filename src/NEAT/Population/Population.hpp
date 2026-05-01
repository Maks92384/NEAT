#pragma once

//Files
#include "Species.hpp"

// Libraries
#include <vector>

using namespace std;


class NEAT;

class Population {
    friend class NEAT;

    static const uint16_t UINT16_ONE;

    uint32_t globalInnovationNumber;
    uint32_t generation;

    float bestTotalFitness;

    uint16_t inputNodeCount;
    uint16_t outputNodeCount;

    vector<unique_ptr<Organism>> organisms;
    vector<Species> species;

    // Configuration parameters

    float excessCoefficient;
    float disjointCoefficient;
    float weightsCoefficient;

    float compatibilityThreshold;

    float crossoverRate;

    float weightMutationRate;
    float newWeightRate;

    float newNodeRate;
    float newConnectionRate;

    float interspeciesMatingRate;

    float remainDisabledRate;


    Population(uint16_t inputNodeCount, uint16_t outputNodeCount);
    Population(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize);

public:

    void nextGeneration();

    void resetPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount, size_t populationSize);
    void resetPopulation(uint16_t inputNodeCount, uint16_t outputNodeCount);
    void resetPopulation(size_t populationSize);
    void resetPopulation();

    size_t getPopulationSize() const;
    uint32_t getGeneration() const;
    uint16_t getInputCount() const;
    uint16_t getOutputCount() const;

    const vector<unique_ptr<Organism>>& getOrganisms() const;


    // Parameters getters and setters

    float getExcessCoefficient() const;
    float getDisjointCoefficient() const;
    float getWeightsCoefficient() const;
    float getCompatibilityThreshold() const;
    float getCrossoverRate() const;
    float getWeightMutationRate() const;
    float getNewWeightRate() const;
    float getNewNodeRate() const;
    float getNewConnectionRate() const;
    float getInterspeciesMatingRate() const;
    float getRemainDisabledRate() const;

    void setExcessCoefficient(float newExcessCoefficient);
    void setDisjointCoefficient(float newDisjointCoefficient);
    void setWeightsCoefficient(float newWeightsCoefficient);
    void setCompatibilityThreshold(float newCompatibilityThreshold);
    void setCrossoverRate(float newCrossoverRate);
    void setWeightMutationRate(float newWeightMutationRate);
    void setNewWeightRate(float newNewWeightRate);
    void setNewNodeRate(float newNewNodeRate);
    void setNewConnectionRate(float newNewConnectionRate);
    void setInterspeciesMatingRate(float newInterspeciesMatingRate);
    void setRemainDisabledRate(float newRemainDisabledRate);
};