//
// Created by mika on 7/7/26.
//

#include <iostream>

#include "../icard.h"
#include "../iplayer.h"
#include "../gamecontext.h"
#include "strengthupeffect.h"

void StrengthUpEffect::Apply(GameContext* context)
{
    const auto* card = this->GetOwner();
    auto* player = this->GetOwner()->GetOwner();

    const int mod = card->GetStrength();
    const int old = player->GetTotalStrength();

    std::cout << "Adding " << mod << " to player total strength (" << old << " -> " << (old + mod) << ")." << std::endl;
    player->TotalStrengthAdd(card->GetStrength());
}