#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace ly
{
    Application::Application()
        : m_Window(sf::VideoMode({1920u, 1080u}), "Light Years"),
        m_TargetFrameRate{60.f},
        m_TickClock{},
        currentWorld{nullptr}
    {
    }

    void Application::Run()
    {
        const float targetDeltaTime = 1.f / m_TargetFrameRate;
        float accumulatedTime = 0.f;

        while (m_Window.isOpen())
        {
            float frameDeltaTime = m_TickClock.restart().asSeconds();
            accumulatedTime += frameDeltaTime;
    
            // Handle all pending events
            while (const std::optional event = m_Window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    m_Window.close();
                }
            }
    
            // Fixed time step update
            while (accumulatedTime >= targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
            }
    
            // Render once per frame
            RenderInternal();

            //LOG("ticking at framerate: %f", 1.f / frameDeltaTime);
        }
    }
}

void ly::Application::TickInternal(float deltaTime)
{
    Tick(deltaTime);

    if (currentWorld)
    {
        currentWorld -> BeginPlayInternal();
        currentWorld -> TickInternal(deltaTime);
    }
}

void ly::Application::RenderInternal()
{
    m_Window.clear();

    Render();

    m_Window.display();
}

void ly::Application::Render()
{
    sf::RectangleShape rect{ sf :: Vector2f{100, 100} };
    rect.setFillColor(sf::Color::Green);
    m_Window.draw(rect);
}

void ly::Application::Tick(float deltaTime)
{
    
}