//
// Created by mika on 7/7/26.
//
#include <iostream>

#include "../iplayer.h"
#include "../gamecontext.h"
#include "performplayerturneffect.h"

void PerformPlayerTurnEffect::Apply(GameContext* context)
{
    std::cout << "\n### Starting " << context->GetCurrentPlayer()->GetName() << "'s turn! ###\n" << std::endl;

    auto& player = context->GetCurrentPlayer();
    int deckSize = player->GetDeck().size();
    auto* card = player->DrawCard();

    if (card != nullptr)
    {
        std::cout << player->GetName() << " is playing " << card->GetName() << "!" << std::endl;
        card->Apply(context);

        int discardSize = player->GetDiscard().size();
        player->DiscardCard(card);

        assert(player->GetDeck().size() == deckSize - 1);
        assert(player->GetDiscard().size() == discardSize + 1);
    }
    else
    {
        std::cout << "Player " << context->GetCurrentPlayer()->GetName() << "'s deck is empty, skipping!" << std::endl;
    }

    context->NextPlayer();
}