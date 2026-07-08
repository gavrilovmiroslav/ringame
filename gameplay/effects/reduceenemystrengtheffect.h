//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_REDUCEENEMYSTRENGTHEFFECT_H
#define RINGAME_REDUCEENEMYSTRENGTHEFFECT_H

#include <string_view>

#include "../ieffect.h"

struct ReduceEnemyStrengthEffect : public IEffect
{
    ReduceEnemyStrengthEffect() : IEffect()
    {
        m_Consumable = true;
    }
    ~ReduceEnemyStrengthEffect() override = default;
    void Apply(GameContext* context) override;

    std::string_view Name() override { return "Reduce Enemy Strength!"; };
};


#endif //RINGAME_REDUCEENEMYSTRENGTHEFFECT_H
