//
// Created by mika on 7/7/26.
//

#include <string>
#include <utility>

#include "humanplayer.h"
#include <initializer_list>

HumanPlayer::HumanPlayer(std::string name, std::initializer_list<std::string>&& deck)
{
    m_Name = std::move(name);

    for (auto&& card : deck)
    {
        m_Decklist.push_back(card);
    }
}