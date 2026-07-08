//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_RANDOM_H
#define RINGAME_RANDOM_H

#include <random>
#include <algorithm>

template<int Min, int Max>
int rnd()
{
    static std::random_device dev;
    static std::mt19937 core{dev()};
    static std::uniform_int_distribution<std::mt19937::result_type> dist(Min, Max);
    return dist(core);
}

#endif //RINGAME_RANDOM_H
