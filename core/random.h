//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_RANDOM_H
#define RINGAME_RANDOM_H

#include <random>
#include <algorithm>

#define UUID_SYSTEM_GENERATOR
#include "../core/uuid.h"

template<int Min, int Max>
static int rnd()
{
    static std::random_device dev;
    static std::mt19937 core{dev()};
    static std::uniform_int_distribution<std::mt19937::result_type> dist(Min, Max);
    return dist(core);
}

static uuids::uuid id()
{
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    std::mt19937 generator(seq);
    uuids::uuid_random_generator gen{generator};

    return gen();
}

#endif //RINGAME_RANDOM_H
