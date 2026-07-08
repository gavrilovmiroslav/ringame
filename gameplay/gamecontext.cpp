//
// Created by mika on 7/7/26.
//

#include <print>

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

void GameContext::Round()
{
    m_State.Push(new PerformPlayerTurnEffect());
    m_State.Push(new PerformPlayerTurnEffect());
    m_State.Push(new GameOverIfEmptyEffect());

    while (!IsGameOver())
    {
        Advance();
    }
}

void GameContext::PrintState()
{
    std::print("    {:20}{:20}{:20}{:20}\n", "Player Name", "Total Strength", "Deck Size", "VICTORY POINTS");
    for (auto& player : m_Players)
    {
        std::print("    {:20}{:14}{:15}{:15}\n",
            player->GetName(), player->GetTotalStrength(),
            player->GetDeck().size(), player->GetVictoryPoints());
    }
}

void GameContext::UpdateVictoryPoints()
{
    int max = 0;
    for (auto& player : m_Players)
    {
        if (player->GetTotalStrength() > max)
        {
            max = player->GetTotalStrength();
        }
    }

    for (auto& player : m_Players)
    {
        if (player->GetTotalStrength() == max)
        {
            player->GainVictoryPoint();
        }
    }
}

void GameContext::Run()
{
    std::cout << "\n --- RINGAME IS ON! -----------------------------------------------------------------" << std::endl;
    PrintState();
    std::cout << " -------------------------------------------------------------------------------------\n\n" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        m_State.Clear();
        std::cout << "\n================== ROUND " << (i + 1) << " / 3 ======================" << std::endl;
        for (auto& player : m_Players)
        {
            player->ShuffleDeck();
        }
        Round();

        UpdateVictoryPoints();

        m_IsGameOver = false;
        for (auto& player : m_Players)
        {
            player->ShuffleDiscardIntoDeck();
        }

        std::cout << "\n --- ROUND " << (i + 1) << " ENDED! -----------------------------------------------------------------" << std::endl;
        PrintState();
        std::cout << " -------------------------------------------------------------------------------------\n" << std::endl;

        for (auto& player : m_Players)
        {
            player->ResetStrength();
        }
    }
}
