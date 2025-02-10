#pragma once
#include <SFML/Graphics.hpp>
#include <cstdint>

namespace ly
{
    class World;
    class Application
    {
        public:
            Application(unsigned int windowWidth, unsigned int windowHeight,
                const std::string &title, std::uint32_t style); 
            void Run();

            template<typename WorldType>
            std::weak_ptr<WorldType> LoadWorld();
            
        private:
            void TickInternal(float deltaTime);
            void RenderInternal();
            virtual void Render();
            virtual void Tick(float deltaTime);

            sf::RenderWindow m_Window;
            float m_TargetFrameRate;
            sf::Clock m_TickClock;

            std::shared_ptr<World> currentWorld;
    };

    template <typename WorldType>
    std::weak_ptr<WorldType> Application::LoadWorld()
    {
        std::shared_ptr<WorldType> newWorld { new WorldType{this} };
        currentWorld = newWorld;
        return newWorld;
    }
}