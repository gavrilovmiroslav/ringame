//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_CARDBASE_H
#define RINGAME_CARDBASE_H

#include "icard.h"

class CardBase : public ICard
{
public:
    CardBase(int strength);
    CardBase(IPlayer* owner, int strength);
    ~CardBase() override = default;

    IPlayer* GetOwner() override;
    void SetOwner(IPlayer* owner) override;
    void Apply(GameContext* context) override;

private:
    IPlayer* m_Owner;
};

#endif //RINGAME_CARDBASE_H
