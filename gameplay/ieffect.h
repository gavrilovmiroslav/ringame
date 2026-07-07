//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_IEFFECT_H
#define RINGAME_IEFFECT_H

class ICard;
class GameContext;

class IEffect
{
public:
    IEffect() = default;

    IEffect(ICard* owner)
        : m_Owner{owner}
    {}

    virtual ~IEffect() = default;

    ICard* GetOwner() { return m_Owner; }
    virtual void Apply(GameContext* context) = 0;

    virtual std::string_view Name() { return "IEffect"; };

    bool IsConsumable() const
    {
        return m_Consumable;
    }
protected:
    bool m_Consumable = false;
    ICard* m_Owner{nullptr};
};

#endif //RINGAME_IEFFECT_H
