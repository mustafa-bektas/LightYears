#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly {
    Actor::Actor(World *owningWorld)
        : m_OwningWorld{owningWorld},
        m_HasBeganPlay{false},
        m_Texture{},
        m_Sprite{m_Texture}
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

    void Actor::SetTexture(const std::string &texturePath)
    {
        if (!m_Texture.loadFromFile(texturePath))
        {
            LOG("Failed to load texture");
        }

        int textureWidth = m_Texture.getSize().x;
        int textureHeight = m_Texture.getSize().y;

        m_Sprite.setTexture(m_Texture);
        m_Sprite.setTextureRect(sf::IntRect{ sf::Vector2i{0, 0}, sf::Vector2i{textureWidth, textureHeight} });
    }
}
