//
// Created by sinat on 11/2/2024.
//

#ifndef SHAPEZOO_RECTANGLE_H
#define SHAPEZOO_RECTANGLE_H

#include "BaseShape.h"
#include <string>

class Rectangle : public BaseShape {
float m_width;
float m_height;
sf::RectangleShape m_rectangle;
public:
    Rectangle(std::string& text,sf::Vector2f position, sf::Vector2f speed, sf::Color color,float width, float height);
    void OnCollision(sf::RenderWindow &window) override;
    void Draw(sf::RenderWindow &window) override;
};
#endif //SHAPEZOO_RECTANGLE_H
