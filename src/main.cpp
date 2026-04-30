// Files
#include "NEAT/NEAT.hpp"
#include "Configuration.hpp"

// Libraries
#include <iostream>
#include <random>

using namespace std;

//mt19937 silnik;

int main() {
    // Potential testing

    // random_device rd;
    // silnik.seed(rd());
    //
    // uniform_int_distribution<int> distrib(0, 100);
    //
    // cout<<distrib(silnik)<<endl;

    NEAT::createSimulation(3, 1, 200);

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
