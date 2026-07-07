//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_DOUBLETOTALSTRENGTHEFFECT_H
#define RINGAME_DOUBLETOTALSTRENGTHEFFECT_H

#include <string_view>

#include "../ieffect.h"

struct DoubleTotalStrengthEffect : public IEffect
{
    DoubleTotalStrengthEffect()
    {
        m_Consumable = true;
    }
    DoubleTotalStrengthEffect(ICard* card) : IEffect{card}
    {
        m_Consumable = true;
    }
    ~DoubleTotalStrengthEffect() override = default;
    void Apply(GameContext* context) override;

    std::string_view Name() override { return "Double Total Strength!"; };

};


#endif //RINGAME_DOUBLETOTALSTRENGTHEFFECT_H
