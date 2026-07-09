//
// Created by mika on 7/8/26.
//

#include "milldiscardstealeffect.h"

#include "../gamecontext.h"
#include "../iplayer.h"

void MillDiscardEffect::Apply(GameContext *context)
{
    assert(this != nullptr);
    assert(this->GetOwner() != nullptr);
    assert(this->GetOwner()->GetOwner() != nullptr);

    auto* player = this->GetOwner()->GetOwner();
    for (auto& other : context->GetPlayers())
    {
        if (other.get() != player)
        {
            auto& discard = other->GetDiscard();
            if (!discard.empty())
            {
                auto card = discard.back();
                std::cout << "[ " << this->GetOwner()->GetName() << " ] Stealing one card (" << card->GetName() << ") from " << other->GetName() << "'s discard pile." << std::endl;
                discard.pop_back();

                card->SetOwner(player);
                player->GetDiscard().push_back(card);
            }
            else
            {
                std::cout << "[ " << this->GetOwner()->GetName() << " ] " << other->GetName() << "'s discard is empty, can't discard." << std::endl;
            }
        }
    }
}
