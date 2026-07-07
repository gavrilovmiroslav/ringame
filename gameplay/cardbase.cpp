//
// Created by mika on 7/7/26.
//

#include "cardbase.h"
#include "gamecontext.h"
#include "effects/strengthupeffect.h"

CardBase::CardBase(int strength)
    : m_Owner{nullptr}
{
    this->m_Strength = strength;
}

CardBase::CardBase(IPlayer* owner, int strength)
    : m_Owner{owner}
{
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
    context->PushNext(new StrengthUpEffect(this));
}
