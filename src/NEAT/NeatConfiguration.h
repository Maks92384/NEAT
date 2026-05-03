#pragma once

namespace neatConf {
    // Simulation configuration

    static const size_t defaultPopulationSize = 200;

    static const float defaultExcessCoefficient = 1.0f;
    static const float defaultDisjointCoefficient = 1.0f;
    static const float defaultWeightsCoefficient = 1.0f;

    static const float defaultCompatibilityThreshold = 3.0f;

    static const float defaultCrossoverRate = 0.75f;

    static const float defaultWeightMutationRate = 0.8f;
    static const float defaultNewWeightRate = 0.1f;

    static const float defaultNewNodeRate = 0.03f;
    static const float defaultNewConnectionRate = 0.05f;

    static const float defaultInterspeciesMatingRate = 0.001f;

    static const float defaultRemainDisabledRate = 0.75f;

    // (MIGHT BE BEST TO SET TO 0, NEEDS EXPERIMENTING)
    static const float defaultCullingThreshold = 0.5f; // Jujutsu Kaisen Reference
}