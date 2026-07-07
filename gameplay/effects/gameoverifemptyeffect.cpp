//
// Created by mika on 7/7/26.
//

#include <iostream>

#include "../gamecontext.h"
#include "../iplayer.h"
#include "gameoverifemptyeffect.h"

void GameOverIfEmptyEffect::Apply(GameContext *context)
{
    bool done = true;
    std::string_view name = "";
    int max = 0;
    for (const auto& player : context->GetPlayers())
    {
        if (player->GetTotalStrength() > max)
        {
            max = player->GetTotalStrength();
            name = player->GetName();
        }

        if (!player->GetDeck().empty())
        {
            std::cout << "Player " << player->GetName() << " still has cards to draw!" << std::endl;
            done = false;
            break;
        }
    }

    if (done)
    {
        std::cout << "Game is finished - both decks are empty!" << std::endl;
        std::cout << "The winner is " << name << " with " << max << " strength!" << std::endl;
        context->GameOver();
    }

    context->Next();
}