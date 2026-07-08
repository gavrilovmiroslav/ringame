//
// Created by mika on 7/8/26.
//

#include "milldiscardeffect.h"

#include "../gamecontext.h"
#include "../iplayer.h"

void MillDiscardEffect::Apply(GameContext *context)
{
    const auto* player = this->GetOwner()->GetOwner();
    for (auto& other : context->GetPlayers())
    {
        if (other.get() != player)
        {
            auto& discard = other->GetDiscard();
            if (!discard.empty())
            {
                auto* card = discard.back();
                std::cout << "Removing one card (" << card->GetName() << ") from " << other->GetName() << "'s discard pile.";
                discard.pop_back();
            }
            else
            {
                std::cout << "" << other->GetName() << "'s discard is empty, can't discard.";
            }
        }
    }
}
