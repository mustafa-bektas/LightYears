#pragma once
#include "framework/Object.h"
#include "framework/Core.h"
#include <SFML/Graphics.hpp>

namespace ly
{
    class World;
    class Actor : public Object
    {
        public:
            Actor(World* owningWorld);
            virtual ~Actor();

            void BeginPlayInternal();
            virtual void BeginPlay();
            void TickInternal(float deltaTime);
            virtual void Tick(float deltaTime);
            void SetTexture(const std::string& texturePath);
            void Render(sf::RenderWindow& window);

        private:
            World* m_OwningWorld;
            bool m_HasBeganPlay;

            sf::Sprite m_Sprite;
            sf::Texture m_Texture;
    };
} // namespace ly
