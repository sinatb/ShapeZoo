#include <SFML/Graphics.hpp>
#include <memory>
#include "include/Triangle.h"
#include "include/Circle.h"
#include "include/Rectangle.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Shape Zoo");
    std::string text = "That's not the shape of my heart";
    std::vector<std::unique_ptr<BaseShape>> shapes;

    shapes.push_back(std::make_unique<Circle>(text,
                                              sf::Vector2f(200, 200),
                                              sf::Vector2f(0.05, 0.05),
                                              sf::Color::Red,
                                              80)
                                              );
    shapes.push_back(std::make_unique<Rectangle>(text,
                                                 sf::Vector2f(300, 300),
                                                 sf::Vector2f(0.05, 0.05),
                                                 sf::Color::Red, 200, 100)
                                                 );
    shapes.push_back(std::make_unique<Triangle>(text,
                                                sf::Vector2f(300, 200),
                                                sf::Vector2f(0.05, 0.05),
                                                sf::Color::Red,
                                                80)
                                                );

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Blue);
        for (const auto& s : shapes)
            s->Update(window);
        window.display();
    }
}
