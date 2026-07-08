//
// Created by mika on 7/7/26.
//

#include "doubletotalstrengtheffect.h"

#include "../iplayer.h"
#include "../icard.h"
#include "../gamecontext.h"

void DoubleTotalStrengthEffect::Apply(GameContext *context)
{
    auto* player = this->GetOwner()->GetOwner();

    const int old = player->GetTotalStrength();
    std::cout << "[ " << this->GetOwner()->GetName() << " ] Doubling " << player->GetName() << "'s total strength (" << old << " -> " << (2 * old) << ")." << std::endl;
    player->TotalStrengthAdd(old);
}
