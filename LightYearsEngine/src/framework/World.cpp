#include "framework/World.h"
#include "framework/Core.h"

namespace ly
{
    World::World(Application* owningApp)
        : m_OwningApp{owningApp},
        m_BeganPlay{false}
        {
        }

    void World::BeginPlayInternal()
    {
        if (!m_BeganPlay)
        {
            m_BeganPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
    }

    World::~World()
    {}

    void World::BeginPlay()
    {
        LOG("began play");
    }

    void World::Tick(float deltaTime)
    {
        LOG("ticking at fps: %f", 1.f / deltaTime);
    }
}
