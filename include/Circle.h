//
// Created by sinat on 11/3/2024.
//

#ifndef SHAPEZOO_CIRCLE_H
#define SHAPEZOO_CIRCLE_H

#include "BaseShape.h"

class Circle : public BaseShape {
sf::CircleShape m_circle;
float m_radius;
public:
    Circle(std::string& text,sf::Vector2f position, sf::Vector2f speed, sf::Color color, float radius);
    void Draw(sf::RenderWindow &window) override;
    void OnCollision(sf::RenderWindow &window) override;

};

#endif //SHAPEZOO_CIRCLE_H
