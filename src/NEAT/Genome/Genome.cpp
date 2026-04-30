#include "Genome.hpp"


Genome::Genome(size_t inputNodeCount, size_t outputNodeCount) {
    for (size_t i = 0; i < inputNodeCount; i++)
         nodes.push_back(
             NodeGene::createInputNodeGene()
         );

    for (size_t i = 0; i < outputNodeCount; i++)
         nodes.push_back(
             NodeGene::createOutputNodeGene()
         );

    for (size_t i = 0; i < inputNodeCount; i++)
        for (size_t j = 0; j < outputNodeCount; j++)
            connections.emplace_back(/*TODO*/);
}
