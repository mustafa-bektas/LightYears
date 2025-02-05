#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly {
    Actor::Actor(World *owningWorld)
        : m_OwningWorld{owningWorld},
        m_HasBeganPlay{false}
    {
    }

    Actor::~Actor()
    {
        LOG("actor destroyed");
    }

    void Actor::BeginPlayInternal()
    {
        if (!m_HasBeganPlay)
        {
            m_HasBeganPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay()
    {
        LOG("Actor begin play");
    }

    void Actor::Tick(float deltaTime)
    {
        LOG("Actor ticking");
    }
}
