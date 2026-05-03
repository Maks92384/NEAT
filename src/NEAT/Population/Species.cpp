// Files
#include "Species.hpp"
#include "../RandomGenerator.hpp"

// Libraries
#include <algorithm>
#include <iostream>

using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::uniform_int_distribution;

Species::Species() {}

void Species::add(Organism* organism) {
    organisms.push_back(organism);
}

void Species::clear() {
    organisms.clear();
}

void Species::cull(float cullingThreshold) {
    size_t cuttingPoint = round(organisms.size() * (1 - cullingThreshold));

    nth_element(
        organisms.begin(),
        organisms.begin() + cuttingPoint,
        organisms.end(),
        [](const Organism* a, const Organism* b) {
            return a->getFitness() > b->getFitness();
        }
    );

    if (cuttingPoint < organisms.size())
        organisms.resize(cuttingPoint);
}

vector<unique_ptr<Organism>> Species::crossover(size_t offspringCount, float crossoverRate) const {
    vector<unique_ptr<Organism>> offspring;
    offspring.reserve(offspringCount);

    size_t crossoverCount = static_cast<size_t>(
        round(static_cast<double>(offspringCount) * crossoverRate)
    );

    float maxFitness = 0;

    for (const auto* organism : organisms) {
        float tempFitness = organism->getFitness();

        if (tempFitness > maxFitness) maxFitness = tempFitness;
    }

    for (size_t i = 0; i < offspringCount; i++) {
        Organism* organism1;
        Organism* organism2;



        if (i < crossoverCount) {
            offspring.push_back(
                make_unique<Organism>(organism1->makeChild(*organism2))
            );
        } else
            offspring.push_back(
                make_unique<Organism>(*organism1)
            );
    }

    return offspring;
}

Organism Species::getRepresentative() const {
    uniform_int_distribution<size_t> organismDistribution(0, organisms.size() - 1);

    return *organisms.at(organismDistribution(random));
}

double Species::getAverageFitness() const {
    if (organisms.empty())
        return 0;

    double sum = 0;

    for (const auto* organism : organisms)
        sum += organism->getFitness();

    return sum / organisms.size();
}

size_t Species::getSize() const {
    return organisms.size();
}

Organism* Species::getOrganismAt(size_t index) {
    return organisms.at(index);
}
