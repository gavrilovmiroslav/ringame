//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_IPLAYER_H
#define RINGAME_IPLAYER_H

#include "icard.h"

// deque >>>>>> vector, but i forget
#include <deque>

class IPlayer
{
public:
    virtual ~IPlayer() {};

    std::deque<ICard*>& GetDeck()
    {
        return m_Deck;
    }

    int GetTotalStrength() const
    {
        return m_TotalStrength;
    }

    void TotalStrengthAdd(int n)
    {
        m_TotalStrength += n;
    }

    ICard* DrawCard()
    {
        if (m_Deck.empty())
        {
            return nullptr;
        }

        ICard* card = m_Deck.front();
        m_Deck.pop_front();
        return card;
    }

    std::string_view GetName() const
    {
        return m_Name;
    }

protected:
    std::string m_Name;
    std::deque<ICard*> m_Deck;
    int m_TotalStrength = 0;
};


#endif //RINGAME_IPLAYER_H
