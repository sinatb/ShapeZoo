//
// Created by sinat on 11/3/2024.
//

#ifndef SHAPEZOO_TRIANGLE_H
#define SHAPEZOO_TRIANGLE_H
#include "BaseShape.h"
class Triangle : public BaseShape {
sf::CircleShape m_triangle;
float m_radius;
public:
    Triangle(std::string& text,sf::Vector2f position, sf::Vector2f speed, sf::Color color, float radius);
    void Draw(sf::RenderWindow &window) override;
    void OnCollision(sf::RenderWindow &window) override;
};
#endif //SHAPEZOO_TRIANGLE_H
