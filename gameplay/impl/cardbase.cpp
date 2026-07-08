//
// Created by mika on 7/7/26.
//

#include "cardbase.h"
#include "../gamecontext.h"
#include "../effects/strengthupeffect.h"

CardBase::CardBase(std::string_view name, int strength, IEffect* effect)
    : ICard{name}
    , m_Owner{nullptr}
    , m_Effect{effect}
{
    if (effect != nullptr)
    {
        effect->SetOwner(this);
    }
    this->m_Strength = strength;
}

CardBase::CardBase(std::string_view name, IPlayer* owner, int strength, IEffect* effect)
    : ICard{name}
    , m_Owner{owner}
    , m_Effect{effect}
{
    if (effect != nullptr)
    {
        effect->SetOwner(this);
    }
    this->m_Strength = strength;
}

void CardBase::SetOwner(IPlayer* owner)
{
    this->m_Owner = owner;
}

IPlayer* CardBase::GetOwner()
{
    return m_Owner;
}

void CardBase::Apply(GameContext* context)
{
    if (this->m_Effect != nullptr)
    {
        context->PushNext(this->m_Effect);
    }
    context->PushNext(new StrengthUpEffect(this));
}
