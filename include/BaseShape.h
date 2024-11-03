//
// Created by sinat on 11/2/2024.
//

#ifndef SHAPEZOO_BASESHAPE_H
#define SHAPEZOO_BASESHAPE_H

#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
#include <random>
class BaseShape {

void Move();

static sf::Vector2f getRandomDirection();

protected:
    std::string  m_text;
    sf::Vector2f m_position;
    sf::Vector2f m_speed;
    sf::Color    m_color;
    sf::Vector2f m_direction;
    sf::Shape&   m_shape;

public:
    BaseShape(std::string& text, sf::Vector2f& position, sf::Vector2f& speed, sf::Color& color, sf::Shape& shape);
    virtual void OnCollision(sf::RenderWindow &window) = 0;
    virtual void Draw(sf::RenderWindow &window) = 0;
    void Update(sf::RenderWindow &window);
    ~BaseShape() = default;
};
#endif //SHAPEZOO_BASESHAPE_H
