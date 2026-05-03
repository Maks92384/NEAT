// Files
#include "Genome.hpp"
#include "../RandomGenerator.hpp"

// Libraries
#include <iostream>

using std::cout;
using std::endl;
using std::uniform_real_distribution;

Genome::Genome(uint16_t inputNodeCount, uint16_t outputNodeCount, const uint32_t& globalInnovationNumber) :
    globalInnovationNumber(globalInnovationNumber) {

    uniform_real_distribution<float> initialWeightDistribution(-1, 1);

    for (uint16_t i = 0; i < inputNodeCount; i++) {
        cout<<nodes.size()<<" -> ";

        nodes.push_back(
            NodeGene::createInputNodeGene()
        );
    }

    for (uint16_t i = 0; i < outputNodeCount; i++) {
        cout<<nodes.size()<<" -> ";
        nodes.push_back(
            NodeGene::createOutputNodeGene()
        );
    }

    for (uint16_t i = 0; i < inputNodeCount; i++)
        for (uint16_t j = 0; j < outputNodeCount; j++)
            connections.emplace_back(
                i,
                inputNodeCount + j,
                initialWeightDistribution(random),
                i * outputNodeCount + j
            );
}

void Genome::mutate() {
}

void Genome::display(size_t index) const {
    cout<<"Genome("<<index<<"):"<<endl;
    for (const auto& connection : connections)
        connection.display();
}
