//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_APPSTATE_H
#define RINGAME_APPSTATE_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

struct AppState
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    AppState() = default;

    bool Init()
    {
        int ok = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        if (ok < 0)
        {
            SDL_Log("SDL_Init failed: %s", SDL_GetError());
            return false;
        }

        ok = SDL_CreateWindowAndRenderer("Ringame", 800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer);
        if (ok < 0)
        {
            SDL_Log("SDL_CreateWindowAndRenderer failed: %s", SDL_GetError());
            return false;
        }

        if (window == nullptr)
        {
            SDL_Log("SDL Window is null!");
        }

        if (renderer == nullptr)
        {
            SDL_Log("SDL Renderer is null!");
        }

        m_IsRunning = true;
        return true;
    }

    bool IsRunning() const
    {
        return m_IsRunning;
    }

    void Shutdown()
    {
        m_IsRunning = false;
    }

private:
    bool m_IsRunning;
};


#endif //RINGAME_APPSTATE_H
