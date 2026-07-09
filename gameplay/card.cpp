//
// Created by mika on 7/8/26.
//

#include "card.h"

#include <utility>
#include "gamecontext.h"
#include "effects/strengthupeffect.h"
#include "registry.h"

Card::~Card() = default;

Card::Card(std::string name, int strength, IEffect* effect, ECardResolutionBehavior resolution)
    : m_Name{std::move(name)}
    , m_Owner{nullptr}
    , m_Strength{strength}
    , m_Effect{effect}
    , m_Resolution{resolution}
    , m_Id{id()}
{
    if (m_Effect != nullptr)
    {
        m_Effect->SetOwner(this);
    }
}

Card::Card(std::string name, IPlayer *owner, int strength, IEffect* effect, ECardResolutionBehavior resolution)
    : m_Name{std::move(name)}
    , m_Owner{owner}
    , m_Strength{strength}
    , m_Effect{effect}
    , m_Resolution{resolution}
    , m_Id{id()}
{
    if (m_Effect != nullptr)
    {
        m_Effect->SetOwner(this);
    }
}

void Card::Apply(GameContext *context)
{
    if (this->m_Effect != nullptr)
    {
        context->PushNext(this->m_Effect.get());
    }

    context->PushNext(new StrengthUpEffect(this));
}

CardTemplate::CardTemplate(const std::string& name, const std::string& effectName, int strength, ECardResolutionBehavior resolution)
    : Card{name, nullptr, strength, nullptr, resolution}
    , m_EffectName{effectName}
{}

std::shared_ptr<Card> CardTemplate::Create(IPlayer *owner, Registry &registry)
{
    IEffect* eff = nullptr;
    if (!m_EffectName.empty())
    {
        eff = registry.CreateEffect(m_EffectName);
    }

    auto card = std::make_shared<Card>(m_Name, owner, m_Strength, eff, m_Resolution);
    registry.RegisterCard(card);
    return card;
}