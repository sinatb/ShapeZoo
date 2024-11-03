#include <SFML/Graphics.hpp>
#include "include/Triangle.h"
#include "include/Circle.h"
#include "include/Rectangle.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Shape Zoo");
    std::string text = "Text";
    Rectangle r(text, sf::Vector2f(0, 0), sf::Vector2f(0.1, 0.1), sf::Color::Red, 30,30);
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Blue);
        r.Update(window);
        window.display();
    }
}
