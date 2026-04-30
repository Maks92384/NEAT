// Files
#include "NEAT/NEAT.hpp"
#include "Configuration.hpp"

// Libraries
#include <iostream>

using namespace std;

int main() {
    // Potential testing

    NEAT::createSimulation(3, 2, 2);

    Simulation& sim = NEAT::getSimulationAt(0);


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
