//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_FORCEGAMEOVEREFFECT_H
#define RINGAME_FORCEGAMEOVEREFFECT_H

#include "../ieffect.h"

struct GameOverIfEmptyEffect : public IEffect
{
    GameOverIfEmptyEffect() = default;
    ~GameOverIfEmptyEffect() override = default;
    void Apply(GameContext* context) override;

    std::string_view Name() override { return "Game Over If All Players Empty"; };
};

#endif //RINGAME_FORCEGAMEOVEREFFECT_H
