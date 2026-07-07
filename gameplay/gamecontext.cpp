//
// Created by mika on 7/7/26.
//

#include "gamecontext.h"
#include "iplayer.h"
#include "effects/gameoverifemptyeffect.h"
#include "effects/performplayerturneffect.h"

GameContext::GameContext(int playerCount)
    : m_PlayerCount{playerCount}
    , m_Players{}
{}

void GameContext::AddPlayer(IPlayer* player)
{
    m_Players.push_back(std::unique_ptr<IPlayer>(player));
}

void GameContext::Advance()
{
    if (m_State.IsEmpty())
    {
        GameOver();
    }

    auto* current = m_State.Current();
    if (current != nullptr)
    {
        current->Apply(this);
        if (current->IsConsumable())
        {
            m_State.Consume();
        }
        else
        {
            m_State.Next();
        }
    }
}

void GameContext::Run()
{
    m_State.Push(new PerformPlayerTurnEffect());
    m_State.Push(new PerformPlayerTurnEffect());
    m_State.Push(new GameOverIfEmptyEffect());
    while (!IsGameOver())
    {
        Advance();
    }
}
