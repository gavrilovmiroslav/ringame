#include <iostream>

#include "core/ringbuffer.h"
#include <cassert>

#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "engine/appstate.h"
#include "gameplay/gamecontext.h"
#include "gameplay/registry.h"
#include "gameplay/impl/humanplayer.h"

#include "gameplay/library.h"

int main() {
    GameContext gameContext{};
    Registry& registry = gameContext.GetRegistry();

    SetupLibrary(registry);

    gameContext.AddPlayer(new HumanPlayer("A",
        { "Heavy", "Heavy", "Double Trouble", "Cutpurse" }));

    gameContext.AddPlayer(new HumanPlayer("B",
        { "Necromancer", "Trapper", "Chrono", "Graverobber" }));

    gameContext.Run();

    /*
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
    */

    return 0;
}
