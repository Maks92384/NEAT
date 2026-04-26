// Files
#include "NEAT/NEAT.hpp"
#include "Configuration.hpp"

// Libraries
#include <iostream>

int main() {
    // Potential testing

    NEAT::createSimulation();

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
