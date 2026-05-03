#pragma once

#include <random>

inline std::mt19937 random {
    std::random_device{}()
};