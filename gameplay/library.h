//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_LIBRARY_H
#define RINGAME_LIBRARY_H

#include "registry.h"

#include <iostream>

#include "effects/doubletotalstrengtheffect.h"
#include "effects/milldiscardstealeffect.h"
#include "effects/onemoreturneffect.h"
#include "effects/reduceenemystrengtheffect.h"
#include "effects/spawnminionseffect.h"
#include "effects/spawntrapeffect.h"

static void SetupLibrary(Registry& registry)
{
    std::cout << "Setting up library" << std::endl;
    registry.RegisterEffectFactory("Double Total Strength", [](){ return new DoubleTotalStrengthEffect(); });
    registry.RegisterEffectFactory("Reduce Enemy Strength", [](){ return new ReduceEnemyStrengthEffect(); });
    registry.RegisterEffectFactory("Spawn 3 Minions", [](){ return new SpawnMinionsEffect(); });
    registry.RegisterEffectFactory("Spawn Trap", [](){ return new SpawnTrapEffect(); });
    registry.RegisterEffectFactory("One More Turn", [](){ return new OneMoreTurnEffect(); });
    registry.RegisterEffectFactory("Mill Enemy Discard Pile", [](){ return new MillDiscardEffect(); });

    registry.RegisterCardTemplate("Heavy", 10);
    registry.RegisterCardTemplate("Double Trouble", 1, "Double Total Strength");
    registry.RegisterCardTemplate("Cutpurse", 1, "Reduce Enemy Strength");
    registry.RegisterCardTemplate("Necromancer", -1, "Spawn 3 Minions", ECardResolutionBehavior::Destroy);
    registry.RegisterCardTemplate("Trapper", 2, "Spawn Trap");
    registry.RegisterCardTemplate("Chrono", 2, "One More Turn");
    registry.RegisterCardTemplate("Graverobber", 5, "Mill Enemy Discard Pile");
    registry.RegisterCardTemplate("Trap", -3);
    registry.RegisterCardTemplate("Minion", 1);
}
#endif //RINGAME_LIBRARY_H
