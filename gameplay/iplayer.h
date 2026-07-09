//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_IPLAYER_H
#define RINGAME_IPLAYER_H

#include <algorithm>
#include <deque>
#include <random>
#include <string>

#include "card.h"

class IPlayer
{
public:
    virtual ~IPlayer() = default;

    void ResetStrength()
    {
        m_TotalStrength = 0;
    }

    std::deque<std::shared_ptr<Card>>& GetDeck()
    {
        return m_Deck;
    }

    std::deque<std::shared_ptr<Card>>& GetDiscard()
    {
        return m_Discard;
    }

    int GetVictoryPoints() const
    {
        return m_VictoryPoints;
    }

    void GainVictoryPoint()
    {
        m_VictoryPoints++;
    }

    int GetTotalStrength() const
    {
        return m_TotalStrength;
    }

    void TotalStrengthAdd(int n)
    {
        m_TotalStrength += n;
    }

    std::shared_ptr<Card> DrawCard()
    {
        if (m_Deck.empty())
        {
            return nullptr;
        }

        auto card = m_Deck.front();
        m_Deck.pop_front();
        return card;
    }

    void DiscardCard(const std::shared_ptr<Card>& card)
    {
        m_Discard.push_back(card);
    }

    void ShuffleDeck()
    {
        std::shuffle(GetDeck().begin(), GetDeck().end(), std::mt19937(std::random_device()()));
    }

    void ShuffleDiscardIntoDeck()
    {
        while (!GetDiscard().empty())
        {
            auto card = GetDiscard().back();
            GetDiscard().pop_back();
            GetDeck().push_back(card);
        }
        ShuffleDeck();
    }

    [[nodiscard]] std::string_view GetName() const
    {
        return m_Name;
    }

    std::vector<std::string>& GetDecklist()
    {
        return m_Decklist;
    }

protected:
    std::vector<std::string> m_Decklist;
    std::string m_Name;
    std::deque<std::shared_ptr<Card>> m_Deck;
    std::deque<std::shared_ptr<Card>> m_Discard;
    int m_TotalStrength = 0;
    int m_VictoryPoints = 0;
};


#endif //RINGAME_IPLAYER_H
