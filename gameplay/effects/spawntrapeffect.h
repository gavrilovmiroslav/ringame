//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_SPAWNTRAPEFFECT_H
#define RINGAME_SPAWNTRAPEFFECT_H

#include <string_view>

#include "../ieffect.h"

struct SpawnTrapEffect : public IEffect
{
    SpawnTrapEffect()
    {
        m_Consumable = true;
    }
    SpawnTrapEffect(ICard* card) : IEffect{card}
    {
        m_Consumable = true;
    }
    ~SpawnTrapEffect() override = default;
    void Apply(GameContext* context) override;

    std::string_view Name() override { return "Spawn Trap! (80%)"; };

};


#endif //RINGAME_SPAWNTRAPEFFECT_H
