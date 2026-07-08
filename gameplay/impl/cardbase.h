//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_CARDBASE_H
#define RINGAME_CARDBASE_H

#include "../icard.h"

class IEffect;

class CardBase : public ICard
{
public:
    CardBase(std::string_view name, int strength, IEffect* effect = nullptr);
    CardBase(std::string_view name, IPlayer* owner, int strength, IEffect* effect = nullptr);
    ~CardBase() override = default;

    IPlayer* GetOwner() override;
    void SetOwner(IPlayer* owner) override;
    void Apply(GameContext* context) override;

private:
    IPlayer* m_Owner;
    IEffect* m_Effect;
};

#endif //RINGAME_CARDBASE_H
