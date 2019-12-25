#pragma once

#include <SFML/System.hpp>

class World;

class PhysicsComponent {
public:
    PhysicsComponent(const sf::Vector2f& position, const sf::Vector2f hitbox = sf::Vector2f(0, 0),  const sf::Vector2f& velocity = sf::Vector2f(0, 0), const sf::Vector2f& acceleration = sf::Vector2f(0, 0)) : 
                   position_(position), hitbox_(hitbox), velocity_(velocity), acceleration_(acceleration), canCollide_(true), id_(generateNewID()), toBeRemoved_(false) {}

    virtual ~PhysicsComponent() {}

    virtual void update(World& world) = 0;

    bool canCollide() const { return canCollide_; }
    int getID() const { return id_; }

public:
    sf::Vector2f position_;
    sf::Vector2f hitbox_;
    sf::Vector2f velocity_;
    sf::Vector2f acceleration_;

    bool canCollide_;
    int id_;
    bool toBeRemoved_;

private:
    int generateNewID() {
        static int i = 0;
        return ++i;
    }
};
