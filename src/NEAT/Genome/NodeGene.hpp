#pragma once


class NodeGene {
    enum class NodeType {
        INPUT,
        HIDDEN,
        OUTPUT
    };

    NodeType nodeType;

    NodeGene(NodeType nodeType);

public:

    static NodeGene createInputNodeGene();

    static NodeGene createHiddenNodeGene();

    static NodeGene createOutputNodeGene();
};
