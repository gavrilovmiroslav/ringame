//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_SPAWNMINIONSEFFECT_H
#define RINGAME_SPAWNMINIONSEFFECT_H

#include <string_view>

#include "../ieffect.h"

struct SpawnMinionsEffect : public IEffect
{
    SpawnMinionsEffect()
    {
        m_Consumable = true;
    }
    SpawnMinionsEffect(Card* card) : IEffect{card}
    {
        m_Consumable = true;
    }
    ~SpawnMinionsEffect() override = default;
    void Apply(GameContext* context) override;

    std::string_view Name() override { return "Spawn Minions!"; };

};


#endif //RINGAME_SPAWNMINIONSEFFECT_H
