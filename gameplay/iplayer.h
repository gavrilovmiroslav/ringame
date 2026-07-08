//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_IPLAYER_H
#define RINGAME_IPLAYER_H

#include <deque>
#include <string>

#include "icard.h"

class IPlayer
{
public:
    virtual ~IPlayer() {};

    std::deque<ICard*>& GetDeck()
    {
        return m_Deck;
    }

    std::deque<ICard*>& GetDiscard()
    {
        return m_Discard;
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

    void DiscardCard(ICard* card)
    {
        m_Discard.push_back(card);
    }

    [[nodiscard]] std::string_view GetName() const
    {
        return m_Name;
    }

protected:
    std::string m_Name;
    std::deque<ICard*> m_Deck;
    std::deque<ICard*> m_Discard;
    int m_TotalStrength = 0;
};


#endif //RINGAME_IPLAYER_H
