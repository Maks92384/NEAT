// Files
#include "NEAT/NEAT.hpp"

// Libraries
#include <iostream>
#include <ostream>

int main() {
    // Potential testing

    NEAT::createSimulation();

    Simulation& sim = NEAT::getSimulationAt(0);

    // sim.start();
    //
    // sim.pause();
    //
    // sim.stop();

    return 0;
}
