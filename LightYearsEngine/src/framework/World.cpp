#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{
    World::World(Application* owningApp)
        : m_OwningApp{owningApp},
        m_BeganPlay{false},
        m_Actors{},
        m_PendingActors{}
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
        for (std::shared_ptr<Actor> actor : m_PendingActors)
        {
            m_Actors.push_back(actor);
            actor->BeginPlayInternal();
        }

        m_PendingActors.clear();

        /* for (std::shared_ptr<Actor> actor : m_Actors)
        {
            actor->Tick(deltaTime);
        } */

       for (auto iter = m_Actors.begin(); iter != m_Actors.end();)
       {
            if (iter->get()->IsPendingDestroy())
            {
                iter = m_Actors.erase(iter);
            }
            else
            {
                iter->get()->TickInternal(deltaTime);
                ++iter;
            }
       }

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

    void World::Render(sf::RenderWindow& window)
    {
        for (std::shared_ptr<Actor> actor : m_Actors)
        {
            actor->Render(window);
        }
    }
}
