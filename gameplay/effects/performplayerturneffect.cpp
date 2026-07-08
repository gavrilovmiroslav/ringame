//
// Created by mika on 7/7/26.
//
#include <iostream>

#include "../iplayer.h"
#include "../gamecontext.h"
#include "performplayerturneffect.h"

void PerformPlayerTurnEffect::Apply(GameContext* context)
{
    std::cout << "\n| " << context->GetCurrentPlayer()->GetName() << "'s turn! ----------------\n" << std::endl;

    auto& player = context->GetCurrentPlayer();
#if defined(RG_DEBUG)
    int deckSize = player->GetDeck().size();
#endif
    auto* card = player->DrawCard();

    if (card != nullptr)
    {
        std::cout << player->GetName() << " is playing " << card->GetName() << "!" << std::endl;
        card->Apply(context);

#if defined(RG_DEBUG)
        int discardSize = player->GetDiscard().size();
#endif

        switch (card->GetResolution())
        {
            case ECardResolutionBehavior::Discard:
                player->DiscardCard(card);
                break;
            case ECardResolutionBehavior::Destroy:
            default: break;
        }

#if defined(RG_DEBUG)
        assert(player->GetDeck().size() == deckSize - 1);
        assert(player->GetDiscard().size() == discardSize + 1);
#endif
    }
    else
    {
        std::cout << "Player " << context->GetCurrentPlayer()->GetName() << "'s deck is empty, skipping!" << std::endl;
    }

    context->NextPlayer();
}