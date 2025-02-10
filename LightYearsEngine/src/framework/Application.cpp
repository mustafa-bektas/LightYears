#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace ly
{
    Application::Application(unsigned int windowWidth, unsigned int windowHeight,
                const std::string &title, std::uint32_t style)
        : m_Window(sf::VideoMode({windowWidth, windowHeight}), title, style),
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
    if (currentWorld)
    {
        currentWorld -> Render(m_Window);
    }
}

void ly::Application::Tick(float deltaTime)
{
    
}