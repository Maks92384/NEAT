#pragma once

namespace neatConf {
    // Simulation configuration

    static const size_t defaultPopulationSize = 200;

    static const float defaultExcessCoefficient = 1.0;
    static const float defaultDisjointCoefficient = 1.0;
    static const float defaultWeightsCoefficient = 1.0;

    static const float defaultCompatibilityThreshold = 3.0;

    static const float defaultCrossoverRate = 0.75;

    static const float defaultWeightMutationRate = 0.8;
    static const float defaultNewWeightRate = 0.1;

    static const float defaultNewNodeRate = 0.03;
    static const float defaultNewConnectionRate = 0.05;

    static const float defaultInterspeciesMatingRate = 0.001;

    static const float defaultRemainDisabledRate = 0.75;
}