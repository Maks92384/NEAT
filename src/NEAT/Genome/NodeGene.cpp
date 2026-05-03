// Files
#include "NodeGene.hpp"

// Libraries
#include <iostream>

using std::cout;
using std::endl;

NodeGene::NodeGene(NodeType nodeType) : nodeType(nodeType) {
    if (nodeType == NodeType::INPUT)
        cout<<"INPUT NODE"<<endl;

    if (nodeType == NodeType::OUTPUT)
        cout<<"OUTPUT NODE"<<endl;
}

 NodeGene NodeGene::createInputNodeGene() {
     return NodeGene(NodeType::INPUT);
 }

 NodeGene NodeGene::createHiddenNodeGene() {
     return NodeGene(NodeType::INPUT);
 }

 NodeGene NodeGene::createOutputNodeGene() {
     return NodeGene(NodeType::OUTPUT);
 }
