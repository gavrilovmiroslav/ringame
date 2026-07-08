//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_IGAMECONTEXT_H
#define RINGAME_IGAMECONTEXT_H

#include <memory>
#include <vector>

#include "../core/ringbuffer.h"
#include "../gameplay/ieffect.h"

class IPlayer;

class GameContext
{
public:
    GameContext(int playerCount);
    void AddPlayer(IPlayer* player);

    inline int GetPlayerCount() const
    {
        return m_PlayerCount;
    }

    inline bool IsGameOver() const
    {
        return m_IsGameOver;
    }

    inline void GameOver()
    {
        m_IsGameOver = true;
    }

    std::span<std::unique_ptr<IPlayer>> GetPlayers()
    {
        return std::span{m_Players};
    }

    inline int GetCurrentPlayerIndex() const
    {
        return m_CurrentPlayer;
    }

    inline std::unique_ptr<IPlayer>& GetCurrentPlayer()
    {
        return m_Players[m_CurrentPlayer];
    }

    inline void NextPlayer()
    {
        m_CurrentPlayer = (m_CurrentPlayer + 1) % m_PlayerCount;
    }

    inline void Print(std::string_view title)
    {
        std::cout << title << ":" << std::endl;
        m_State.Print();
    }

    inline void Back()
    {
        m_State.Back();
    }

    inline void Next()
    {
        m_State.Next();
    }

    inline void PushNext(IEffect* effect)
    {
        m_State.PushNext(effect);
    }

    inline void Push(IEffect* effect)
    {
        m_State.Push(effect);
    }

    inline void Consume()
    {
        m_State.Consume();
    }

    void Advance();
    void Round();
    void Run();

private:
    bool m_IsGameOver = false;
    int m_PlayerCount = 0;
    int m_CurrentPlayer = 0;
    std::vector<std::unique_ptr<IPlayer>> m_Players;
    RingBuffer<IEffect*> m_State;
};


#endif //RINGAME_IGAMECONTEXT_H
