#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>



int main() {
  sf::VideoMode video({800, 600});
  sf::RenderWindow window(video, "SFML Window");
  sf::Clock clock;

  sf::Shader shad;
  if (!shad.loadFromFile("shad1.vert", "shad1.frag")) {
    std::cerr << "Error loading vertex shader" << std::endl;
    return -1;
  }

  sf::RectangleShape rect(sf::Vector2f(800 / 4., 600 / 4.));
  rect.setFillColor(sf::Color::Red);
  const float rectWidth = 800 / 4.0f;
  const float rectHeight = 600 / 4.0f;
  const float rectOriginX = rectWidth / 2.0f;
  const float rectOriginY = rectHeight / 2.0f;

  rect.setPosition(sf::Vector2f(800 / 2.0f, 600 / 2.0f));
  rect.setOrigin(sf::Vector2f(rectOriginX, rectOriginY));


  // shad.setUniform("transform", rect.getTransform().getMatrix());

  // rotation
  float rotationSpeed = 20.0f; // degrees per second

  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    while (const std::optional event = window.pollEvent()) {
      // "close requested" event: we close the window
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    // draw everything here...
    // Update rotation
    float deltaTime = clock.restart().asSeconds();
    sf::Angle rotAngle = sf::degrees(rotationSpeed * deltaTime);
    rect.rotate(rotAngle);

    // shad.setUniform("position", sf::Glsl::Vec4(rect.getPosition().x, rect.getPosition().y, 0.0f, 1.0f));
    // shad.setUniform("transform", sf::Glsl::Mat4(rect.getTransform().getMatrix()));
    shad.setUniform("time", clock.getElapsedTime().asSeconds());

    // Clear the window
    window.clear(sf::Color::Black);

    // Draw the rectangle

    window.draw(rect, &shad);
    // end the current frame
    window.display();
  }

  return 0;
}
