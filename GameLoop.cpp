#include "GameLoop.h"

namespace GameLoop {

void loop() {
  std::cout << "Game Started" << std::endl;

  // // Variables for frame progression
  // int MS_PER_UPDATE = 10;

  // // SFML Window Initialization
  // sf::RenderWindow window(sf::VideoMode(1800, 1200), "GameWindow", sf::Style::Close);
  // window.setVerticalSyncEnabled(true);

  // // Variables for tracking time and delta time
  // Stopwatch<std::chrono::milliseconds> deltaClock;
  // double lag = 0.0;
  // double lagLeftOver = 1.0;

  // // Variables for tracking framerate
  // Stopwatch<std::chrono::milliseconds> framerateClock;
  // framerateClock.start();
  // int frameCount = 0;
  // int vpsCount = 0;

  // // Object for graphics manipulation
  // Graphics* graphics = new Graphics(&window);

  // // Create empty world to fill later
  // World world;

  // // View for zoom and camera
  // float zoomMultiplier = 2.0;
  // sf::View view = window.getDefaultView();
  // view.zoom(1 / zoomMultiplier);
  // window.setView(view);

  // // Main game loop
  // while(window.isOpen()) {
  //   sf::Event event;
  //   while(window.pollEvent(event)) {
  //     // Close requested
  //     if(event.type == sf::Event::Closed) {
  //       window.close();
  //     }
  //   }

  //   // Track framerate
  //   if(framerateClock.elapsed() >= 1000)
  //   {
  //     std::cout << "Entities: " << world.entities_.size() << std::endl;
  //     std::cout << "FPS: " << frameCount << std::endl;
  //     std::cout << "VPS: " << vpsCount << std::endl << std::endl;

  //     framerateClock.restart();
  //     frameCount = 0;
  //     vpsCount = 0;
  //     // std::cout << world.entities.size() << std::endl;
  //     if(world.entities_.size() > 0)
  //     {
  //       // std::cout << "(" << world.entities_[0].m_data->m_position.x << ", " << world.entities_[0].m_data->m_position.y << ")\n";
  //     }
  //   }


  // }
}

std::vector<GameObject> getTestLevel() {
  std::vector<GameObject> gameObjects;

  sf::Vector2f floorPos(150, 250);
  sf::Vector2f floorHitbox(700, 5);
  // GameObject object = GOFactory::createPlatform(floorPos, floorHitbox);
  gameObjects.emplace_back(GOFactory::createPlatform(floorPos, floorHitbox));


  return gameObjects;
}

}