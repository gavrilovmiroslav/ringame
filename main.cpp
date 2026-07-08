#include <iostream>

#include "core/ringbuffer.h"
#include <cassert>

#include <SDL3/SDL_main.h>

#include "engine/appstate.h"
#include "gameplay/impl/cardbase.h"
#include "gameplay/gamecontext.h"
#include "gameplay/effects/doubletotalstrengtheffect.h"
#include "gameplay/effects/milldiscardstealeffect.h"
#include "gameplay/effects/onemoreturneffect.h"
#include "gameplay/effects/reduceenemystrengtheffect.h"
#include "gameplay/effects/spawnminionseffect.h"
#include "gameplay/effects/spawntrapeffect.h"
#include "gameplay/impl/humanplayer.h"

int main() {
    GameContext gameContext{2};

    gameContext.AddPlayer(new HumanPlayer("A", {
        new CardBase("Heavy", 10),
        new CardBase("Heavy", 10),
        new CardBase("Double Trouble", 1, new DoubleTotalStrengthEffect()),
        new CardBase("Cutpurse", 1, new ReduceEnemyStrengthEffect()),
    }));

    gameContext.AddPlayer(new HumanPlayer("B", {
        new CardBase("Necromancer", -1, new SpawnMinionsEffect(), ECardResolutionBehavior::Destroy),
        new CardBase("Trapper", 2, new SpawnTrapEffect()),
        new CardBase("Chrono", 2, new OneMoreTurnEffect()),
        new CardBase("Graverobber", 5, new MillDiscardEffect()) }));

    gameContext.Run();

    AppState state{};
    state.Init();

    while (state.IsRunning())
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EventType::SDL_EVENT_QUIT:
                    state.Shutdown();
                    break;
            }
        }

        SDL_RenderClear(state.renderer);
        // rendering goes here
        SDL_RenderPresent(state.renderer);
    }

    SDL_Quit();

    return 0;
}
