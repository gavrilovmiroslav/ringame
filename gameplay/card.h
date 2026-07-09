//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_ICARD_H
#define RINGAME_ICARD_H

#include <memory>
#include <string>
#include <string_view>
#include "ecardresolutionbehavior.h"

#include "../core/random.h"

class IEffect;
class IPlayer;
class GameContext;
class Registry;

class Card
{
public:
    virtual ~Card();

    explicit Card(
        std::string name,
        int strength,
        IEffect* effect,
        ECardResolutionBehavior resolution = ECardResolutionBehavior::Discard);

    explicit Card(
            std::string name,
            IPlayer* owner,
            int strength,
            IEffect* effect,
            ECardResolutionBehavior resolution);

    int GetStrength() const
    {
        return m_Strength;
    }

    void SetStrength(int n)
    {
        m_Strength = n;
    }

    [[nodiscard]] ECardResolutionBehavior GetResolution() const
    {
        return m_Resolution;
    }

    [[nodiscard]] std::string_view GetName() const
    {
        return m_Name;
    }

    [[nodiscard]] uuids::uuid GetID() const
    {
        return m_Id;
    }

    virtual void Apply(GameContext* context);

    void SetOwner(IPlayer* owner)
    {
        this->m_Owner = owner;
    }

    IPlayer* GetOwner()
    {
        return m_Owner;
    }

protected:
    uuids::uuid m_Id;
    IPlayer* m_Owner;
    std::shared_ptr<IEffect> m_Effect;
    int m_Strength = 0;
    std::string m_Name;
    ECardResolutionBehavior m_Resolution = ECardResolutionBehavior::Discard;
};

struct CardTemplate : public Card
{
    ~CardTemplate() override = default;

    explicit CardTemplate(
        const std::string& name,
        const std::string& effectName,
        int strength,
        ECardResolutionBehavior resolution = ECardResolutionBehavior::Discard);

    std::shared_ptr<Card> Create(IPlayer* owner, Registry& registry);

    std::string m_EffectName;
};

#endif //RINGAME_ICARD_H
