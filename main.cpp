#include <SFML/Graphics.hpp>
#include <memory>
#include "include/TextParser.h"
int main() {
    std::string filename = "test1.txt";
    TextParser parser(filename);

    //Config Values
    int window_width = parser.getWidth(), window_height = parser.getHeight();
    sf::Color bg_color = parser.getBgColor();
    std::string window_name = parser.getWindowName();
    std::vector<std::unique_ptr<BaseShape>> shapes = parser.getShapes();
    //

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), window_name);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(bg_color);
        for (const auto& s : shapes)
            s->Update(window);
        window.display();
    }
}
