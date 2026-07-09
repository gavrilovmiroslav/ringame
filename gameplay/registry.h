//
// Created by mika on 7/8/26.
//

#ifndef RINGAME_REGISTRY_H
#define RINGAME_REGISTRY_H

#include <map>
#include <string>

#define UUID_SYSTEM_GENERATOR
#include "../core/uuid.h"

#include "../gameplay/card.h"

class Registry
{
    std::map<std::string, std::function<IEffect*()>> m_EffectFactories{};
    std::map<std::string, std::shared_ptr<CardTemplate>> m_CardTemplates{};
    std::map<uuids::uuid, std::shared_ptr<Card>> m_Cards{};

public:
    Registry() = default;

    void RegisterEffectFactory(std::string_view name, const std::function<IEffect*()>& factory);

    void RegisterCardTemplate(
        const std::string& name,
        int strength = 1,
        const std::string& effect = "",
        ECardResolutionBehavior resolution = ECardResolutionBehavior::Discard);

    void RegisterCard(std::shared_ptr<Card> card);
    IEffect* CreateEffect(const std::string& name, Card* owner = nullptr);
    std::shared_ptr<Card> Instantiate(const std::string& name, IPlayer* owner = nullptr);
};

#endif //RINGAME_REGISTRY_H
