//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_ONEMORETURNEFFECT_H
#define RINGAME_ONEMORETURNEFFECT_H

#include <string_view>

#include "../ieffect.h"

struct OneMoreTurnEffect : IEffect
{
    OneMoreTurnEffect() = default;
    ~OneMoreTurnEffect() override = default;
    void Apply(GameContext* context) override;

    std::string_view Name() override { return "One More Turn!"; };
};


#endif //RINGAME_ONEMORETURNEFFECT_H
