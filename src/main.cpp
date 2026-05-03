// Files
#include "NEAT/NEAT.hpp"
#include "Configuration.hpp"

// Libraries
#include <iostream>
#include <random>

std::mt19937 silnik;

using std::cout;
using std::endl;
using std::vector;
using std::random_device;
using std::uniform_real_distribution;
using std::unique_ptr;

int main() {
    // Potential testing

    random_device random_device{};
    silnik.seed(random_device());

    uniform_real_distribution<float> fitnessDistribution(0.0, 1000);

    NEAT::createPopulation(3, 2, 2);

    Population& pop = NEAT::getPopulationAt(0);

    pop.resetPopulation(1, 2, 20);

    cout<<"==================================================="<<endl<<endl;

    const vector<unique_ptr<Organism>>& organisms = pop.getOrganisms();

    for (auto& organism : organisms)
        organism->setFitness(fitnessDistribution(silnik));

    for (size_t i = 0; i < organisms.size(); i++)
        organisms.at(i)->display(i);

    cout<<"==================================================="<<endl;

    cout<<"==================================================="<<endl;

    cout<<"==================================================="<<endl<<endl;

    pop.nextGeneration();


    /*

    cout<<"==================================================="<<endl<<endl;

    cout<<"==================================================="<<endl<<endl;

    cout<<"==================================================="<<endl<<endl;


    vector<int> test = {9,3,3,8,6,3,2,3,5,6,5,2,1,0};

    nth_element(test.begin(), test.begin(), test.end(), [](int a, int b) {
        return a > b;
    });

    for (int e : test)
        cout<<e<<" ";

    cout<<endl<<endl;
    cout<<"==================================================="<<endl<<endl;

    */


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
