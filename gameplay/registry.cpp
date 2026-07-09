//
// Created by mika on 7/8/26.
//

#include "registry.h"

#include <map>
#include <cassert>
#include <memory>

#include "ieffect.h"

IEffect* Registry::CreateEffect(const std::string& name, Card* owner)
{
    auto result = m_EffectFactories.find(name);
    if (result != m_EffectFactories.end())
    {
        auto* eff = m_EffectFactories[name]();
        eff->SetOwner(owner);
        return eff;
    }
    else
    {
        return nullptr;
    }
}

void Registry::RegisterCardTemplate(const std::string& name, int strength, const std::string& effect, ECardResolutionBehavior resolution)
{
    auto temp = std::make_shared<CardTemplate>(name, effect, strength, resolution);
    assert(temp != nullptr);
    m_CardTemplates.emplace(name, temp);
    assert(!m_CardTemplates.empty());
}

std::shared_ptr<Card> Registry::Instantiate(const std::string& name, IPlayer* owner)
{
    assert(!m_CardTemplates.empty());
    const auto result = m_CardTemplates.find(name);
    if (result != m_CardTemplates.end())
    {
        auto card = result->second->Create(owner, *this);
        assert(card != nullptr);
        return card;
    }

    return nullptr;
}

void Registry::RegisterCard(std::shared_ptr<Card> card)
{
    m_Cards.emplace(card->GetID(), card);
}

void Registry::RegisterEffectFactory(std::string_view name, const std::function<IEffect *()> &factory)
{
    m_EffectFactories.emplace(std::string{name}, factory);
}
