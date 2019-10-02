#pragma once

#include <SFML/System.hpp>

class World;

class PhysicsComponent {
public:
    PhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox = sf::Vector2f(0, 0),  const sf::Vector2f& velocity = sf::Vector2f(0, 0), const sf::Vector2f& acceleration = sf::Vector2f(0, 0)) : 
                   position_(position), hitbox_(hitbox), velocity_(velocity), acceleration_(acceleration), id_(generateNewID()), toBeRemoved_(false) {}

    virtual ~PhysicsComponent() {}

    virtual void update(World& world) = 0;

    int getID() { return id_; }

public:
    sf::Vector2f position_;
    sf::Vector2f hitbox_;
    sf::Vector2f velocity_;
    sf::Vector2f acceleration_;

    int id_;
    bool toBeRemoved_;

private:
    int generateNewID() {
        static int i = 0;
        return ++i;
    }
};
