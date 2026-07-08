//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_MILLDISCARDEFFECT_H
#define RINGAME_MILLDISCARDEFFECT_H

#include <string_view>

#include "../ieffect.h"

struct MillDiscardEffect : public IEffect
{
    MillDiscardEffect() = default;
    ~MillDiscardEffect() override = default;
    void Apply(GameContext* context) override;

    std::string_view Name() override { return "Mill Discard!"; };
};


#endif //RINGAME_MILLDISCARDEFFECT_H
