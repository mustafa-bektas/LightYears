#pragma once

#include <framework/Application.h>
#include <framework/Core.h>

namespace ly
{
    class Actor;
    class GameApplication : public Application
    {
        public:
            GameApplication();
            virtual void Tick(float deltaTime) override;
        private:
            float counter;
            std::weak_ptr<Actor> actorToDestroy;


    };
} // namespace ly
