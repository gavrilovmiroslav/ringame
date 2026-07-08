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
    auto* card = player->DrawCard();

    std::cout << player->GetName() << " is playing " << card->GetName() << "!" << std::endl;
    if (card != nullptr)
    {
        card->Apply(context);
    }
    else
    {
        std::cout << "Player " << context->GetCurrentPlayer()->GetName() << "'s deck is empty, skipping!" << std::endl;
    }

    player->DiscardCard(card);
    context->NextPlayer();
}