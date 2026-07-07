//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_ICARD_H
#define RINGAME_ICARD_H

#include <vector>
#include <sys/types.h>

class IPlayer;
class GameContext;

class ICard
{
public:
    virtual ~ICard() {};

    virtual IPlayer* GetOwner() = 0;
    virtual void SetOwner(IPlayer* owner) = 0;

    int GetStrength() const
    {
        return m_Strength;
    }

    void SetStrength(int n)
    {
        m_Strength = n;
    }

    virtual void Apply(GameContext* context) = 0;

protected:
    int m_Strength = 0;
};

#endif //RINGAME_ICARD_H
