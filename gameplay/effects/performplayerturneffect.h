//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_STARTNEXTPLAYERTURN_H
#define RINGAME_STARTNEXTPLAYERTURN_H

#include <string_view>

#include "../ieffect.h"

struct PerformPlayerTurnEffect : public IEffect
{
    PerformPlayerTurnEffect() = default;
    ~PerformPlayerTurnEffect() override = default;
    void Apply(GameContext* context) override;

    std::string_view Name() override { return "Perform Turn"; };
};

#endif //RINGAME_STARTNEXTPLAYERTURN_H
