//
// Created by mika on 7/8/26.
//

#include "spawnminionseffect.h"

#include <iostream>

#include "../gamecontext.h"
#include "../iplayer.h"
#include "../card.h"

void SpawnMinionsEffect::Apply(GameContext *context)
{
    auto* player = this->GetOwner()->GetOwner();
    int count = player->GetDeck().size();
    if (count == 0) count = 1;
    std::cout << "[ " << this->GetOwner()->GetName() << " ] Spawning " << count << " minions (strength 1) for next round!" << std::endl;

    for (int i = 0; i < count; i++)
    {
        player->GetDiscard().push_back(context->GetRegistry().Instantiate("Minion", player));
    }
}