// Files
#include "NEAT/NEAT.hpp"
#include "Configuration.hpp"

// Libraries
#include <iostream>
#include <random>

mt19937 silnik;

using namespace std;

int main() {
    // Potential testing

    random_device random_device{};
    silnik.seed(random_device());


    NEAT::createPopulation(3, 2, 2);

    Population& pop = NEAT::getPopulationAt(0);

    //pop.nextGeneration();

    cout<<"==================================================="<<endl<<endl;

    const vector<unique_ptr<Organism>>& organisms = pop.getOrganisms();

    for (int i = 0; i < organisms.size(); i++)
        organisms.at(i)->display(i);


    short frameCount = 0;

    // while (true) {
    //     sim.adjustFitnesses();
    //
    //     if ( ++frameCount == Conf::generationLifespan ) {
    //         frameCount = 0;
    //         sim.nextGeneration();
    //     }
    // }

    return 0;
}
