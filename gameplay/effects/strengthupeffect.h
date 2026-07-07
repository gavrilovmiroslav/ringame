//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_STRENGTHUP_H
#define RINGAME_STRENGTHUP_H

#include "../ieffect.h"

struct StrengthUpEffect : public IEffect
{
    StrengthUpEffect() = delete;
    StrengthUpEffect(ICard* card) : IEffect{card}
    {
        m_Consumable = true;
    }
    ~StrengthUpEffect() = default;

    std::string_view Name() override { return "Strength Up!"; };
    void Apply(GameContext* context) override;
};

#endif //RINGAME_STRENGTHUP_H
