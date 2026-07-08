//
// Created by mika on 7/8/26.
//

#include "reduceenemystrengtheffect.h"

#include <cmath>
#include <iostream>

#include "../gamecontext.h"
#include "../iplayer.h"
#include "../icard.h"

void ReduceEnemyStrengthEffect::Apply(GameContext *context)
{
    // let's fix the percent to 50% of OUR strength rounded up
    auto* player = this->GetOwner()->GetOwner();

    int mod = static_cast<int>(std::ceil((static_cast<float>(player->GetTotalStrength()) + 0.5f) / 2));

    for (auto& other : context->GetPlayers())
    {
        if (other.get() != player)
        {
            int old = other->GetTotalStrength();
            std::cout << "[ " << this->GetOwner()->GetName() << " ] Reducing " << other->GetName() << "'s strength by 50% of " << player->GetName() << "'s strength (" << old << " -> " << (old - mod) << ")." << std::endl;
            other->TotalStrengthAdd(-mod);
        }
    }
}
