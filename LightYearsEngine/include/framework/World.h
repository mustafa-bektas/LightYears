#pragma once
#include "framework/Core.h"
#include <vector>
#include <memory>

namespace ly
{
    class Actor;
    class Application;
    class World
    {
        public:
            World(Application* owningApp);

            void BeginPlayInternal();
            void TickInternal(float deltaTime);

            virtual ~World();

            template<typename ActorType>
            std::weak_ptr<ActorType> SpawnActor();

        private: 
            void BeginPlay();
            void Tick(float deltaTime);
            Application* m_OwningApp;
            bool m_BeganPlay;

            std::vector<std::shared_ptr<Actor>> m_Actors;
            std::vector<std::shared_ptr<Actor>> m_PendingActors;
    };

    template <typename ActorType>
    std::weak_ptr<ActorType> World::SpawnActor()
    {
        std::shared_ptr<ActorType> newActor{ new ActorType{this} };
        m_PendingActors.push_back(newActor);
        return newActor;           
    }
}
