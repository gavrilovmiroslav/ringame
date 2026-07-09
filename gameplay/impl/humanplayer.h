//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_HUMANPLAYER_H
#define RINGAME_HUMANPLAYER_H

#include "../iplayer.h"

class HumanPlayer : public IPlayer
{
public:
    HumanPlayer(std::string name, std::initializer_list<std::string>&& deck);
    ~HumanPlayer() override = default;
};


#endif //RINGAME_HUMANPLAYER_H
