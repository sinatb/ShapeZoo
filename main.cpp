#include <SFML/Graphics.hpp>
#include <memory>
#include "include/Triangle.h"
#include "include/Circle.h"
#include "include/Rectangle.h"
#include <fstream>
#include <sstream>
sf::Color ParseColor(std::string& color){
    if (color == "RED") {
        return sf::Color::Red;
    } else if (color == "GREEN") {
        return sf::Color::Green;
    } else if (color == "BLUE") {
        return sf::Color::Blue;
    }
    return sf::Color::Black;
}
int main() {
    //Config Values
    int window_width, window_height = 0;
    sf::Color bg_color;
    std::string window_name;
    std::vector<std::unique_ptr<BaseShape>> shapes;

    std::ifstream input_file(R"(D:\works\gameDev\COMP4300\ShapeZoo\test-files\test1.txt)");
    if (!input_file.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }
    std::string line;
    int line_number = 0;

    while (std::getline(input_file, line)){
        std::istringstream stream(line);
        std::string token;
        int token_counter = 0;
        while (stream >> token) {
            switch (line_number) {
                case 0:
                    if (token_counter == 0) {
                        window_width = std::stoi(token);
                        token_counter++;
                    } else if (token_counter == 1) {
                        window_height = std::stoi(token);
                        token_counter++;
                    }
                    break;
                case 1:
                    if (token_counter == 0) {
                       bg_color = ParseColor(token);
                    }
                    break;
                case 2:
                    window_name += token + " ";
                    break;
                default:
                    break;
            }
        }
        line_number ++;
    }
    input_file.close();

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), window_name);
    std::string text = "That's not the shape of my heart";

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

        window.clear(bg_color);
        for (const auto& s : shapes)
            s->Update(window);
        window.display();
    }
}
