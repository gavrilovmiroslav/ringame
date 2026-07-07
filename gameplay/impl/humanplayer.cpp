//
// Created by mika on 7/7/26.
//

#include <string>
#include <utility>

#include "humanplayer.h"

HumanPlayer::HumanPlayer(std::string name, std::vector<ICard*> deck)
{
    m_Name = std::move(name);

    for (ICard* card : deck)
    {
        // TODO: leaving warning for later
        card->SetOwner(this);
        this->m_Deck.push_back(std::move(card));
    }
}