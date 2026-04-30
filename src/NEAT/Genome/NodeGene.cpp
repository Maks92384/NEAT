#include "NodeGene.hpp"

NodeGene::NodeGene(NodeType nodeType) : nodeType(nodeType) {}

 NodeGene NodeGene::createInputNodeGene() {
     return NodeGene(NodeType::INPUT);
 }

 NodeGene NodeGene::createHiddenNodeGene() {
     return NodeGene(NodeType::INPUT);
 }

 NodeGene NodeGene::createOutputNodeGene() {
     return NodeGene(NodeType::OUTPUT);
 }
