//
// Created by mika on 7/8/26.
//

#include "onemoreturneffect.h"

#include <iostream>

#include "../gamecontext.h"
#include "../iplayer.h"

void OneMoreTurnEffect::Apply(GameContext *context)
{
    context->NextPlayer();
    std::cout << context->GetCurrentPlayer()->GetName() << " gets to play one more turn!" << std::endl;
    context->Consume();
}