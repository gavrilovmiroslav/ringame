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
    for (const auto& player : context->GetPlayers())
    {
        if (!player->GetDeck().empty())
        {
            done = false;
            break;
        }
    }

    if (done)
    {
        std::cout << "The round is finished - both decks are empty!" << std::endl;
        context->GameOver();
    }

    context->Next();
}