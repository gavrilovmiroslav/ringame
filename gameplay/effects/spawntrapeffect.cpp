//
// Created by mika on 7/8/26.
//

#include "spawntrapeffect.h"

#include <iostream>

#include "../gamecontext.h"
#include "../iplayer.h"
#include "../card.h"
#include "../../core/random.h"

void SpawnTrapEffect::Apply(GameContext *context)
{
    if (rnd<0, 100>() < 80)
    {
        auto* player = this->GetOwner()->GetOwner();
        std::cout << "[ " << this->GetOwner()->GetName() << " ] Spawning enemy traps for next round!" << std::endl;

        for (auto& other : context->GetPlayers())
        {
            if (other.get() != player)
            {
                other->GetDiscard().push_back(context->GetRegistry().Instantiate("Trap", other.get()));
            }
        }
    }
    else
    {
        std::cout << "[ " << this->GetOwner()->GetName() << " ] failed!" << std::endl;
    }
}