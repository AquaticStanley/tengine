#include "GameLoop.h"

namespace GameLoop {

void loop() {
    std::cout << "Game Started" << std::endl;

    // Variables for frame progression
    int MS_PER_UPDATE = 10;

    // SFML Window Initialization
    sf::RenderWindow window(sf::VideoMode(1800, 1200), "GameWindow", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    // Variables for tracking time and delta time
    Stopwatch<std::chrono::milliseconds> deltaClock;
    double lag = 0.0;
    double lagLeftOver = 1.0;

    // Variables for tracking framerate
    Stopwatch<std::chrono::milliseconds> framerateClock;
    framerateClock.start();
    int frameCount = 0;
    int vpsCount = 0;

    // Object for graphics manipulation
    Graphics* graphics = new Graphics(&window);

    // Create empty world to fill later
    World world;

    // Spawn timer
    bool spawned = false;
    Stopwatch<std::chrono::milliseconds> spawnClock;
    spawnClock.start();

    // View for zoom and camera
    float zoomMultiplier = 2.0;
    sf::View view = window.getDefaultView();
    view.zoom(1 / zoomMultiplier);
    window.setView(view);

    // Main game loop
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            // Close requested
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Check if it's time to spawn initial objects
        if(!spawned && spawnClock.elapsed() >= 1000) {
          spawned = true;
          std::cout << "Spawned" << std::endl;
          std::vector<GameObject> gameObjects = getTestLevel();
          world.addEntities(gameObjects);
        }

        // Track framerate
        if(framerateClock.elapsed() >= 1000)
        {
            std::cout << "Entities: " << world.entities_.size() << std::endl;
            std::cout << "FPS: " << frameCount << std::endl;
            std::cout << "VPS: " << vpsCount << std::endl << std::endl;

            framerateClock.restart();
            frameCount = 0;
            vpsCount = 0;
            if(world.entities_.size() > 0)
            {
            std::cout << "(" << world.entities_[0].physics_->position_.x << ", " << world.entities_[0].physics_->position_.y << ")\n";
            }
        }

        frameCount++;

        // Get delta time
        lag += deltaClock.restart();

        world.processInput();

        while(lag >= MS_PER_UPDATE) {
            world.updatePhysics();
            vpsCount++;
            lag -= MS_PER_UPDATE;
        }

        window.clear(sf::Color::Black);

        world.render((lag/MS_PER_UPDATE) + (1.0 - lagLeftOver), *graphics);

        lagLeftOver = lag / MS_PER_UPDATE;
        if(spawned) {
            view.setCenter(sf::Vector2f(world.entities_[1].physics_->position_.x * 2.0, view.getSize().y * zoomMultiplier) - world.entities_[1].physics_->position_);
        }

        window.setView(view);
        window.display();
    }
}

std::vector<GameObject> getTestLevel() {
    std::vector<GameObject> gameObjects;

    // Create Player
    gameObjects.emplace_back(GOFactory::createPlayer(sf::Vector2f(300, 600)));

    // Create Camera
    gameObjects.emplace_back(GOFactory::createCamera(gameObjects[0].physics_));

    // Create Platforms
    gameObjects.emplace_back(GOFactory::createPlatform(sf::Vector2f(150, 250), sf::Vector2f(300, 4)));
    gameObjects.emplace_back(GOFactory::createPlatform(sf::Vector2f(300, 500), sf::Vector2f(100, 3)));
    gameObjects.emplace_back(GOFactory::createPlatform(sf::Vector2f(100, 200), sf::Vector2f(30, 600)));
    gameObjects.emplace_back(GOFactory::createPlatform(sf::Vector2f(-100, 200), sf::Vector2f(700, 5)));
    gameObjects.emplace_back(GOFactory::createPlatform(sf::Vector2f(600, 200), sf::Vector2f(400, 20)));
    gameObjects.emplace_back(GOFactory::createPlatform(sf::Vector2f(1100, 200), sf::Vector2f(400, 20)));

    return gameObjects;
}

}