#include "framework/Application.h"
#include <iostream>

namespace ly
{
    Application::Application()
        : m_Window(sf::VideoMode({1920u, 1080u}), "Light Years"),
        m_TargetFrameRate{60.f},
        m_TickClock{}
    {
    }

    void Application::Run()
    {
        while (m_Window.isOpen())
        {
            m_TickClock.restart();
            float accumulatedTime = 0.f;
            float targetDeltaTime = 1.f / m_TargetFrameRate;

            while (const std::optional event = m_Window.pollEvent())
            {
                if (event -> is<sf::Event::Closed>())
                {
                    m_Window.close();
                }
            }

            float frameDeltaTime = m_TickClock.restart().asSeconds();
            accumulatedTime += frameDeltaTime;
            while (accumulatedTime > targetDeltaTime)
            {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
    }
}

void ly::Application::TickInternal(float deltaTime)
{
    Tick(deltaTime);
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
    std::cout << "ticking at framerate: " << 1.f / deltaTime << std::endl;
}