//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_IEFFECT_H
#define RINGAME_IEFFECT_H

class Card;
class GameContext;

class IEffect
{
public:
    IEffect() = default;

    IEffect(Card* owner)
        : m_Owner{owner}
    {}

    virtual ~IEffect() = default;

    void SetOwner(Card* card) { m_Owner = card; }
    Card* GetOwner() { return m_Owner; }
    virtual void Apply(GameContext* context) = 0;

    virtual std::string_view Name() { return "IEffect"; };

    bool IsConsumable() const
    {
        return m_Consumable;
    }
protected:
    bool m_Consumable = false;
    Card* m_Owner{nullptr};
};

#endif //RINGAME_IEFFECT_H
